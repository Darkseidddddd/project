import random
import numpy as np
import pickle
from MyError import *

# 生成(a,b)间的一个随机数
def _rand(a, b):
    return (b - a) * random.random() + a

# sigmoid function
def _sigmoid(x):
    return 1 / (1 + np.exp(-x))

# derivative of sigmoid function
def _dsigmoid(x):
    return _sigmoid(x) * (1 - _sigmoid(x))

# shape: 1 * output_num
def _softmax(x):
    return np.exp(x) / np.sum(np.exp(x),axis=1)

class Layer:
    def __init__(self, input_num, output_num):
        self._unit_num = output_num
        self._weights = np.random.rand(input_num, output_num)-0.5
        self._input_num = input_num
        self._output_num = output_num
        self._inputs = np.array([0.0] * self._input_num)
        self._outputs = np.array([0.0] * self._output_num)

    def _set_inputs(self, inputs):
        # inputs: np.array
        self._inputs = inputs.copy()
    
    def _get_inputs(self):
        # 取得该层的输入
        return self._inputs
    def _set_weights(self, weights):
        # weights: np.array
        # shape = input * output
        if weights.shape == (self._input_num, self._output_num):
            pass
        else:
            raise weights_size_err()
        self._weights = weights.copy()
    
    def _get_weights(self):
        # shape = input * ouput
        # 获取一层的weights
        return self._weights

    def _calculate_outputs(self):
        self._outputs = _sigmoid(np.dot(self._inputs.reshape(1,self._input_num),self._weights))
        return self._outputs

    def _update(self, delta_weight):
        self._weights = self._weights + delta_weight

class BPNN:
    def __init__(self, input_num, hidden_num, output_num):
        self._input_num = input_num
        self._hidden_num = hidden_num
        self._output_num = output_num
        self._hidden_layer = Layer(self._input_num, self._hidden_num)
        self._output_layer = Layer(self._hidden_num, self._output_num)

    def _layer_load_data(self, layer, sample):
        """
        给layer传送sample数据
        计算outputs返回
        shape: 1*output_num
        """
        layer._set_inputs(sample)
        return layer._calculate_outputs()

    def _single_sample_epoch(self, sample, label, rate):
        """
        对于单个输入样本计算参数改变量
        相当于标准BP
        返回各项变化量
        """

        hidden_layer_outputs = \
            self._layer_load_data(self._hidden_layer, sample)
        output_layer_outputs = \
            self._layer_load_data(self._output_layer, hidden_layer_outputs)
        
        # loss对z的偏微分
        # shape: 1 * output_num
        delta_out = output_layer_outputs * (1 - output_layer_outputs) \
            * (label.reshape(1,self._output_num) - output_layer_outputs)
        
        # shape: hidden_num * output_num
        delta_w = rate * np.dot(hidden_layer_outputs.reshape(self._hidden_num, 1), \
            delta_out.reshape(1,self._output_num))
        
        output_layer_weights = self._output_layer._get_weights()
        # shape: 1 * hidden_num
        delta_hidden = hidden_layer_outputs * (1 - hidden_layer_outputs) \
            * np.dot(delta_out, output_layer_weights.transpose())

        delta_v = rate * np.dot(sample.reshape(self._input_num, 1), \
            delta_hidden)

        E = 0.5 * np.sum((output_layer_outputs - label.reshape(1, self._output_num)) ** 2)
        return delta_w, delta_v, E

    def _single_sample_test(self, sample):
        """
        对于单个输入样本的测试
        返回Label
        shape: 1 * output_num
        """
        hidden_layer_outputs = \
            self._layer_load_data(self._hidden_layer, sample)
        output_layer_outputs = \
            self._layer_load_data(self._output_layer, hidden_layer_outputs)

        return output_layer_outputs

    def standard_train(self, samples, labels, rate=0.1, epochs=100):
        sample_num = samples.shape[0]

        count = 0
        r = rate
        while count <= epochs:
            E = 0
            for i in range(sample_num):
                rate = r
                delta_w, delta_v, e = self._single_sample_epoch(samples[i], labels[i], rate)
                E = E + e
                self._output_layer._update(delta_w)
                self._hidden_layer._update(delta_v)

            if count % 100 == 0:
                # print(E)
                print('Epoch: %d , Error %-.10f' % (count, E))
            count = count + 1

        print("\nTotal epochs: " + str(count-1))

    def get_bpnn(self):
        """
        打印bpnn参数
        """
        hidden_layer = self._hidden_layer._get_weights()
        output_layer = self._output_layer._get_weights()
        print("Hidden Layer:")
        print("\nWeights:\n", hidden_layer[1])
        print("Output Layer:")
        print("\nWeights:\n", output_layer[1])

    def test(self, samples):
        """
        训练好的bpnn的测试
        """
        if samples.shape[1] != self._input_num:
            raise sample_size_err()
        labels = np.empty([0,self._output_num])
        for i in range(samples.shape[0]):
            labels = np.row_stack((labels, \
                self._single_sample_test(samples[i])))
        return labels

    def save(self, filename):
        """
        保存bp神经网络
        """
        model = {
            "hidden_layer_weights": self._hidden_layer._get_weights(),
            "output_layer_weights": self._output_layer._get_weights(),
            # "hidden_layer_thresholds": self._hidden_layer._get_thresholds(),
            # "output_layer_thresholds": self._output_layer._get_thresholds()        
        }
        with open(filename, "wb") as f:
            pickle.dump(model, f)
        print("Model Saved!")

    def load(self, filename):
        """
        导入bp神经网络
        """
        with open(filename, "rb") as f:
            model = pickle.load(f)
            self._hidden_layer._set_weights(model["hidden_layer_weights"])
            # self._hidden_layer._set_thresholds(model["hidden_layer_thresholds"])
            self._output_layer._set_weights(model["output_layer_weights"])
            # self._output_layer._set_thresholds(model["output_layer_thresholds"])
        print("Model loaded!")

def demo():
    input_num, hidden_num, output_num = 5,4,4
    myBPNN = BPNN(input_num, hidden_num, output_num)
    data = np.array([[1,0,2,3,4],[0,1,4,2,2],[4,0,1,1,3],[1,4,1,2,3]])
    label = np.array([[0,1,0,0], [0,1,0,0], [1,0,0,0], [0,0,0,1]])
    myBPNN.standard_train(samples=data, labels=label, rate=1, epochs=1000)
    myBPNN.standard_train(samples=data, labels=label, rate=0.1, epochs=500)
    print("Training Finished!")
    myBPNN.get_bpnn()
    predict_label = myBPNN.test(data)
    for i in range(len(label)):
        print(label[i], '->', predict_label[i])
    myBPNN.save("myBPNN.m")
    test = BPNN(input_num, hidden_num, output_num)
    test.load("myBPNN.m")
    test.get_bpnn()
if __name__ == '__main__':
    demo()