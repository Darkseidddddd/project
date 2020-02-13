### 任务描述：

​	在之前的神经网络作业基础上实现softmax进行多分类。不得调用机器学习框架中已有的实现，使用python实现softmax的前向与后向过程。

### 基本数据集：

（train.csv, test.csv）
在训练集上进行训练，并在数据集上进行预测。

### 拓展数据集：

（thyroid.txt）
将实现的模型在此数据集上训练（自己划分训练集，数据集），观察模型是否能够拟合此数据集，并设法提高模型的准确率。

---

#### 一. softmax反向传播推导

##### 1. softmax函数如下

$$
P_{i,k}=\frac{e^{f_{i,k}}}{\sum^m_{j=1}e^{f_{i,j}}}
$$

##### 2. 损失函数

$$
Loss =-log(P_{yi})
$$

##### 3. 求解

求：
$$
\frac{\partial L}{\partial X}\ \ \ \ \ \ \ \ \ \ \ \ \ \frac{\partial L}{\partial W}\ \ \ \ \ \ \ \ \ \ \ \ \ \frac{\partial L}{\partial b}
$$

###### (1) 在softmax中对变量 $p\_{yi}$ 求导

$$
P_{i,k}=\frac{e^{f_{i,k}}}{\sum^m_{j=1}e^{f_{i,j}}}看成一个整体
$$

所以对此函数求导
$$
\frac{\partial L_{i}}{\partial P_{yi}}=-\frac{1}{P_{yi}}
$$

###### (2) 利用bp算法的思路

在 $P_{yi}$ 中对变量 $f_{x}$ 求导，其中的 $\sum_je^{f_i}=e^{f_1}+e^{f_2}+\cdots+e^{f_n}$。对其求偏导有两种情况

* $k=y_i$

$$
\frac{\partial P_{yi}}{\partial f_{yi}}=\frac{e^{f_{yi}}\sum_je^{f_j}-e^{f_{yi}}*e^{f_{yi}}}{(\sum_je^{f_j})^2}=P_{yi}-(P_{yi})^2\\
结合\frac{\partial L_i}{\partial P_{yi}}=-\frac{1}{P_{yi}}可以得到\frac{\partial L_i}{\partial f_{yi}}=\frac{\partial L_i}{\partial P_{yi}}\frac{\partial P_{yi}}{\partial f_{yi}}=P_{yi}-1
$$

* $k\neq y_i$

$$
\frac{\partial P_{yi}}{\partial f_k}=\frac{-e^{f_k}*e^{f_{yi}}}{\sum_j(e^{f_j})^2}=-P_{yi}*P_k\\
结合\frac{\partial L_i}{\partial P_{yi}}=-\frac{1}{P_{yi}}可以得到\frac{\partial L_i}{\partial f_k}=\frac{\partial L_i}{\partial P_{yi}}\frac{\partial P_{yi}}{\partial f_k}=P_k
$$

###### (3) 对 $f_k$ 函数求微分

$ f(x_i:W)=Wx_i+b$

在 $f_k$ 中对变量 $W、X、b$ 求导 
$$
\frac{\partial f}{\partial x_i}=W\ \ \ \ \ \ \ \ \ \ \ \ \ \frac{\partial f}{\partial W}=x_i\ \ \ \ \ \ \ \ \ \ \ \ \ \frac{\partial f}{\partial b}=1\\
$$
结合前面的
$$
\frac{\partial L_i}{\partial f_{yi}}=\frac{\partial L_i}{\partial P_{yi}}\frac{\partial P_{yi}}{\partial f_{yi}}=P_{yi}-1\ \ \ \ \ \ \ \ \ \ \ \ \frac{\partial L_i}{\partial f_k}=\frac{\partial L_i}{\partial P_{yi}}\frac{\partial P_{yi}}{\partial f_k}=P_k
$$


可以得到如下的梯度公式
$$
\frac{\partial L_i}{\partial W_{yi}}=x_i(P_{yi}-1)\ \ \ \ \ \ \ \ \ \ \ \ \ \frac{\partial L_i}{\partial W_{k}}=x_iP_k(k\neq y_i)\ \ \ \ \ \ \ \ \ \ \ \ \ dW=\frac{\partial L_i}{\partial W}=x_iP
$$
这里的**P**是经减1后得出的概率矩阵
$$
dx=\frac{\partial L_i}{\partial x_i}=PW\\
db=\frac{\partial L_i}{\partial b}=P
$$
所以现在就可以将这些梯度用于反向传播，与之前的神经网络结合起来求解。

#### 二. 实现

##### 1. 基本数据集

数据集有train.csv和test.csv，已经划分好了训练集和测试集

总共有3类，训练集有4001条数据，测试集有500条数据，特征维度为2维。

其中训练集的分布图像如下
![](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/5/1.png)

测试集的分布图像如下

![](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/5/2.png)

可以看到训练集中有几个点交缠在一块。

###### （1）首先设置隐藏层的激活函数为sigmoid

参数如下：

> input_num = 4001
>
> hidden_num = 5
>
> output_num = 3
>
> 激活函数: sigmoid
>
> learing rate = 0.001
>
> epochs = 1000
>
> batch_size = 2

最终结果如下：

![](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/5/3.png)

loss曲线如下，可以看到大概在400个epoch就接近收敛了

![](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/5/4.png)

训练集和测试集的准确率变化情况如下：

训练集：

![](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/5/7.png)

测试集：

![](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/5/5.png)

将测试集的准确率图像拉长过后如下：

![6](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/5/6.png)

可以看到大概到100个epoch，就已经达到最优的结果了，测试集上的准确率为0.9980。

###### （2）设置激活函数为relu

参数如下：

> input_num = 4001
>
> hidden_num = 5
>
> output_num = 3
>
> 激活函数: sigmoid
>
> learing rate = 0.0001
>
> epochs = 1000
>
> batch_size = 2

最终结果如下：

![](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/5/12.png)

loss曲线如下：

![](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/5/8.png)

训练集测试集的准确率变化情况如下：

训练集：

![](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/5/9.png)

测试集：

![](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/5/10.png)

拉长后的图像：

![](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/5/11.png)

大概在40个epoch左右就已经达到最好的效果了，测试集上最好的准确率为0.998。可见relu激活函数实际上要比sigmoid激活函数好。

##### 2. 拓展数据集

数据集名称为thyroid.txt

训练集和测试集需要自己划分

总共有3类，7200条数据，特征维度为21维。

###### （1）3 : 7划分

参数如下：

> input_num = 5040
>
> hidden_num = 20
>
> output_num = 3
>
> 激活函数: sigmoid
>
> learing rate = 0.0001
>
> epochs = 1000
>
> batch_size = 2

最终结果：

![](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/5/19.png)

loss曲线：

![](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/5/20.png)

训练集测试集准确率变化情况：

![](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/5/21.png)

loss大概在200个epoch就基本收敛了，但是训练集和测试集的准确率从一开始就保持不变，测试集最优为0.9134。

###### （2）5 : 5划分

参数如下：

> input_num = 3600
>
> hidden_num = 20
>
> output_num = 3
>
> 激活函数: relu
>
> learing rate = 0.0001
>
> epochs = 1000
>
> batch_size = 2

最终结果如下：

![](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/5/16.png)

loss曲线如下：

![](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/5/17.png)

测试集训练集的准确率变化情况：

![](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/5/18.png)

loss大概在200个epoch就基本收敛了，但是训练集和测试集的准确率还是从一开始保持不变，测试集最优为0.9247。

###### （3）0.15 : 0.85划分

参数如下：

> input_num = 1080
>
> hidden_num = 20
>
> output_num = 3
>
> 激活函数: relu
>
> learing rate = 0.0001
>
> epochs = 1000
>
> batch_size = 2

最终结果如下：

![](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/5/13.png)

loss曲线如下：

![](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/5/14.png)

训练集和测试集的准确率变化情况如下：

![](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/5/15.png)

可以看到loss一直在下降，准确率还是不变。此时测试集准确率最优为0.9275。

###### （4）加上正则惩罚项

```python
# 加上正则惩罚项
delta_w += -rate * lam/m*output_layer_weights
delta_v += -rate * lam/m*hidden_layer_weights
```

采用0.15 : 0.85的划分方式

参数如下：

> input_num = 1080
>
> hidden_num = 20
>
> output_num = 3
>
> 激活函数: relu
>
> learing rate = 0.0001
>
> epochs = 1000
>
> batch_size = 2

最终结果如下：

![](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/5/22.png)

最终训练出来的部分权重矩阵如下：

![](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/5/23.png)

![24](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/5/24.png)

可以看到很多节点的权重值非常小，不会产生梯度爆炸问题。

###### （5）不加正则化项

和上面一样的参数，最终得到部分权重如下：

![](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/5/25.png)

![26](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/5/26.png)

此时结果就没有那么小了，此时如果学习率过大，就可能在反向传播的时候发生溢出，即梯度爆炸。

最终结果如下：

![](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/5/27.png)

测试集的准确率有轻微改变，所以是否加上正则化惩罚项可能会对结果产生影响。

#### 三. 遇到的问题

##### （1）学习率过大

刚开始在调整学习率的过程中，我把lr设为1，0.1，0.01，在结果出现了NaN的情况，发现是因为学习率过大，导致了计算梯度的时候结果太大，超出了exp的范围，梯度爆炸的问题。所以最终，我的学习率都不是很大。

##### （2）batch_size为整个训练集大小

结果的准确率为0.33，反向传播失效，不知道什么原因，可能梯度消失了。而且batch_size越大，我的训练速度越快。在多次测试中我发现，batch_size越大，最终结果并没有小的时候好，所以我的batch_size基本都设置为2了。

##### （3）拟合结果

可能因为数据集太小，基本上都不需要1000个epoch就能达到最优结果，甚至只需要200个左右，但是loss是一直在下降。对于拓展数据集，可能因为分类为3的类别占了一大部分，导致最终结果看上去没有训练的过程。




