import pandas as pd
import numpy as np
from keras.models import load_model
from prepare_data import load_data
from sklearn.model_selection import train_test_split
# import os
# os.environ['CUDA_VISIABLE_DIVICES']='1'

def export(pred_points, filename):
    """
    :param pred_points: result from your model use test.csv
    :return:
    """
    submission_data = pd.DataFrame(pred_points)
    submission_data.to_csv(filename, index=False)

# 预测结果
def predict(model_path, res_path):
    X, y = load_data(test=False)
    x_train,x_val,y_train,y_val = train_test_split(X,y,random_state = 69,test_size = 0.1)
    model = load_model(model_path)
    y_pre = model.predict(x_val)
    loss = np.sqrt(np.mean(np.square(y_pre - y_val)))*48
    print('best val loss: %.8f' %loss)
    # model = load_model(model_path)
    x_test = load_data(test=True)
    res = model.predict(x_test)*48+48
    export(res, res_path)

if __name__ == '__main__':
    # 导入模型，保存文件
    predict(model_path='best_weights.h5',res_path='res.csv') 
