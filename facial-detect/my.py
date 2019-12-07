import tensorflow as tf
import numpy as np
from prepare_data import load_data
from sklearn.model_selection import train_test_split
import os
os.environ["CUDA_VISIBLE_DEVICES"] = "0,1"

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
    layer4 = conv_bn_relu(pool3, kernelshape=[3, 3, 128, 256], scope='layer4')
    layer4 = conv_bn_relu(layer4, kernelshape=[3, 3, 256, 256], scope='layer4_1')
    pool4 = max_pool_2x2(layer4)

    gap = tf.reduce_mean(pool4, axis=(1,2))
    gap = tf.reshape(gap, shape=[-1,256])
    fc1 = fullyconnected_relu_layer(gap, shape=[256, 512], scope='fc1')
    fc2 = fullyconnected_relu_layer(fc1, shape=[512, 1000], scope='fc2')
    fc3 = fullyconnected_relu_layer(fc2, shape=[1000, n_class], active=False, scope='fc3')
    
    return fc3

def val(y_pred, train_images, train_labels, batch_size):
    
    n = train_images.shape[0]
    X = tf.placeholder('float', shape=[None, image_width, image_height, 1])
    y = tf.placeholder('float', shape=[None, image_labels])
    y_pred = myNet(X=X, image_width=image_width, image_height=image_height, image_channel=1, n_class=30)
    
    cost = tf.square(y_pred-y)
    loss = 0
    for i in range(0, n, batch_size):
        loss1 = cost.eval(feed_dict={X: train_images[i:i+batch_size], y: train_labels[i:i+batch_size]})
        loss += loss1
    return tf.sqrt(loss/n)

def train(epochs=1000, batch_size=6, lr=0.01):
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
    # train_op
    train_op = tf.train.AdamOptimizer(lr).minimize(cost)
    '''
    TensorFlow Session
    '''
    features_placeholder = tf.placeholder(train_images.dtype, train_images.shape)
    labels_placeholder = tf.placeholder(train_labels.dtype, train_labels.shape)

    dataset = tf.data.Dataset.from_tensor_slices((features_placeholder, labels_placeholder))
    dataset = dataset.shuffle(20).batch(batch_size).repeat()

    iterator = dataset.make_initializable_iterator()
    data_element = iterator.get_next()

    init = tf.initialize_all_variables()
    saver = tf.train.Saver(tf.all_variables(),max_to_keep=2)
    # 画图
    tf.summary.scalar('loss', cost)
    merged_summary_op = tf.summary.merge_all()
    summary_writer = tf.summary.FileWriter('log', graph=tf.get_default_graph())
    
    sess = tf.InteractiveSession()
    sess.run(init)
    sess.run(iterator.initializer, feed_dict={features_placeholder: train_images, labels_placeholder: train_labels})

    num_examples = train_images.shape[0]
    print('start training')
    best_loss = 100.0
    k = 0
    for e in range(epochs):
        for i in range(0, num_examples, batch_size):
            X_batch, y_batch = sess.run(data_element)
            _, summary = sess.run([train_op, merged_summary_op], feed_dict={X: X_batch, y: y_batch})
            summary_writer.add_summary(summary, k)
            k += 1    
        
        # 计算训练集与测试集的loss
        cost_ = tf.square(y_pred-y)
        loss = 0.0
        train_nums = train_images.shape[0]
        test_nums = test_images.shape[0]
        for i in range(0, train_nums, batch_size):
            loss_ = cost_.eval(feed_dict={X: train_images[i:i+batch_size], y: train_labels[i:i+batch_size]})
            loss += np.sum(loss_)
        train_cost_epoch = np.sqrt(loss/(train_nums*image_labels))
        loss = 0.0
        for i in range(0, test_nums, batch_size):
            loss_ = cost_.eval(feed_dict={X: test_images[i:i+batch_size], y: test_labels[i:i+batch_size]})
            loss += np.sum(loss_)
        test_cost_epoch = np.sqrt(loss/(test_nums*image_labels))
        
        # train_cost_epoch = cost.eval(feed_dict={X: train_images, y: train_labels})
        # test_cost_epoch = cost.eval(feed_dict={X: test_images, y: test_labels})
        if best_loss > test_cost_epoch:
            best_loss = test_cost_epoch
            saver.save(sess, 'model/my-model', global_step=e)
            print('-------------best loss: %.6f------------' %best_loss)
        print('epoch %d, train_loss: %.6f, test loss: %.6f' %(e, train_cost_epoch, test_cost_epoch))

    save_path = saver.save(sess, 'model/my-model')
    print('best loss: %.6f' %best_loss)
    # print('Model saved in file:', save_path)
    sess.close()

if __name__ == '__main__':
    train(epochs=700, batch_size=6, lr=0.0001)
