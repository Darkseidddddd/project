import tensorflow as tf
import numpy as np
from prepare_data import load_data
from sklearn.model_selection import train_test_split

def weight_xavier_init(shape, input_num, output_num, activationfunc='relu', uniform=True, variable_name=None):
    if activationfunc == 'sigmoid':
        if uniform:
            init_range = tf.sqrt(6.0 / (input_num + output_num))
            initial = tf.random_uniform(shape, -init_range, init_range)
            return tf.Variable(initial, name=variable_name)
        else:
            stddev = tf.sqrt(2.0 / (input_num + output_num))
            initial = tf.truncated_normal(shape, mean=0.0, stddev=stddev)
            return tf.Variable(initial, name=variable_name)
    elif activationfunc == 'relu':
        if uniform:
            init_range = tf.sqrt(6.0 / (input_num + output_num)) * np.sqrt(2)
            initial = tf.random_uniform(shape, -init_range, init_range)
            return tf.Variable(initial, name=variable_name)
        else:
            stddev = tf.sqrt(2.0 / (input_num + output_num)) * np.sqrt(2)
            initial = tf.truncated_normal(shape, mean=0.0, stddev=stddev)
            return tf.Variable(initial, name=variable_name)
    elif activationfunc == 'tan':
        if uniform:
            init_range = tf.sqrt(6.0 / (input_num + output_num)) * 4
            initial = tf.random_uniform(shape, -init_range, init_range)
            return tf.Variable(initial, name=variable_name)
        else:
            stddev = tf.sqrt(2.0 / (input_num + output_num)) * 4
            initial = tf.truncated_normal(shape, mean=0.0, stddev=stddev)
            return tf.Variable(initial, name=variable_name)

def bias_variable(shape, variable_name=None):
    initial = tf.constant(0.1, shape=shape)
    return tf.Variable(initial, name=variable_name)

def conv2d(x, W, strides=1):
    conv_2d = tf.nn.conv2d(x, W, strides=[1, strides, strides, 1], padding='SAME')
    return conv_2d

def max_pool_2x2(x, inception=False):
    if inception:
        pool2d = tf.nn.max_pool(x, ksize=[1, 3, 3, 1], strides=[1, 1, 1, 1], padding='SAME')
    else:
        pool2d = tf.nn.max_pool(x, ksize=[1, 2, 2, 1], strides=[1, 2, 2, 1], padding='SAME')

    return pool2d

def conv_bn_relu(x, kernelshape, scope=None):
    with tf.name_scope(scope):
        W = weight_xavier_init(shape=kernelshape, input_num=kernelshape[0] * kernelshape[1] * kernelshape[2], 
                                output_num=kernelshape[-1], activationfunc='relu', variable_name=scope + 'W')
        B = bias_variable([kernelshape[-1]], variable_name=scope + 'B')
        conv = conv2d(x, W) + B
        conv = tf.nn.relu(conv)
        return conv

def fullyconnected_relu_layer(x, shape, active=True, scope=None):
    with tf.name_scope(scope):
        W = weight_xavier_init(shape=shape, input_num=shape[0] * shape[1],
                                output_num=shape[-1], activationfunc='relu', variable_name=scope + 'W')
        B = bias_variable([shape[-1]], variable_name=scope + 'B')
        conv = tf.matmul(x, W) + B
        if active:
            conv = tf.nn.relu(conv)
        return conv

def myNet(X, image_width, image_height, image_channel, n_class=30):
    inputX = tf.reshape(X,[-1, image_width, image_height, image_channel])
    # layer1
    layer1 = conv_bn_relu(inputX, kernelshape=[3, 3, image_channel, 32], scope='layer1')
    layer1 = conv_bn_relu(layer1, kernelshape=[3, 3, 32, 32], scope='layer1_1')
    pool1 = max_pool_2x2(layer1)
    # layer2
    layer2 = conv_bn_relu(pool1, kernelshape=[3, 3, 32, 64], scope='layer2')
    layer2 = conv_bn_relu(layer2, kernelshape=[3, 3, 64, 64], scope='layer2_1')
    pool2 = max_pool_2x2(layer2)

    # layer3
    layer3 = conv_bn_relu(pool2, kernelshape=[3, 3, 64, 128], scope='layer3')
    layer3 = conv_bn_relu(layer3, kernelshape=[3, 3, 128, 128], scope='layer3_1')
    pool3 = max_pool_2x2(layer3)
    
    # layer4
    # layer4 = conv_bn_relu(pool3, kernelshape=[3, 3, 128, 256], scope='layer4')
    # layer4 = conv_bn_relu(layer4, kernelshape=[3, 3, 256, 256], scope='layer4_1')
    # pool4 = max_pool_2x2(layer4)

    gap = tf.reduce_mean(pool3, axis=(1,2))
    gap = tf.reshape(gap, shape=[-1,128])
    fc1 = fullyconnected_relu_layer(gap, shape=[128, 256], scope='fc1')
    fc2 = fullyconnected_relu_layer(fc1, shape=[256, 512], scope='fc2')
    fc3 = fullyconnected_relu_layer(fc2, shape=[512, n_class], active=False, scope='fc3')
    
    return fc3

def test(batch_size=6):
    model_file=tf.train.latest_checkpoint('model1/')
    # model_file = 'model'
    image_size = 96*96
    image_width = image_height = 96
    image_labels = 30

    x, y = load_data()
    train_images, test_images, train_labels, test_labels = train_test_split(x, y, test_size=0.3,random_state=0)
    
    X = tf.placeholder('float', shape=[None, image_width, image_height, 1])
    y = tf.placeholder('float', shape=[None, image_labels])
    y_pred = myNet(X=X, image_width=image_width, image_height=image_height, image_channel=1, n_class=30)
    # cost function
    cost = tf.sqrt(tf.reduce_mean(tf.square(y_pred-y)))
    init = tf.initialize_all_variables()
    saver = tf.train.Saver()
    sess = tf.InteractiveSession() 
    sess.run(init)
    saver.restore(sess, model_file)
    # 计算训练集与测试集的loss
    cost_ = tf.square(y_pred-y)
    loss = 0.0
    test_nums = test_images.shape[0]
    for i in range(0, test_nums, batch_size):
        loss_ = cost_.eval(feed_dict={X: test_images[i:i+batch_size], y: test_labels[i:i+batch_size]})
        loss += np.sum(loss_)
    test_cost_epoch = np.sqrt(loss/(test_nums*image_labels))
    print('test loss: %.6f' %test_cost_epoch)

if __name__ == '__main__':
    test(batch_size=6)
