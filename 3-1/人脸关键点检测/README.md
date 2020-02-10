### 任务描述：
使用（96，96）的灰度图进行15个人脸关键点的预测
### 数据集介绍：
训练集包含人脸图像以及相应的关键点坐标，测试集只包含人脸图像
### Baseline介绍：
包含了读取数据集，输入标签分离，结果导出等代码。
* 评测方式：
* * 使用自己编写的模型对训练集数据进行预测，将预测结果使用提供的函数导出到csv文件，文件使用完整的学号命名。

---
---

### 一. 数据集

单通道灰度值图像

图片大小：96 × 96 × 1

训练集大小：6001

测试集大小：1048

总共十五个关键点：

> `left` / `right` eye center
>
> `left` / `right` eye `inner` / `outer` corner
>
> `left` / `right` eyebrow `inner` / `outer`end
>
> nose tip
>
> mouth `left` / `right` center
>
> mouth center `top` / `bottom` lip

标签由关键点坐标组成的一维向量，其中奇数索引代表横坐标，偶数索引代表纵坐标，15个关键点摊开为30个值。

随机读取训练集图片展示如下：

<img src="https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/6/1.png" style="zoom:67%;" />

### 二. 环境

1. Linux
2. GTX 1080 8G × 2
3. python 3.7
4. Tensorflow-gpu 1.15.0
5. keras 2.3.1

### 三. 模型

* 卷积神经网络

```python
def Conv2d_BN(x, nb_filter, kernel_size, strides=(1, 1), padding='same', activation=True, name=None):
    '''
    定义convolution + batch normalization层
    参数
    x: tensor, 输入特征\图片
    nb_filter: int, 输出通道数
    kernel_size: (n,n), 卷积核大小
    strides: int, 卷积步长
    padding: string, 'same' or 'valid', 边界是否填充
    activation: boolean, 是否使用激活函数
    name: string, 名字
    '''
    if name is not None:
        bn_name = name + '_bn'
        conv_name = name + '_conv'
    else:
        bn_name = None
        conv_name = None
	# 卷积层
    x = Conv2D(nb_filter, kernel_size, padding=padding, use_bias=True, strides=strides, name=conv_name)(x)
    if activation:
    	# LeakyReLU激活函数
    	x = LeakyReLU(alpha=0.1)(x)
    # bn层
    x = BatchNormalization(axis=3, name=bn_name)(x)
    return x

def myModel(width,height,channel,classes):
    '''
    定义模型
    width, height: 图片的宽和高
    channel: 通道数
    classes: 输出节点数
    '''
    inpt = Input(shape=(width, height, channel))
    # layer 1
    x = Conv2d_BN(x=inpt, nb_filter=32, kernel_size=(3,3), strides=(1,1), padding='same', name='layer1_1')
    x = Conv2d_BN(x=x, nb_filter=32, kernel_size=(3,3), strides=(1,1), padding='same', name='layer1_2')
    x = MaxPooling2D(pool_size=(2, 2), strides=(2, 2), padding='valid')(x)

    # layer 2
    x = Conv2d_BN(x=x, nb_filter=64, kernel_size=(3,3), strides=(1,1), padding='same', name='layer2_1')
    x = Conv2d_BN(x=x, nb_filter=64, kernel_size=(3,3), strides=(1,1), padding='same', name='layer2_2')
    x = MaxPooling2D(pool_size=(2, 2), strides=(2, 2), padding='valid')(x)

    # layer 3
    x = Conv2d_BN(x=x, nb_filter=96, kernel_size=(3,3), strides=(1,1), padding='same', name='layer3_1')
    x = Conv2d_BN(x=x, nb_filter=96, kernel_size=(3,3), strides=(1,1), padding='same', name='layer3_2')
    x = MaxPooling2D(pool_size=(2, 2), strides=(2, 2), padding='valid')(x)

    # layer 4
    x = Conv2d_BN(x=x, nb_filter=128, kernel_size=(3,3), strides=(1,1), padding='same', name='layer4_1')
    x = Conv2d_BN(x=x, nb_filter=128, kernel_size=(3,3), strides=(1,1), padding='same', name='layer4_2')
    x = MaxPooling2D(pool_size=(2, 2), strides=(2, 2), padding='valid')(x)

    # layer 5
    x = Conv2d_BN(x=x, nb_filter=256, kernel_size=(3,3), strides=(1,1), padding='same', name='layer5_1')
    x = Conv2d_BN(x=x, nb_filter=256, kernel_size=(3,3), strides=(1,1), padding='same', name='layer5_2')
    x = MaxPooling2D(pool_size=(2, 2), strides=(2, 2), padding='valid')(x)

    # layer 6
    x = Conv2d_BN(x=x, nb_filter=512, kernel_size=(3,3), strides=(1,1), padding='same', name='layer6_1')
    x = Conv2d_BN(x=x, nb_filter=512, kernel_size=(3,3), strides=(1,1), padding='same', name='layer6_2')
    x = AveragePooling2D(pool_size=(2, 2), strides=(2, 2), padding='valid')(x)

    # fullyconnected layer
    x = Flatten()(x)
    x = Dense(1000, activation='relu')(x)
    x = Dropout(0.1)(x)
    x = Dense(classes)(x)

    model = Model(inputs=inpt, outputs=x)
    return model
```

总共12个卷积层，12个bn层，采用小卷积核， (3,3) 大小，加深层数，步长为2，前面5个layer用最大池化捕捉突出特征，最后卷积输出用平均池化获取全局信息，激活函数采用LeakyReLU，防止在卷积计算为负的点直接取消梯度。最后接一个全连接层，采用relu激活函数，用0.1的drop rate连接一个dropout层，防止过拟合。再连一个输出层。

模型大小为41M。

### 四. 调试过程

* `train.csv` 划分：

> 训练集 : 验证集 = 9 : 1

* 数据归一化处理，像素值约束在[ 0, 1 ]之间，标签坐标约束在[ -1, 1 ]。

* 评测指标：

$$
RMSE=\sqrt {\frac {1}{n}\sum_{i=1}^n(y_i-\hat y_i)^2}\\
MSE=\frac {1}{n}\sum_{i=1}^n(y_i-\hat y_i)^2
$$

* 当验证集的loss连续超过10个epochs没下降时，降级学习率，变为原来的一办。
* 当验证集的loss连续超过15个epochs没下降时，停止训练。
* 每次保存最优模型

#### 1. 卷积层数

##### （1）4层

参数：

> epochs: 100
>
> batch_size: 32
>
> dropout_rate: 0.1
>
> use_bias = True
>
> optimizer: RMSprop(参数为默认值lr=0.001, rho=0.9, epsilon=None, decay=0.0)

模型：

|                       | 通道数  | 卷积核大小 | 步长  | padding | 节点数 |
| --------------------- | ------- | ---------- | ----- | ------- | ------ |
| layer1/layer1_1       | 1==>32  | (3,3)      | (1,1) | same    |        |
| layer1/layer1_2       | 32==>32 | (3,3)      | (1,1) | same    |        |
| layer1/AveragePooling | 32==>32 | (2,2)      | (2,2) | valid   |        |
| Dense（隐藏层）       |         |            |       |         | 1000   |
| Dense（输出层）       |         |            |       |         | 30     |

```python
def myModel(width,height,channel,classes):
    inpt = Input(shape=(width, height, channel))
    # layer 1
    x = Conv2d_BN(x=inpt, nb_filter=32, kernel_size=(3,3), strides=(1,1), padding='same', name='layer1_1')
    x = Conv2d_BN(x=x, nb_filter=32, kernel_size=(3,3), strides=(1,1), padding='same', name='layer1_2')
    x = AveragePooling2D(pool_size=(2, 2), strides=(2, 2), padding='valid')(x)
    
    x = Flatten()(x)
    x = Dense(1000, activation='relu')(x)
    x = Dropout(0.1)(x)
    x = Dense(classes)(x)
```

结果：

![](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/6/loss1.png)

左边为训练集loss变化曲线，右边为验证集的loss变化曲线。

可以看到23个epochs就收敛了，不再继续训练。

最终验证集上的loss为 ***3.18328321***。

得到的效果并不好，继续加深层数。

##### （2）8层

参数：

> epochs: 100
>
> batch_size: 32
>
> dropout_rate: 0.1
>
> use_bias = True
>
> optimizer: RMSprop(参数为默认值lr=0.001, rho=0.9, epsilon=None, decay=0.0)

模型：

|                 | 通道数  | 卷积核大小 | 步长  | padding | 节点数 |
| --------------- | ------- | ---------- | ----- | ------- | ------ |
| layer1/layer1_1 | 1==>32  | (3,3)      | (1,1) | same    |        |
| layer1/layer1_2 | 32==>32 | (3,3)      | (1,1) | same    |        |
| MaxPooling      | 32==>32 | (2,2)      | (2,2) | valid   |        |
| layer2/layer2_1 | 32==>64 | (3,3)      | (1,1) | same    |        |
| layer2/layer2_2 | 64==>64 | (3,3)      | (1,1) | same    |        |
| MaxPooling      | 64==>64 | (2,2)      | (2,2) | valid   |        |
| layer3/layer3_1 | 64==>96 | (3,3)      | (1,1) | same    |        |
| layer3/layer3_2 | 96=>96  | (3,3)      | (1,1) | same    |        |
| AveragePooling  | 96==>96 | (2,2)      | (2,2) | valid   |        |
| Dense（隐藏层） |         |            |       |         | 1000   |
| Dense（输出层） |         |            |       |         | 30     |

```python
def myModel(width,height,channel,classes):
    inpt = Input(shape=(width, height, channel))
    # layer 1
    x = Conv2d_BN(x=inpt, nb_filter=32, kernel_size=(3,3), strides=(1,1), padding='same', name='layer1_1')
    x = Conv2d_BN(x=x, nb_filter=32, kernel_size=(3,3), strides=(1,1), padding='same', name='layer1_2')
    x = MaxPooling2D(pool_size=(2, 2), strides=(2, 2), padding='valid')(x)

    # layer 2
    x = Conv2d_BN(x=x, nb_filter=64, kernel_size=(3,3), strides=(1,1), padding='same', name='layer2_1')
    x = Conv2d_BN(x=x, nb_filter=64, kernel_size=(3,3), strides=(1,1), padding='same', name='layer2_2')
    x = MaxPooling2D(pool_size=(2, 2), strides=(2, 2), padding='valid')(x)

    # layer 3
    x = Conv2d_BN(x=x, nb_filter=96, kernel_size=(3,3), strides=(1,1), padding='same', name='layer3_1')
    x = Conv2d_BN(x=x, nb_filter=96, kernel_size=(3,3), strides=(1,1), padding='same', name='layer3_2')
    x = MaxPooling2D(pool_size=(2, 2), strides=(2, 2), padding='valid')(x)
    
    x = Flatten()(x)
    x = Dense(1000, activation='relu')(x)
    x = Dropout(0.1)(x)
    x = Dense(classes)(x)

    model = Model(inputs=inpt, outputs=x)
    return model
```

结果：

![](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/6/loss2.png)

左边为训练集的loss变化曲线，右边为验证集的loss变化曲线。

因为最值相差太大，所以后面基本看不出变化，也是过早就趋于收敛了。

最终验证集上的loss为***2.05023092***。

继续加深层数。

##### （3）12层

参数：

> epochs: 100
>
> batch_size: 32
>
> dropout_rate: 0.1
>
> use_bias = True
>
> optimizer: RMSprop(参数为默认值lr=0.001, rho=0.9, epsilon=None, decay=0.0)

模型：

|                 | 通道数    | 卷积核大小 | 步长  | padding | 节点数 |
| --------------- | --------- | ---------- | ----- | ------- | ------ |
| layer1/layer1_1 | 1==>32    | (3,3)      | (1,1) | same    |        |
| layer1/layer1_2 | 32==>32   | (3,3)      | (1,1) | same    |        |
| MaxPooling      | 32==>32   | (2,2)      | (2,2) | valid   |        |
| layer2/layer2_1 | 32==>64   | (3,3)      | (1,1) | same    |        |
| layer2/layer2_2 | 64==>64   | (3,3)      | (1,1) | same    |        |
| MaxPooling      | 64==>64   | (2,2)      | (2,2) | valid   |        |
| layer3/layer3_1 | 64==>96   | (3,3)      | (1,1) | same    |        |
| layer3/layer3_2 | 96=>96    | (3,3)      | (1,1) | same    |        |
| MaxPooling      | 96==>96   | (2,2)      | (2,2) | valid   |        |
| layer4/layer4_1 | 96==>128  | (3,3)      | (1,1) | same    |        |
| layer4/layer4_2 | 128==>128 | (3,3)      | (1,1) | same    |        |
| MaxPooling      | 128==>128 | (2,2)      | (2,2) | valid   |        |
| layer5/layer5_1 | 128==>256 | (3,3)      | (1,1) | same    |        |
| layer5/layer5_2 | 256==>256 | (3,3)      | (1,1) | same    |        |
| MaxPooling      | 256==>256 | (2,2)      | (2,2) | valid   |        |
| layer6_1        | 256==>512 | (3,3)      | (1,1) | same    |        |
| layer6_2        | 512==>512 | (3,3)      | (1,1) | same    |        |
| AveragePooling  | 512==>512 | (2,2)      | (2,2) | valid   |        |
| Dense（隐藏层） |           |            |       |         | 1000   |
| Dense（输出层） |           |            |       |         | 30     |

```python
def myModel(width,height,channel,classes):
    inpt = Input(shape=(width, height, channel))
    # layer 1
    x = Conv2d_BN(x=inpt, nb_filter=32, kernel_size=(3,3), strides=(1,1), padding='same', name='layer1_1')
    x = Conv2d_BN(x=x, nb_filter=32, kernel_size=(3,3), strides=(1,1), padding='same', name='layer1_2')
    x = MaxPooling2D(pool_size=(2, 2), strides=(2, 2), padding='valid')(x)

    # layer 2
    x = Conv2d_BN(x=x, nb_filter=64, kernel_size=(3,3), strides=(1,1), padding='same', name='layer2_1')
    x = Conv2d_BN(x=x, nb_filter=64, kernel_size=(3,3), strides=(1,1), padding='same', name='layer2_2')
    x = MaxPooling2D(pool_size=(2, 2), strides=(2, 2), padding='valid')(x)

    # layer 3
    x = Conv2d_BN(x=x, nb_filter=96, kernel_size=(3,3), strides=(1,1), padding='same', name='layer3_1')
    x = Conv2d_BN(x=x, nb_filter=96, kernel_size=(3,3), strides=(1,1), padding='same', name='layer3_2')
    x = MaxPooling2D(pool_size=(2, 2), strides=(2, 2), padding='valid')(x)

    # layer 4
    x = Conv2d_BN(x=x, nb_filter=128, kernel_size=(3,3), strides=(1,1), padding='same', name='layer4_1')
    x = Conv2d_BN(x=x, nb_filter=128, kernel_size=(3,3), strides=(1,1), padding='same', name='layer4_2')
    x = MaxPooling2D(pool_size=(2, 2), strides=(2, 2), padding='valid')(x)

    # layer 5
    x = Conv2d_BN(x=x, nb_filter=256, kernel_size=(3,3), strides=(1,1), padding='same', name='layer5_1')
    x = Conv2d_BN(x=x, nb_filter=256, kernel_size=(3,3), strides=(1,1), padding='same', name='layer5_2')
    x = MaxPooling2D(pool_size=(2, 2), strides=(2, 2), padding='valid')(x)

    # layer 6
    x = Conv2d_BN(x=x, nb_filter=512, kernel_size=(3,3), strides=(1,1), padding='same', name='layer6_1')
    x = Conv2d_BN(x=x, nb_filter=512, kernel_size=(3,3), strides=(1,1), padding='same', name='layer6_2')
    x = AveragePooling2D(pool_size=(2, 2), strides=(2, 2), padding='valid')(x)

    # fullyconnected layer
    x = Flatten()(x)
    x = Dense(1000, activation='relu')(x)
    x = Dropout(0.1)(x)
    x = Dense(classes)(x)
```

结果：

![](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/6/loss3.png)

左边为训练集的loss曲线，右边为验证集的loss曲线。

训练集大概在30个epochs后就收敛了，测试集40个epochs之前抖动比较厉害，之后也趋于稳定。大概在66个epochs就达到停止的条件。

最终验证集上的loss为***1.80527330***。

综上：

|      | 模型大小 | RMSE       |
| ---- | -------- | ---------- |
| 4层  | 562M     | 3.18328321 |
| 8层  | 107M     | 2.05023092 |
| 12层 | 41.6M    | 1.80527330 |

可以看到12层的模型效果最好。不知道为什么层数减小模型反而异常的大，可能保存了其它的什么数据。

#### 2. 卷积核大小

##### （1）2 × 2

参数：

> epochs: 100
>
> batch_size: 32
>
> dropout_rate: 0.1
>
> use_bias = True
>
> optimizer: RMSprop(参数为默认值lr=0.001, rho=0.9, epsilon=None, decay=0.0)

模型：

|                 | 通道数    | 卷积核大小 | 步长  | padding | 节点数 |
| --------------- | --------- | ---------- | ----- | ------- | ------ |
| layer1/layer1_1 | 1==>32    | (2,2)      | (1,1) | same    |        |
| layer1/layer1_2 | 32==>32   | (2,2)      | (1,1) | same    |        |
| MaxPooling      | 32==>32   | (2,2)      | (2,2) | valid   |        |
| layer2/layer2_1 | 32==>64   | (2,2)      | (1,1) | same    |        |
| layer2/layer2_2 | 64==>64   | (2,2)      | (1,1) | same    |        |
| MaxPooling      | 64==>64   | (2,2)      | (2,2) | valid   |        |
| layer3/layer3_1 | 64==>96   | (2,2)      | (1,1) | same    |        |
| layer3/layer3_2 | 96=>96    | (2,2)      | (1,1) | same    |        |
| MaxPooling      | 96==>96   | (2,2)      | (2,2) | valid   |        |
| layer4/layer4_1 | 96==>128  | (2,2)      | (1,1) | same    |        |
| layer4/layer4_2 | 128==>128 | (2,2)      | (1,1) | same    |        |
| MaxPooling      | 128==>128 | (2,2)      | (2,2) | valid   |        |
| layer5/layer5_1 | 128==>256 | (2,2)      | (1,1) | same    |        |
| layer5/layer5_2 | 256==>256 | (2,2)      | (1,1) | same    |        |
| MaxPooling      | 256==>256 | (2,2)      | (2,2) | valid   |        |
| layer6_1        | 256==>512 | (2,2)      | (1,1) | same    |        |
| layer6_2        | 512==>512 | (2,2)      | (1,1) | same    |        |
| AveragePooling  | 512==>512 | (2,2)      | (2,2) | valid   |        |
| Dense（隐藏层） |           |            |       |         | 1000   |
| Dense（输出层） |           |            |       |         | 30     |

```python
def myModel(width,height,channel,classes):
    inpt = Input(shape=(width, height, channel))
    # layer 1
    x = Conv2d_BN(x=inpt, nb_filter=32, kernel_size=(2,2), strides=(1,1), padding='same', name='layer1_1')
    x = Conv2d_BN(x=x, nb_filter=32, kernel_size=(2,2), strides=(1,1), padding='same', name='layer1_2')
    x = MaxPooling2D(pool_size=(2, 2), strides=(2, 2), padding='valid')(x)

    # layer 2
    x = Conv2d_BN(x=x, nb_filter=64, kernel_size=(2,2), strides=(1,1), padding='same', name='layer2_1')
    x = Conv2d_BN(x=x, nb_filter=64, kernel_size=(2,2), strides=(1,1), padding='same', name='layer2_2')
    x = MaxPooling2D(pool_size=(2, 2), strides=(2, 2), padding='valid')(x)

    # layer 3
    x = Conv2d_BN(x=x, nb_filter=96, kernel_size=(2,2), strides=(1,1), padding='same', name='layer3_1')
    x = Conv2d_BN(x=x, nb_filter=96, kernel_size=(2,2), strides=(1,1), padding='same', name='layer3_2')
    x = MaxPooling2D(pool_size=(2, 2), strides=(2, 2), padding='valid')(x)

    # layer 4
    x = Conv2d_BN(x=x, nb_filter=128, kernel_size=(2,2), strides=(1,1), padding='same', name='layer4_1')
    x = Conv2d_BN(x=x, nb_filter=128, kernel_size=(2,2), strides=(1,1), padding='same', name='layer4_2')
    x = MaxPooling2D(pool_size=(2, 2), strides=(2, 2), padding='valid')(x)

    # layer 5
    x = Conv2d_BN(x=x, nb_filter=256, kernel_size=(2,2), strides=(1,1), padding='same', name='layer5_1')
    x = Conv2d_BN(x=x, nb_filter=256, kernel_size=(2,2), strides=(1,1), padding='same', name='layer5_2')
    x = MaxPooling2D(pool_size=(2, 2), strides=(2, 2), padding='valid')(x)

    # layer 6
    x = Conv2d_BN(x=x, nb_filter=512, kernel_size=(2,2), strides=(1,1), padding='same', name='layer6_1')
    x = Conv2d_BN(x=x, nb_filter=512, kernel_size=(2,2), strides=(1,1), padding='same', name='layer6_2')
    x = AveragePooling2D(pool_size=(2, 2), strides=(2, 2), padding='valid')(x)

    # fullyconnected layer
    x = Flatten()(x)
    x = Dense(1000, activation='relu')(x)
    x = Dropout(0.1)(x)
    x = Dense(classes)(x)

    model = Model(inputs=inpt, outputs=x)
    return model
```

最终结果：

![](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/6/loss4.png)

左边为训练集loss曲线，右边为验证集loss曲线。

55个epochs达到停止条件，30个epochs之后趋向于收敛。

最终验证集上的loss为***1.82733778***。

显然效果比 (3,3) 的卷积核差。

##### （2）4 × 4

参数：

> epochs: 100
>
> batch_size: 32
>
> dropout_rate: 0.1
>
> use_bias = True
>
> optimizer: RMSprop(参数为默认值lr=0.001, rho=0.9, epsilon=None, decay=0.0)

模型：

|                 | 通道数    | 卷积核大小 | 步长  | padding | 节点数 |
| --------------- | --------- | ---------- | ----- | ------- | ------ |
| layer1/layer1_1 | 1==>32    | (4,4)      | (1,1) | same    |        |
| layer1/layer1_2 | 32==>32   | (4,4)      | (1,1) | same    |        |
| MaxPooling      | 32==>32   | (2,2)      | (2,2) | valid   |        |
| layer2/layer2_1 | 32==>64   | (4,4)      | (1,1) | same    |        |
| layer2/layer2_2 | 64==>64   | (4,4)      | (1,1) | same    |        |
| MaxPooling      | 64==>64   | (2,2)      | (2,2) | valid   |        |
| layer3/layer3_1 | 64==>96   | (4,4)      | (1,1) | same    |        |
| layer3/layer3_2 | 96=>96    | (4,4)      | (1,1) | same    |        |
| MaxPooling      | 96==>96   | (2,2)      | (2,2) | valid   |        |
| layer4/layer4_1 | 96==>128  | (4,4)      | (1,1) | same    |        |
| layer4/layer4_2 | 128==>128 | (4,4)      | (1,1) | same    |        |
| MaxPooling      | 128==>128 | (2,2)      | (2,2) | valid   |        |
| layer5/layer5_1 | 128==>256 | (4,4)      | (1,1) | same    |        |
| layer5/layer5_2 | 256==>256 | (4,4)      | (1,1) | same    |        |
| MaxPooling      | 256==>256 | (2,2)      | (2,2) | valid   |        |
| layer6_1        | 256==>512 | (4,4)      | (1,1) | same    |        |
| layer6_2        | 512==>512 | (4,4)      | (1,1) | same    |        |
| AveragePooling  | 512==>512 | (2,2)      | (2,2) | valid   |        |
| Dense（隐藏层） |           |            |       |         | 1000   |
| Dense（输出层） |           |            |       |         | 30     |

```python
def myModel(width,height,channel,classes):
    inpt = Input(shape=(width, height, channel))
    # layer 1
    x = Conv2d_BN(x=inpt, nb_filter=32, kernel_size=(4,4), strides=(1,1), padding='same', name='layer1_1')
    x = Conv2d_BN(x=x, nb_filter=32, kernel_size=(4,4), strides=(1,1), padding='same', name='layer1_2')
    x = MaxPooling2D(pool_size=(2, 2), strides=(2, 2), padding='valid')(x)

    # layer 2
    x = Conv2d_BN(x=x, nb_filter=64, kernel_size=(4,4), strides=(1,1), padding='same', name='layer2_1')
    x = Conv2d_BN(x=x, nb_filter=64, kernel_size=(4,4), strides=(1,1), padding='same', name='layer2_2')
    x = MaxPooling2D(pool_size=(2, 2), strides=(2, 2), padding='valid')(x)

    # layer 3
    x = Conv2d_BN(x=x, nb_filter=96, kernel_size=(4,4), strides=(1,1), padding='same', name='layer3_1')
    x = Conv2d_BN(x=x, nb_filter=96, kernel_size=(4,4), strides=(1,1), padding='same', name='layer3_2')
    x = MaxPooling2D(pool_size=(2, 2), strides=(2, 2), padding='valid')(x)

    # layer 4
    x = Conv2d_BN(x=x, nb_filter=128, kernel_size=(4,4), strides=(1,1), padding='same', name='layer4_1')
    x = Conv2d_BN(x=x, nb_filter=128, kernel_size=(4,4), strides=(1,1), padding='same', name='layer4_2')
    x = MaxPooling2D(pool_size=(2, 2), strides=(2, 2), padding='valid')(x)

    # layer 5
    x = Conv2d_BN(x=x, nb_filter=256, kernel_size=(4,4), strides=(1,1), padding='same', name='layer5_1')
    x = Conv2d_BN(x=x, nb_filter=256, kernel_size=(4,4), strides=(1,1), padding='same', name='layer5_2')
    x = MaxPooling2D(pool_size=(2, 2), strides=(2, 2), padding='valid')(x)

    # layer 6
    x = Conv2d_BN(x=x, nb_filter=512, kernel_size=(4,4), strides=(1,1), padding='same', name='layer6_1')
    x = Conv2d_BN(x=x, nb_filter=512, kernel_size=(4,4), strides=(1,1), padding='same', name='layer6_2')
    x = AveragePooling2D(pool_size=(2, 2), strides=(2, 2), padding='valid')(x)

    # fullyconnected layer
    x = Flatten()(x)
    x = Dense(1000, activation='relu')(x)
    x = Dropout(0.1)(x)
    x = Dense(classes)(x)

    model = Model(inputs=inpt, outputs=x)
    return model
```

最终结果：

![](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/6/loss5.png)

左边为训练集loss曲线，右边为测试集loss曲线。

测试集有轻微的抖动，其它正常，在35个epochs后趋于收敛。

最终验证集上的loss为***1.88821242***。

综上：

|       | 模型大小 | RMSE       |
| ----- | -------- | ---------- |
| (2,2) | 20.9M    | 1.82733778 |
| (3,3) | 41.6M    | 1.80527330 |
| (4,4) | 70.6M    | 1.88821242 |

可以看到 (3,3) 的卷积核大小最合适，大的卷积核会使得参数量加倍。

#### 3. 是否使用偏置向量

##### （1）use_bias = False

每一个卷积层不使用偏置向量

参数：

> epochs: 100
>
> batch_size: 32
>
> dropout_rate: 0.1
>
> use_bias = False
>
> optimizer: RMSprop(参数为默认值lr=0.001, rho=0.9, epsilon=None, decay=0.0)

模型：

|                 | 通道数    | 卷积核大小 | 步长  | padding | 节点数 |
| --------------- | --------- | ---------- | ----- | ------- | ------ |
| layer1/layer1_1 | 1==>32    | (3,3)      | (1,1) | same    |        |
| layer1/layer1_2 | 32==>32   | (3,3)      | (1,1) | same    |        |
| MaxPooling      | 32==>32   | (2,2)      | (2,2) | valid   |        |
| layer2/layer2_1 | 32==>64   | (3,3)      | (1,1) | same    |        |
| layer2/layer2_2 | 64==>64   | (3,3)      | (1,1) | same    |        |
| MaxPooling      | 64==>64   | (2,2)      | (2,2) | valid   |        |
| layer3/layer3_1 | 64==>96   | (3,3)      | (1,1) | same    |        |
| layer3/layer3_2 | 96=>96    | (3,3)      | (1,1) | same    |        |
| MaxPooling      | 96==>96   | (2,2)      | (2,2) | valid   |        |
| layer4/layer4_1 | 96==>128  | (3,3)      | (1,1) | same    |        |
| layer4/layer4_2 | 128==>128 | (3,3)      | (1,1) | same    |        |
| MaxPooling      | 128==>128 | (2,2)      | (2,2) | valid   |        |
| layer5/layer5_1 | 128==>256 | (3,3)      | (1,1) | same    |        |
| layer5/layer5_2 | 256==>256 | (3,3)      | (1,1) | same    |        |
| MaxPooling      | 256==>256 | (2,2)      | (2,2) | valid   |        |
| layer6_1        | 256==>512 | (3,3)      | (1,1) | same    |        |
| layer6_2        | 512==>512 | (3,3)      | (1,1) | same    |        |
| AveragePooling  | 512==>512 | (2,2)      | (2,2) | valid   |        |
| Dense（隐藏层） |           |            |       |         | 1000   |
| Dense（输出层） |           |            |       |         | 30     |

```python
def Conv2d_BN(x, nb_filter, kernel_size, strides=(1, 1), padding='same', name=None):
    if name is not None:
        bn_name = name + '_bn'
        conv_name = name + '_conv'
    else:
        bn_name = None
        conv_name = None

    x = Conv2D(nb_filter, kernel_size, padding=padding, use_bias=False, strides=strides, kernel_initializer='glorot_uniform', name=conv_name)(x)
    x = LeakyReLU(alpha=0.1)(x)
    x = BatchNormalization(axis=3, name=bn_name)(x)
    return x
```

最终结果：

![](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/6/loss6.png)

左边为训练集的loss曲线，右边为验证集的loss曲线。

训练集在40个epochs后就收敛了，而验证集前期波动较大，60个epochs后趋于收敛。

最终验证集的loss为***1.82598148***。

综上：

|                | 模型大小 | RMSE       |
| -------------- | -------- | ---------- |
| use_bias=False | 41.6M    | 1.82598148 |
| use_bias=True  | 41.6M    | 1.80527330 |

两个模型基本一样大，但是结果却有差别。可见用偏置向量会好一点。

#### 4. 权值初始化

​	之前默认用的`glorot_uniform`， Xavier 均匀分布初始化器。它从 [-limit，limit] 中的均匀分布中抽取样本， 其中 `limit` 是 `sqrt(6 / (fan_in + fan_out))`， `fan_in` 是权值张量中的输入单位的数量， `fan_out` 是权值张量中的输出单位的数量。

##### （1）Ones

​	将所有权值设为1。

结果：

![](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/6/loss8.png)

左边为训练集的loss变化曲线，右边为验证集的loss变化曲线。

可以看到验证集除了有一个抖动，其它都很平滑。初始的loss非常大，之后逐渐下降。

最终验证集上的loss为***3.37461251***。

##### （2）RandomNormal

​	按照正态分布生成随机张量的初始化器。

结果：

![](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/6/loss9.png)

左边为训练集loss曲线，右边为测试集loss曲线。

初始的loss很小，很快就下降趋于收敛。

最终验证集上的loss为***1.82365545***。

##### （3）glorot_normal

​	Xavier 正态分布初始化器。它从以 0 为中心，标准差为 `stddev = sqrt(2 / (fan_in + fan_out))` 的截断正态分布中抽取样本， 其中 `fan_in` 是权值张量中的输入单位的数量， `fan_out` 是权值张量中的输出单位的数量。

结果：

![](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/6/loss7.png)

左边为训练集的loss曲线，右边为验证集的loss曲线。

训练集平滑，在30个epochs后趋于收敛，验证集抖动，60个epochs后才趋于收敛。初始的loss不大，下降也很快。

最终验证集上的loss为***1.79378161***。

这里我在本地的结果达到了新高，但是榜上并没有变化。

综上：

|                | RMSE       |
| -------------- | ---------- |
| Ones           | 3.37461251 |
| RandomNormal   | 1.82365545 |
| glorot_normal  | 1.79378161 |
| glorot_uniform | 1.80527330 |

不同的权值初始化器对训练收敛速度影响很大，并且像ones这种都初始为1，很有可能陷入局部最优，导致最终的loss很大。

#### 5. batch_size大小

##### （1）8

结果：

![](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/6/loss9.png)

左边为训练集的loss曲线，右边为验证集的loss曲线。

可以看到验证集上有轻微的抖动。

最终验证集上的loss为***1.84245861***。

##### （2）16

结果：

![](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/6/loss11.png)

左边为训练集loss曲线，右边为验证集loss曲线。

最终验证集上的loss为***1.80412955***。

##### （3）64

结果：

![](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/6/loss12.png)

验证集最初的loss变化存在抖动，而后很快就趋于收敛。

最终验证集上的loss为***1.79907260***。

##### （4）128

结果：

![](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/6/loss13.png)

左边为训练集loss曲线，右边为验证集loss曲线。

最终验证集上的loss为***1.85479109***。

综上：

|      | RMSE       |
| ---- | ---------- |
| 8    | 1.84245861 |
| 16   | 1.80412955 |
| 32   | 1.80527330 |
| 64   | 1.79907260 |
| 128  | 1.85479109 |

本地最优结果是64的batch_size，但是榜上最好是32。所以我还是选择batch_size为32。

#### 6. optimizer选择

##### （1）Adam

![](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/6/loss14.png)

左边为训练集loss曲线，右边为验证集loss曲线。

很正常，比较平稳。

最终验证集上的loss为***1.83405668***。

##### （2）sgd

![](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/6/loss15.png)

左边为训练集loss曲线，右边为验证集loss曲线。

最终验证集上的loss为***2.76584201***。

##### （3）Adadelta

![](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/6/loss16.png)

左边为训练集loss曲线，右边为验证集loss曲线。

最终验证集上的loss为***2.12262922***。

综上：

|          | RMSE       |
| -------- | ---------- |
| Adam     | 1.83405668 |
| sgd      | 2.76584201 |
| rmsprop  | 1.80527330 |
| adadelta | 2.12262922 |

所以rmsprop优化器得到的结果最好。

#### 7. resnet结构

一个残差架构如下：

![](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/6/res.png)

输入数据经过两个卷积操作后，与输入值做加和，最终输出。这样可以保证学习到高级特征的同时，低级特征也不会损失。

```python
def identity_Block(inpt, nb_filter, kernel_size, strides=(1, 1), with_conv_shortcut=False):
    # 第一层卷积
    x = Conv2d_BN(inpt, nb_filter=nb_filter, kernel_size=kernel_size, strides=strides,padding='same')
    # 第二层卷积，之后不适用激活函数
    x = Conv2d_BN(x, nb_filter=nb_filter, kernel_size=kernel_size, activation=False, padding='same')
    # 满足条件让输入通道数保持相同
    if with_conv_shortcut:
        shortcut = Conv2d_BN(inpt, nb_filter=nb_filter, strides=strides, kernel_size=kernel_size, activation=False)
        # 加和
        x = add([x, shortcut])
        x = LeakyReLU(alpha=0.1)(x)
        return x
    else:
        # 否则直接相加
        x = add([x, inpt])
        x = LeakyReLU(alpha=0.1)(x)
        return x
```

```python
def resnet(width,height,channel,classes):
    inpt = Input(shape=(width, height, channel))
    # x = ZeroPadding2D((2, 2))(inpt)

    #conv1
    x = Conv2d_BN(inpt, nb_filter=32, kernel_size=(3, 3), strides=(1, 1), padding='same')
    x = Conv2d_BN(x, nb_filter=32, kernel_size=(3, 3), strides=(1, 1), padding='same')
    x = MaxPooling2D(pool_size=(3, 3), strides=(2, 2), padding='valid')(x)

    #conv2_x
    x = identity_Block(x, nb_filter=64, kernel_size=(3, 3), strides=(1, 1), with_conv_shortcut=True)
    x = MaxPooling2D(pool_size=(3, 3), strides=(2, 2), padding='valid')(x)

    #conv3_x
    x = identity_Block(x, nb_filter=96, kernel_size=(3, 3), strides=(1, 1), with_conv_shortcut=True)
    x = MaxPooling2D(pool_size=(3, 3), strides=(2, 2), padding='valid')(x)

    #conv4_x
    x = identity_Block(x, nb_filter=128, kernel_size=(3, 3), strides=(1, 1), with_conv_shortcut=True)
    x = MaxPooling2D(pool_size=(3, 3), strides=(2, 2), padding='valid')(x)

    #conv5_x
    x = identity_Block(x, nb_filter=256, kernel_size=(3, 3), strides=(1, 1), with_conv_shortcut=True)
    x = AveragePooling2D(pool_size=(3, 3), strides=(2, 2), padding='valid')(x)
    
    x = Flatten()(x)
    x = Dense(1000, activation='relu')(x)
    x = Dropout(0.15)(x)
    x = Dense(classes)(x)

    model = Model(inputs=inpt, outputs=x)
    return model
```

这里我用了四个残差块，共10个卷积层。

结果：

![](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/6/loss17.png)

左边为训练集的loss曲线，右边为测试集的loss曲线。

最终验证集上的loss为***1.73696040***。是我所有实验中最优的结果。

### 五. 最终结果

![](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/6/2.png)

这是我的模型跑的结果截图，loss计算的是mse，归一化后所以为这么小。

* ground truth如下：

![](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/6/12.png)

* 预测结果如下：

![12](https://cdn.jsdelivr.net/gh/darkseidddddd/CDN@4.0/MachineLearning/6/7.png)

蓝框标注出了差别。数据集标注的就有很大偏差，得到的模型肯定也会有偏差。

### 六. 问题及解决

#### 1. 测试集和训练集分布不同

​	我在本地跑出更好的结果，提交上去发现并没有上升。而有时候结果不好，提交后反而上升了，本地我也没有过拟合，仿佛测试集和训练集两个分布不是完全相同的。

#### 2. 模型大小

​	当我只有四层卷积层时，模型大小达到了500M，而深度增加模型大小反而下降。到了12层的时候为最小，然后我再增加模型深度，大小又会增加。可能是我没加正则化项，使得权值没有约束，在浅层的时候权值很大，从而保存得到的模型大小也很大。

#### 3. 数据集划分

​	我尝试了很多不同的随机数种子，按照相同的比例划分数据集，相同的模型最终在验证集上得到的结果也不尽相同，可能数据量太小，以至于划分出两种不同分布的训练集和验证集。



