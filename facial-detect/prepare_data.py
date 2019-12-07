import numpy as np
import pandas as pd

def load_data():
    print('load data')
    Train_Dir = 'train.csv'
    # Test_Dir = './data/test.csv'
    train_data = pd.read_csv(Train_Dir)
    # test_data = pd.read_csv(Test_Dir)

    # use the previous value to fill the missing value
    train_data.fillna(method='ffill', inplace=True)

    # preparing training data
    imga = []
    for i in range(len(train_data)):
        img = train_data['Image'][i].split(' ')
        img = ['0' if x == '' else x for x in img]
        imga.append(img)

    image_list = np.array(imga, dtype='float')
    X_train = image_list.reshape(-1, 96, 96, 1)

    # preparing training label
    training = train_data.drop('Image', axis=1)
    y_train = []
    for i in range(len(train_data)):
        y = training.iloc[i, 1:]
        y_train.append(y)
    y_train = np.array(y_train, dtype='float')

    # preparing test data
    # timga = []
    # for i in range(len(test_data)):
    #     timg = test_data['Image'][i].split(' ')
    #     timg = ['0' if x == '' else x for x in timg]
    #     timga.append(timg)
    # timage_list = np.array(timga, dtype='float')
    # X_test = timage_list.reshape(-1, 96, 96, 1)
    print('done')
    return X_train, y_train



