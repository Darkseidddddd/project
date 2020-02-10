import pandas as pd
import numpy as np
import keras
import os
from sklearn.model_selection import train_test_split
from prepare_data import load_data

from keras import optimizers
from keras.layers.advanced_activations import LeakyReLU
from keras.models import Sequential, Model
from keras.layers import Input, AveragePooling2D, MaxPooling2D, BatchNormalization, Flatten, Dense, Dropout, Conv2D,MaxPool2D, add
os.environ['CUDA_VISIABLE_DEVICES'] = '0,1'
def Conv2d_BN(x, nb_filter, kernel_size, strides=(1, 1), padding='same', activation=True, name=None):
    if name is not None:
        bn_name = name + '_bn'
        conv_name = name + '_conv'
    else:
        bn_name = None
        conv_name = None

    x = Conv2D(nb_filter, kernel_size, padding=padding, use_bias=True, strides=strides, name=conv_name)(x)
    if activation:
        x = LeakyReLU(alpha=0.1)(x)
    x = BatchNormalization(axis=3, name=bn_name)(x)
    return x

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

def resnet(width,height,channel,classes):
    inpt = Input(shape=(width, height, channel))
    # x = ZeroPadding2D((2, 2))(inpt)

    #conv1
    x = Conv2d_BN(inpt, nb_filter=32, kernel_size=(3, 3), strides=(1, 1), padding='same')
    x = Conv2d_BN(x, nb_filter=32, kernel_size=(3, 3), strides=(1, 1), padding='same')
    x = MaxPooling2D(pool_size=(3, 3), strides=(2, 2), padding='valid')(x)

    #conv2_x
    x = identity_Block(x, nb_filter=64, kernel_size=(3, 3), strides=(1, 1), with_conv_shortcut=True)
    # x = identity_Block(x, nb_filter=64, kernel_size=(3, 3))
    x = MaxPooling2D(pool_size=(3, 3), strides=(2, 2), padding='valid')(x)

    #conv3_x
    x = identity_Block(x, nb_filter=96, kernel_size=(3, 3), strides=(1, 1), with_conv_shortcut=True)
    # x = identity_Block(x, nb_filter=96, kernel_size=(3, 3))
    # x = identity_Block(x, nb_filter=128, kernel_size=(3, 3))
    x = MaxPooling2D(pool_size=(3, 3), strides=(2, 2), padding='valid')(x)

    #conv4_x
    x = identity_Block(x, nb_filter=128, kernel_size=(3, 3), strides=(1, 1), with_conv_shortcut=True)
    x = MaxPooling2D(pool_size=(3, 3), strides=(2, 2), padding='valid')(x)
    # x = identity_Block(x, nb_filter=128, kernel_size=(3, 3))
    # x = identity_Block(x, nb_filter=256, kernel_size=(3, 3))

    #conv5_x
    x = identity_Block(x, nb_filter=256, kernel_size=(3, 3), strides=(1, 1), with_conv_shortcut=True)
    # x = identity_Block(x, nb_filter=512, kernel_size=(3, 3))
    # x = identity_Block(x, nb_filter=512, kernel_size=(3, 3))
    x = AveragePooling2D(pool_size=(3, 3), strides=(2, 2), padding='valid')(x)
    x = Flatten()(x)
    x = Dense(1000, activation='relu')(x)
    x = Dropout(0.15)(x)
    x = Dense(classes)(x)

    model = Model(inputs=inpt, outputs=x)
    return model

# create your model here
def myModel(width,height,channel,classes):
    inpt = Input(shape=(width, height, channel))
    # layer 1
    x = Conv2d_BN(x=inpt, nb_filter=32, kernel_size=(3,3), strides=(1,1), padding='same', name='layer1_1')
    x = Conv2d_BN(x=x, nb_filter=32, kernel_size=(3,3), strides=(1,1), padding='same', name='layer1_2')
    # x = Conv2d_BN(x=x, nb_filter=48, kernel_size=(3,3), strides=(1,1), padding='same', name='layer1_3')
    x = MaxPooling2D(pool_size=(2, 2), strides=(2, 2), padding='valid')(x)

    # layer 2
    x = Conv2d_BN(x=x, nb_filter=64, kernel_size=(3,3), strides=(1,1), padding='same', name='layer2_1')
    x = Conv2d_BN(x=x, nb_filter=64, kernel_size=(3,3), strides=(1,1), padding='same', name='layer2_2')
    # x = Conv2d_BN(x=x, nb_filter=64, kernel_size=(3,3), strides=(1,1), padding='same', name='layer2_3')
    # x = Conv2d_BN(x=x, nb_filter=64, kernel_size=(3,3), strides=(1,1), padding='same', name='layer2_4')
    x = MaxPooling2D(pool_size=(2, 2), strides=(2, 2), padding='valid')(x)

    # layer 3
    x = Conv2d_BN(x=x, nb_filter=96, kernel_size=(3,3), strides=(1,1), padding='same', name='layer3_1')
    x = Conv2d_BN(x=x, nb_filter=96, kernel_size=(3,3), strides=(1,1), padding='same', name='layer3_2')
    # x = Conv2d_BN(x=x, nb_filter=96, kernel_size=(3,3), strides=(1,1), padding='same', name='layer3_3')
    x = MaxPooling2D(pool_size=(2, 2), strides=(2, 2), padding='valid')(x)

    # layer 4
    x = Conv2d_BN(x=x, nb_filter=128, kernel_size=(3,3), strides=(1,1), padding='same', name='layer4_1')
    x = Conv2d_BN(x=x, nb_filter=128, kernel_size=(3,3), strides=(1,1), padding='same', name='layer4_2')
    # x = Conv2d_BN(x=x, nb_filter=128, kernel_size=(3,3), strides=(1,1), padding='same', name='layer4_3')
    x = MaxPooling2D(pool_size=(2, 2), strides=(2, 2), padding='valid')(x)

    # layer 5
    x = Conv2d_BN(x=x, nb_filter=256, kernel_size=(3,3), strides=(1,1), padding='same', name='layer5_1')
    x = Conv2d_BN(x=x, nb_filter=256, kernel_size=(3,3), strides=(1,1), padding='same', name='layer5_2')
    # x = Conv2d_BN(x=x, nb_filter=256, kernel_size=(2,2), strides=(1,1), padding='same', name='layer5_3')
    x = MaxPooling2D(pool_size=(2, 2), strides=(2, 2), padding='valid')(x)

    # layer 6
    x = Conv2d_BN(x=x, nb_filter=512, kernel_size=(3,3), strides=(1,1), padding='same', name='layer6_1')
    x = Conv2d_BN(x=x, nb_filter=512, kernel_size=(3,3), strides=(1,1), padding='same', name='layer6_2')
    # x = Conv2d_BN(x=x, nb_filter=512, kernel_size=(2,2), strides=(1,1), padding='same', name='layer6_3')
    x = AveragePooling2D(pool_size=(2, 2), strides=(2, 2), padding='valid')(x)
    # x = AveragePooling2D(pool_size=(2, 2), strides=(2, 2), padding='valid')(x)
    
    # layer 7
    # x = Conv2d_BN(x=x, nb_filter=512, kernel_size=(2,2), strides=(1,1), padding='same', name='layer7_1')
    # x = Conv2d_BN(x=x, nb_filter=512, kernel_size=(2,2), strides=(1,1), padding='same', name='layer7_2')
    # x = AveragePooling2D(pool_size=(2, 2), strides=(1, 1), padding='valid')(x) 
   
    # fullyconnected layer
    x = Flatten()(x)
    # x = Dense(512, activation='relu')(x)
    # x = Dropout(0.1)(x)
    x = Dense(1000, activation='relu')(x)
    x = Dropout(0.15)(x)
    # x = Dense(512, activation='relu')(x)
    # x = Dropout(0.15)(x)
    x = Dense(classes)(x)

    model = Model(inputs=inpt, outputs=x)
    return model

def train(epochs=100, batch_size=48):
    X, y = load_data(False)
    x_train,x_test,y_train,y_test = train_test_split(X,y,random_state = 69,test_size = 0.1)
    model = myModel(96,96,1,30)
    # model = resnet(96, 96, 1, 30)
    # rmsprop = optimizers.RMSprop(decay=0.00001)
    model.compile(optimizer = 'rmsprop',loss = 'mean_squared_error',  metrics = ['acc'])
    # 保存最优模型
    checkpoint = keras.callbacks.ModelCheckpoint('model/best_weights.h5',monitor='val_loss',save_best_only=True)
    # 15个epoch没变化时停止训练
    earlystop = keras.callbacks.EarlyStopping(monitor='val_loss',patience=15)
    # 保存loss曲线和精度曲线
    tb = keras.callbacks.TensorBoard(log_dir='model/log/')
    # 更新lr的回调函数
    updatelr = keras.callbacks.ReduceLROnPlateau(monitor='val_loss', factor=0.5, patience=10, min_lr = 0.0002)
    callbacks_list = [checkpoint, earlystop, tb, updatelr]
    model.fit(x_train,y_train,batch_size=batch_size, epochs=epochs, validation_data=(x_test,y_test), callbacks=callbacks_list)
    # model.save('model_5/weights.h5')

if __name__ == '__main__':
    train(epochs=100, batch_size=32)
