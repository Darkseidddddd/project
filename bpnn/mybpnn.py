import random
import numpy as np
import pickle
from sklearn.model_selection import train_test_split

def to_one_hot(data, class_num):
    labels = np.zeros((data.shape[0],class_num))
    for i,c in enumerate(data[:,-1]):
        labels[i][int(c)] = 1
    return labels

def load_data():
    data_train = np.loadtxt('train.csv', delimiter=',')
    data_test = np.loadtxt('test.csv', delimiter=',')
    labels_train = to_one_hot(data_train, 3)
    labels_test = to_one_hot(data_test, 3)
    return data_train[:,:-1], labels_train, data_test[:,:-1], labels_test

def loadtxt():
    data = np.loadtxt('thyroid.txt', delimiter=',')
    data[:,-1] = data[:,-1] - 1
    data[:,:-1] = normalization(data[:,:-1])
    X_train,X_test,y_train,y_test = train_test_split(data[:,:-1],data[:,-1],test_size=0.85)
    return X_train, to_one_hot(y_train.reshape(-1,1),3), X_test, to_one_hot(y_test.reshape(-1,1),3)

    # sigmoid function
def _sigmoid(x):
    return 1 / (1 + np.exp(-x))
    # return np.exp(x) / (1 + np.exp(x))

# derivative of sigmoid function
def _dsigmoid(x):
    return _sigmoid(x) * (1 - _sigmoid(x))

def _relu(x):
    return np.maximum(x,0)

def _drelu(x):
    x_ = x.copy()
    x_[x_>0] = 1
    x_[x_<=0] = 0
    return x_

# shape: 1 * output_num
def _softmax(x):
    # print(x)
    temp = np.exp(x) / np.sum(np.exp(x),axis=1).reshape(-1,1)
    return temp

def to_dense(one_hot_label):
    dense = np.argmax(one_hot_label,axis=1).reshape(1,-1)
    return dense

def normalization(x):
    x = (x-np.min(x,axis=0))/(np.max(x,axis=0)-np.min(x,axis=0))
    return x

    # 传入概率矩阵
def calculate_acc(y, label):
    y_ = np.argmax(y,axis=1).reshape(1,-1)
    labels = to_dense(label)
    predictions = (y_ == labels)
    # print(predictions)
    return np.sum(predictions == True) / len(y)

def shuffle_data(x,y):
    temp = np.hstack((x,y))
    np.random.shuffle(temp)
    return temp[:,:x.shape[1]], temp[:,x.shape[1]:]


class Layer:
    def __init__(self, input_num, output_num, layer_name):
        # 该层的类别名字
        self._layer_name = layer_name
        # 该层的节点数
        self._unit_num = output_num
        # 初始化该层的权重参数
        self._weights = np.random.rand(input_num, output_num)*0.01
        # self._b = np.random.rand(1, output_num) * np.sqrt(2 / input_num)
        # 初始化b
        self._b = np.zeros((1, output_num))
        # 输入该层数据的维度
        self._input_num = input_num
        # 输出的维度
        self._output_num = output_num
        # 初始化输入与输出为0
        self._inputs = np.array([0.0] * self._input_num)
        self._outputs = np.array([0.0] * self._output_num)

    def _set_inputs(self, inputs):
        # 设置输入
        self._inputs = inputs.copy()
    
    def _get_inputs(self):
        # 取得该层的输入
        return self._inputs

    def _set_weights(self, weights):
        # 设置权重
        self._weights = weights.copy()
    
    def _set_b(self, b):
        # 设置b
        self._b = b.copy()

    def _get_weights(self):
        # shape = input * ouput
        # 获取一层的weights
        return self._weights
    
    def _get_b(self):
        # 获取b
        return self._b

    def _calculate_outputs(self):
        # 判断属于什么激活函数，然后代入对应的函数，计算最终输出结果
        if self._layer_name == 'softmax_layer':
            self._outputs = _softmax(np.dot(self._inputs,self._weights) + self._b)
        elif self._layer_name == 'sigmoid':
            self._outputs = _sigmoid(np.dot(self._inputs,self._weights) + self._b)
        elif self._layer_name == 'relu':
            self._outputs = _relu(np.dot(self._inputs,self._weights) + self._b)
        return self._outputs

    def _update(self, delta_weight, delta_b):
        # 更新权重和b
        self._weights = self._weights + delta_weight
        self._b = self._b + delta_b
class BPNN:
    def __init__(self, input_num, hidden_num, output_num, random_seed=3):
        # 输入维度
        self._input_num = input_num
        # 隐藏层节点数量
        self._hidden_num = hidden_num
        # 输出维度
        self._output_num = output_num
        # 隐藏层，激活函数为relu
        self._hidden_layer = Layer(self._input_num, self._hidden_num, 'relu')
        # self._hidden_layer = Layer(self._input_num, self._hidden_num, 'sigmoid')
        # 输出层，softmax
        self._output_layer = Layer(self._hidden_num, self._output_num, 'softmax_layer')
        # 设置随机数种子，保证每次初始化权重的随机值相同
        random.seed(random_seed)

    def _layer_load_data(self, layer, batch_sample):
        # 给layer传递输入的值
        layer._set_inputs(batch_sample)
        # 计算输出
        return layer._calculate_outputs()
    
    def _forward_output(self, sample):
        # 前向传播，计算输出结果
        hidden_layer_outputs = self._layer_load_data(self._hidden_layer, sample)
        output_layer_outputs = self._layer_load_data(self._output_layer, hidden_layer_outputs)
        return output_layer_outputs

    def _back_foward(self, batch_sample, batch_label, rate, lam):
        """
        对于输入的样本进行反向传播计算偏导
        返回各项变化量
        """
        # 样本数量
        m = batch_sample.shape[0]
        # batch_size * layer_output_num
        # 计算每一层的输出
        hidden_layer_outputs = self._layer_load_data(self._hidden_layer, batch_sample)
        output_layer_outputs = self._layer_load_data(self._output_layer, hidden_layer_outputs)
        
        # 获取每一层的权重
        output_layer_weights = self._output_layer._get_weights()
        hidden_layer_weights = self._hidden_layer._get_weights()
        # softmax层
        # shape: m * output_num
        # 计算减1过后的概率矩阵
        dZ_softmax = (output_layer_outputs-batch_label) / m
        # 计算权重的变化量
        delta_w = -rate * np.dot(hidden_layer_outputs.reshape(self._hidden_num, m), dZ_softmax)
        # 加上正则惩罚项
        # delta_w += -rate * lam/m*output_layer_weights
        # 计算b的变化量
        delta_bw = -rate * np.sum(dZ_softmax,axis=0,keepdims=True).reshape(1,-1)
        if self._hidden_layer._layer_name == 'relu':
            # relu
            # m * hidden_num
            # 隐藏层的偏差
            dZ_hidden = _drelu(hidden_layer_outputs) * np.dot(dZ_softmax, output_layer_weights.transpose())
        elif self._hidden_layer._layer_name == 'sigmoid':
            # sigmoid
            dZ_hidden = hidden_layer_outputs * (1 - hidden_layer_outputs) \
                * np.dot(dZ_softmax, output_layer_weights.transpose())
        # 计算隐藏层的权重的变化量
        delta_v = -rate * np.dot(batch_sample.reshape(self._input_num, m), dZ_hidden)
        # 正则惩罚项
        # delta_v += -rate * lam/m*hidden_layer_weights
        # 计算b的变化量
        delta_bv = -rate * np.sum(dZ_hidden,axis=0,keepdims=True).reshape(1,-1)

        
        return delta_w, delta_bw, delta_v, delta_bv

    def standard_train(self, samples, labels, samples_test, labels_test, rate=0.01, epochs=100, batch_size=2, lam=50):
        # 整个训练集的数量
        sample_num = samples.shape[0]
        count = 0
        best_acc1, best_acc2 = 0,0
        # samples, labels = shuffle_data(samples, labels)
        acc_train, acc_test, Loss = [],[],[]
        # 批量处理
        mini_batches_samples = [
            samples[k:k+batch_size]
            for k in range(0, sample_num, batch_size)
        ]
        mini_batches_labels = [
            labels[k:k+batch_size]
            for k in range(0, sample_num, batch_size)
        ]
        while count <= epochs:
            # 按batch遍历
            for i, batch in enumerate(mini_batches_samples):
                # 反向传播更新权重
                delta_w, delta_bw, delta_v, delta_bv = self._back_foward(batch, mini_batches_labels[i], rate, lam)
                self._output_layer._update(delta_w, delta_bw)
                self._hidden_layer._update(delta_v, delta_bv)
            
            # 每个epoch计算一次输出结果
            # 预测的概率
            y_pre_train = self._forward_output(samples)
            y_pre_test = self._forward_output(samples_test)
            # 交叉熵损失
            loss = -np.sum(np.log(np.max(y_pre_train,axis=1)))/sample_num
            # 记录整个loss
            Loss.append(loss)
            # 计算训练集和测试集上的准确率
            acc1 = calculate_acc(y_pre_train, labels)
            acc2 = calculate_acc(y_pre_test, labels_test)
            acc_train.append(acc1)
            acc_test.append(acc2)
            # 每100个epoch输出
            if count % 100 == 0:
                print('Epoch: %d, loss: %.6f' %(count, loss))
                # 更新最优的准确率
                best_acc1 = max(acc1, best_acc1)
                # 保存测试集上的最优模型
                if acc2 > best_acc2:
                    self.save("myBPNN.m")
                    best_acc2 = acc2
                # 记录最优的值
                print('Epoch: %d, acc_train %.4f, acc_test %.4f' % (count, acc1, acc2))
                # print('lr: %.6f' %rate)
            count = count + 1

        # 训练完毕
        print("\nTotal epochs: " + str(count-1))
        print('\nbest_acc1: %.4f, best_acc2: %.4f' %(best_acc1,best_acc2))
        return np.array(acc_train), np.array(acc_test), np.array(Loss)

    def get_bpnn(self):
        # 打印bpnn的参数
        hidden_layer_w = self._hidden_layer._get_weights()
        hidden_layer_b = self._hidden_layer._get_b()
        output_layer_w = self._output_layer._get_weights()
        output_layer_b = self._output_layer._get_b()
        print("Hidden Layer:")
        print("\nWeights:\n", hidden_layer_w, "\nb:\n", hidden_layer_b)
        print("Output Layer:")
        print("\nWeights:\n", output_layer_w, "\nb:\n", output_layer_b)

    def save(self, filename):
        # 保存训练好的神经网络
        model = {
            "hidden_layer_weights": self._hidden_layer._get_weights(),
            "output_layer_weights": self._output_layer._get_weights(),
            "hidden_layer_b": self._hidden_layer._get_b(),
            "output_layer_b": self._output_layer._get_b()        
        }
        with open(filename, "wb") as f:
            pickle.dump(model, f)
        print("Model Saved!")

    def load(self, filename):
        # 导入训练好的神经网络
        with open(filename, "rb") as f:
            model = pickle.load(f)
            self._hidden_layer._set_weights(model["hidden_layer_weights"])
            self._hidden_layer._set_b(model["hidden_layer_b"])
            self._output_layer._set_weights(model["output_layer_weights"])
            self._output_layer._set_b(model["output_layer_b"])
        print("Model loaded!")

def demo():
    # data_train, labels_train, data_test, labels_test = load_data()
    data_train, labels_train, data_test, labels_test = loadtxt()
    # data_train = normalization(data_train)
    # data_test = normalization(data_test)
    input_num = data_train.shape[1]
    hidden_num = 20
    output_num = 3
    myBPNN = BPNN(input_num, hidden_num, output_num)
    acc_train, acc_test, loss = myBPNN.standard_train(
                                                    samples=data_train, 
                                                    labels=labels_train, 
                                                    samples_test=data_test, 
                                                    labels_test=labels_test, 
                                                    rate=0.0001, 
                                                    epochs=1000,
                                                    batch_size=2,
                                                    lam=50)
    # acc_train, acc_test, loss = myBPNN.standard_train(samples=data_train, labels=labels_train, rate=0.0001, epochs=500, samples_test, labels_test)
    np.savetxt('acc_train.csv', acc_train, delimiter=',')
    np.savetxt('acc_test.csv', acc_test, delimiter=',')
    np.savetxt('loss.csv', loss, delimiter=',')
    print("Training Finished!")
    myBPNN.get_bpnn()
    # predict_label = myBPNN._forward_output(data_test)
    # test_acc = calculate_acc(predict_label, labels_test)
    # print('\ntest_acc: %.4f' %test_acc)
    # for i in range(len(labels_train)):
        # print(labels_train[i], '->', predict_label[i])
    # myBPNN.save("myBPNN.m")
    # test = BPNN(input_num, hidden_num, output_num)
    # test.load("myBPNN.m")
    # test.get_bpnn()
if __name__ == '__main__':
    demo()