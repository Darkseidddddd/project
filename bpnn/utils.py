import numpy as np
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
