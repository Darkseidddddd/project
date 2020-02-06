#### 背景：

* 考虑到网上销售的产品数量，产品定价在规模上变得更加困难。服装有很强的季节性定价趋势，受品牌影响很大，而电子产品价格根据产品规格波动。如何根据以往信息合理定价，有效地帮助商家进行商品的销售是一个十分有意义的问题。

#### 分析目标：

通过给出的商品描述、商品类别和品牌信息，并结合训练数据种的商品价格来给新商品顶价格。Eg：

|商品名称|品牌名称|商品描述| 商品类别 |
| :------------: | :------------: | :---------------------------------------: | :-------------------------------------------: |
|       美杜莎羊皮飞行员夹克外套男       |  Versace   | 1、时尚衣领设计，经典百搭，休闲舒适；2、简约袖口设计；细节尽显品质；3、精湛的制作工艺，细节彰显品质；4、精心挑选高品质面料，手感好，面料舒适 |   服饰   |
| 新款秋冬季男士韩版潮流连帽帅气夹克衣服 | 美特斯邦威 |     一件精心设计、不挑身材的保暖夹克。舒适，时尚，有型。     |   服饰   |

显然Versace的衣服价格上应该远高于美特斯邦威的衣服，并且在商品描述中，可以发现两者描述有细微差别。

>  本project旨在对文本信息进行分析，提取文本信息中重要的信息，推导出和价格之间的潜在关系

#### 数据字段分析

|      字段名       |       含义       |
| :---------------: | :--------------: |
| train_id/test_id  |   商品的序号值   |
|       name        |     商品名称     |
|   category_name   |   商品所属类别   |
| item_condition_id | 商品当前是否有货 |
|    brand_name     |     商品品牌     |
|     shipping      |     是否包邮     |
| item_description  |     商品描述     |
|       price       |       商品       |

#### 数据集

* train.csv 训练集（含price）
* test.csv 测试集（不含price）
* label_test.csv 测试集中对应的price
* f_test.csv 最终的评价数据集（不含price）

#### 评价指标

评价使用的是 Mean Squared Logarithmic Error: 计算方式如下
$$
MSLE=\frac{1}{n}\sum^n_{i=1}(log(p_i+1)-log(\alpha_i+1))^2
$$
其中 $$n$$ 代表测试集的样本数；$$p_i$$ 代表的是预测的商品的价格值；$$\alpha_i$$ 代表实际的销售价格

---

---

#### 一. 数据集

|      字段名       |       含义       |
| :---------------: | :--------------: |
|       name        |     商品名称     |
|   category_name   |   商品所属类别   |
| item_condition_id | 商品当前是否有货 |
|    brand_name     |     商品品牌     |
|     shipping      |     是否包邮     |
| item_description  |     商品描述     |
|       price       |     商品价格     |

训练集：train.csv

最终要测试的数据：test.csv

这里我们用留出法，将train.csv分成训练集 : 测试集 = 7 : 3

#### 二. 数据分析及预处理

```python
# 读取数据
data = pd.read_csv('data/train.csv', sep='\t')
# 查看数据的统计信息
data.describe()
```

<img src="D:\learn\数据科学导论\大作业\12.png" style="zoom:80%;" />

```python
# 查看缺失值
data.isnull().any()
```

<img src="D:\learn\数据科学导论\大作业\10.png" style="zoom:80%;" />

```python
data.isnull().sum()
```

<img src="D:\learn\数据科学导论\大作业\11.png" style="zoom:80%;" />

可以看到其中**category_name**和**brand_name**这两个特征存在缺失值，并且**brand_name**缺失值的数量比较多。

```python
# 特征预处理
def featureProcessing(df):
    # 删除不用的数据
    df = df.drop(['price', 'train_id'], axis=1)
    # 处理缺失值
    df['category_name'] = df['category_name'].fillna('No/No/No').astype(str)
    df['brand_name'] = df['brand_name'].fillna('missing').astype(str)
    df['item_description'] = df['item_description'].fillna('No')
    # 将int型转为str类型
    df['shipping'] = df['shipping'].astype(str)
    df['item_condition_id'] = df['item_condition_id'].astype(str)

    return df
df = featureProcessing(data)
df.head()
```

![](D:\learn\数据科学导论\大作业\13.png)

```python
# 绘制price柱形图
width = [50, 100, 150, 200, 250, 300, 350]
sns.distplot(train_data['price'], color = 'g', rug = True, bins = [w for w in width])
```

<img src="D:\learn\数据科学导论\大作业\15.png" style="zoom:80%;" />

可以看到**price**的频率分布。

```python
# 利用原始数据的int类型画图
# 统计item_condition不同量出现的次数
ax = sns.countplot('item_condition_id', data = df)
ax.set_xticklabels(ax.get_xticklabels(), rotation = 40, ha = "right")
ax.set_title('Count of each item condition')
```

<img src="D:\learn\数据科学导论\大作业\14.png" style="zoom:80%;" />

可以看到为取值为1的分布最多，取值为4，5的相对较少。

```python
# 经过np.log压缩后绘制price柱形图
plt.xlabel('log(price+1)', fontsize = 12)
plt.title('Log Price Distribution', fontsize = 12)
np.log(train_data['price'] + 1).plot.hist(bins = 50, figsize = (8, 4), edgecolor = 'white', color = 'g')
```

<img src="D:\learn\数据科学导论\大作业\16.png" style="zoom:80%;" />

经过log处理后的价格分布情况。

```python
# 输出列类型
print(df.astype('object').describe().transpose())
```

<img src="D:\learn\数据科学导论\大作业\17.png" style="zoom:80%;" />

可以看到每个特征的具体信息。

```python
def split_cat(text):
    return text.split("/")
df['cat1'], df['cat2'], df['cat3'] = \
zip(*df['category_name'].apply(lambda x: split_cat(x)))

# 查看切分后的cat1的取值的概率
print(df['cat1'].value_counts() / len(df['cat1']))
```

<img src="D:\learn\数据科学导论\大作业\18.png" style="zoom:80%;" />

```python
# Category切分之后的第一部分的出现次数最多的前10个
plt.figure(figsize = (17, 10))
sns.countplot(y = df['cat1'], order = df['cat1'].value_counts().index, orient = 'v')
plt.title('Top 10 Cat1 Categories', fontsize = 25)
plt.ylabel('Cat1 Category', fontsize = 20)
plt.xlabel('Number of Items')
```

![](D:\learn\数据科学导论\大作业\22.png)

```python
# 通过cat1绘制二元特征shipping的柱形分布图
ax = sns.countplot(x = "cat1", hue = "shipping", data = df, palette = "Set3")
ax.set_xticklabels(ax.get_xticklabels(), rotation = 40, ha = "right")
ax.set_title('Count of shipping by cat1')
```

<img src="D:\learn\数据科学导论\大作业\19.png" style="zoom:80%;" />

挑选**cat1**和**shipping**来看一看分布情况。

```python
# 通过shipping绘制price的柱形分布图，查看shipping和price的相关性
shipping_by_buyer = data[data['shipping'] == 0]['price']
shipping_by_seller = data[data['shipping'] == 1]['price']
fig, ax = plt.subplots(figsize = (18, 8))
ax.hist(shipping_by_seller, color = 'g', alpha = 1.0, bins = 50, range = [0, 100],label = 'Price when Seller pays Shipping')
ax.hist(shipping_by_buyer, color = 'y', alpha = 0.7, bins = 50, range = [0, 100],label = 'Price when Buyer pays Shipping')
plt.xlabel('price', fontsize = 12)
plt.ylabel('frequency', fontsize = 12)
plt.title('Price Distribution by Shipping Type', fontsize = 15)
plt.tick_params(labelsize = 12)
plt.legend()
```

<img src="D:\learn\数据科学导论\大作业\20.png" style="zoom:80%;" />

可以看到包邮时整体平均价格会相对低一些。

```python
# Brand按照价格排序的前20个
top_20_exp_brand = pd.DataFrame(train_data.groupby(['brand_name'],as_index = True).std()['price'].sort_values(ascending = False)[0 : 20]).reset_index()
ax = sns.barplot(x = "brand_name", y = "price", data = top_20_exp_brand)
ax.set_xticklabels(ax.get_xticklabels(),rotation = 90)
ax.set_title('Top 20 Brand', fontsize = 15)
```

<img src="D:\learn\数据科学导论\大作业\21.png" style="zoom:80%;" />



可以看到商标对价格也有很大的影响。

#### 三. 特征选择

考虑到最初的六个特征并不能很好地表达模型以及做出很好的预测，所以我们调试了无数次。最终得到如下的特征组合。

* **name**和**item_description**

对于能很好的代表一个商品的特征，我们初步分析有**name**和**item_description**这两个特征，所以我们分别去掉这两个特征，在岭回归模型上，得到了一个更加糟糕的结果。于是我们得出一个结论——这两个特征很有用。

* **brand_name**和**name**

对于单独的商标，例如Nike，能表达的商品信息比较宽泛，价格也参差不齐。同理，对于单独的商品名称，例如××T-shirt Medium，也是如此。但是如果将商标和名称合在一起，可能就会更好地表达出这件商品的特征，例如Nike black T-shirt Medium，它将价格区间变得更小，即更具体，这可能就是我们需要的特征。

~~~python
df['brand_name_name'] = df['brand_name'].fillna('') + ' ' + df['name'].fillna('')
~~~

![](D:\learn\数据科学导论\大作业\2.png)

* **name**和**cat2**

首先我们先将**category_name**按照'/'分隔切开，新生成三列类别特征，分别是**cat1，cat2，cat3**

```python
def split_cat(text):
    return text.split("/")
df['cat1'], df['cat2'], df['cat3'] = \
zip(*df['category_name'].apply(lambda x: split_cat(x)))
```

![](D:\learn\数据科学导论\大作业\9.png)

```python
print('cat1: %d, cat2: %d, cat3: %d' %(cat1.nunique(), cat2.nunique(), cat3.nunique()))
```

> cat1: 11, cat2: 114, cat3: 816

其中**cat1**有11个不同的类，**cat2**有114个不同的类，**cat3**有816个不同的类。

由之前的分析，我们认为name和item_description非常重要，而要能表示一兼商品的价格，商品类别也很重要，所以在这个前提之下，我们分别融合了name和cat1，cat2，cat3，进行了试探，最终发现name和cat2的组合（或者name和cat3）的组合，使得最终结果能更加优化。

```python
df['name_cat1'] = df['name'].fillna('') + ' ' + df['cat1'].fillna('')
df['name_cat2'] = df['name'].fillna('') + ' ' + df['cat2'].fillna('')
df['name_cat3'] = df['name'].fillna('') + ' ' + df['cat3'].fillna('')
```

```python
df = df.drop(['name_cat1', 'name_cat3'])
```

![](D:\learn\数据科学导论\大作业\4.png)

* name，item_description和brand_name

对于上面已经用过的特征，不妨把item_description和name结合在一起，同时再加一个brand_name，这样获得的特征，又进一步提升了最后的准确率。

```python
df['text'] = df['item_description'].fillna('') + ' ' + df['name'].fillna('') + ' ' + df['brand_name'].fillna('')
```

![](D:\learn\数据科学导论\大作业\5.png)

* brand_name，cat23，id和shipping

所有特征中，表达能力最弱的就是**brand_name**，**condition_id**和**shipping**了，但是如果将它们拼接在一起，就会使它们的表达能力增强，同时，我们还加入了类别，总共重组了四个特征。

```python
df['bn_cat23_id_shipping'] = df['brand_name'] + df['cat23']+df['item_condition_id']+df['shipping']
```

![](D:\learn\数据科学导论\大作业\6.png)

于是，我们得到了我们想要的重组之后的特征组合。为了降低特征维度，我们试图寻找可以删减不用的特征。因为**text**这个特征在合并的时候，之间加了分隔符空格，再加上TfidfVectorizer会使得整个句子按照默认字符空格将所有单词分开，所以**text**实际上包含了**name**和**item_description**这两个特征。经过验证，在删掉这两个特征时，最终结果并没有太大的变化，但对于其它特征来说，删去则会使结果表现得更糟糕。最终，我们便确定了我们所需要的特征组合。

![](D:\learn\数据科学导论\大作业\7.png)

#### 四. 模型构建

##### 1. 岭回归模型

~~~python
from sklearn.linear_model import Ridge
def ridgeClassify(train_data, train_label):
    ridgeClf = Ridge(
        solver='auto',
        fit_intercept=True,
        alpha=3.5,
        max_iter=550,
        normalize=False,
        tol=0.01)
    # 训练
    ridgeClf.fit(train_data, train_label)
    return ridgeClf
~~~

##### 2. 神经网络模型

~~~python
import keras
from keras.models import Sequential
from keras.layers import Dense
from keras.wrappers.scikit_learn import KerasRegressor

# 定义模型
def regressor_model():
    model = Sequential()
    # 第一层，64个节点，随机初始化权重，激活函数为relu，输入维度为特征数量
    model.add(Dense(units = 64,kernel_initializer = 'uniform', activation = 'relu', input_dim = 449780))
    # 第二层，16个节点，激活函数为relu
    model.add(Dense(units = 16, kernel_initializer = 'uniform', activation = 'relu'))
    # 第三层，16个节点，激活函数为relu
    model.add(Dense(units = 16, kernel_initializer = 'uniform', activation = 'relu'))
    # 第四层，8个节点，激活函数为relu
    model.add(Dense(units = 8, kernel_initializer = 'uniform', activation = 'relu'))
    model.add(Dense(1, init='uniform'))
    # 编译模型，因为y_train已经log过，所以这里用mse评估函数，相当于最终的msle
    model.compile(loss='mse', optimizer='adam', metrics=['mse'])
    return model

from sklearn.pipeline import Pipeline

estimators = []
# 设置验证集，并在训练时输出
estimators.append(('mlp', KerasRegressor(build_fn= regressor_model, epochs=10, validation_data=(X_test, y_test),verbose=1)))
# 添加到pipeline
pipeline = Pipeline(estimators)

pipeline.fit(X_train,y_train)
~~~

##### 3. LightGBM

~~~python
import lightgbm as lgb
params = {
    'task': 'train',
    'boosting_type': 'gbdt',  # 设置提升类型为gbdt
    'objective': 'regression', # 目标函数
    'metric': {'l2','mse'},  # 评估函数mse
    'num_leaves': 31,   # 叶子节点数
    'learning_rate': 0.1,  # 学习速率
    'feature_fraction': 1, # 建树的特征选择比例
    'bagging_fraction': 0.9, # 建树的样本采样比例
    'bagging_freq': 5,  # k 意味着每 k 次迭代执行bagging
    'verbose': 1, # 显示信息
    'batch_size': 48
}

lgb_train = lgb.Dataset(X_train, y_train) # 将数据保存到LightGBM二进制文件将使加载更快
lgb_eval = lgb.Dataset(X_test, y_test, reference=lgb_train)  # 创建验证数据
gbm = lgb.train(params,lgb_train,num_boost_round=3000,valid_sets=lgb_eval,early_stopping_rounds=15) # 训练数据需要参数列，总共训练3000次，当连续15次不下降时退出训练
~~~

#### 五. 预测及结果

##### 1. 岭回归模型

```python
def ridgeClassify(train_data, train_label, alpha):
    ridgeClf = Ridge(
        solver='auto',
        fit_intercept=True,
        alpha=alpha,
        max_iter=550,
        normalize=False,
        tol=0.01)
    # 训练
    ridgeClf.fit(train_data, train_label)
    return ridgeClf

res_alpha = []
for alpha in [3,3.1,3.2,3.3,3.4,3.5,3.6,3.7,3.8,3.9,4]:
    ridgeClf = ridgeClassify(X_train, y_train, alpha)
# 结果预测
    test_price = ridgeClf.predict(X_test)
    msle = mean_squared_log_error(y_test, np.expm1(test_price))
    res_alpha.append(msle)
res_alpha

'''
def ridgeClassify(train_data, train_label,max_iter):
    ridgeClf = Ridge(
        solver='auto',
        fit_intercept=True,
        alpha=3.5,
        max_iter=max_iter,
        normalize=False,
        tol=0.01)
    # 训练
    ridgeClf.fit(train_data, train_label)
    return ridgeClf

res_iter = []
for iters in [400,450,500,550,600,650,700]:
    ridgeClf = ridgeClassify(X_train, y_train, iters)
# 结果预测
    test_price = ridgeClf.predict(X_test)
    msle = mean_squared_log_error(y_test, np.expm1(test_price))
    res_iter.append(msle)
'''
```

![](D:\learn\数据科学导论\大作业\28.png)

这里是我们测试的不同学习率对结果的影响，可以看到当alpha为3.3，3.4，3.5的时候，结果最好。

为了寻找最优的参数组合，我们还分别测试了不同的最大迭代次数以及不同的精度对结果的影响。

开始我们分别测试了学习率为0.001，0.01，0.05，0.1，1，3，5，7的各种不同情况，发现当学习率为3的时候，结果是最理想的。在这基础之上，之后我们又分别测试了alpha为区间[3,4]，间隔为0.1的所有不同取值，最终得到结果，发现当alpha为3.5的时候，能使我们训练出一个相对最好的模型。

接着，我们保持alpha不变，分别测试了max_iter为400，450，500，550，600，650，700的各种不同取值，最终得到结果，max_iter在以上区间内的取值并不会对模型产生太大的影响，所以我们取550为最终的最优参数。

##### 2. 神经网络模型

最初我们只设置了两层，第一层的神经元个数为8，第二层的神经元个数为4，激活函数为relu，epochs为5，得到如下的结果：

![](D:\learn\数据科学导论\大作业\26.png)

可以看到由于模型太过于简单，最终的效果并不好。

于是我们将两层扩充至三层，第一层的神经元个数为16，第二层的神经元个数为8，第三层神经元个数为4，激活函数为relu，epochs为5，得到如下结果：

![](D:\learn\数据科学导论\大作业\30.png)

可以看到第二个epoch就已经到了最优的结果了，所以证明模型还不够复杂，于是加下来我们又更改了模型参数。

最后我们扩充至四层模型，第一层到第四层的神经元个数分别为64，16，16，8，激活函数为relu，得到如下的结果：

<img src="D:\learn\数据科学导论\大作业\8.png" style="zoom:80%;" />

因为我们的特征维度太大，所以我们没有再复杂化整个模型，可以看到效果并没有岭回归好，并且训练速度也非常慢，在第一个epoch后就基本不会再提升了。最终我们放弃了这个模型。

##### 3. lightGBM

刚开始参数设置

<img src="D:\learn\数据科学导论\大作业\24.png" style="zoom:80%;" />

总共迭代2000次，最终结果如下：

<img src="D:\learn\数据科学导论\大作业\23.jpg" style="zoom:80%;" />

可以看到结果在0.2099的样子。

然后我们改变参数如下：

<img src="D:\learn\数据科学导论\大作业\25.png" style="zoom:80%;" />

即增大了叶子节点数，其它保持不变。

最终结果如下：

![](D:\learn\数据科学导论\大作业\27.png)

可以看到相对于上面的结果，叶子节点数增加了一倍，而最终结果只降低了0.004。还是没有岭回归得到的效果好。所以我们放弃了这个模型。

最终，我们在岭回归上达到了0.197的msle，这也是我们在划分方式为7 : 3训练集上的最终结果。

### 六. 遇到的问题

##### 1. 清洗**item_description**

```python
from nltk.tokenize import sent_tokenize
import re
import string
from nltk.corpus import stopwords
stop = stopwords.words('english')
def tokenize(text):
    # 将数字，换行，\t等全部替换为空格
    regex = re.compile('[' +re.escape(string.punctuation) + '0-9\\r\\t\\n]')
    text = regex.sub(" ", text)
        
    tokens_ = [word_tokenize(s) for s in sent_tokenize(text)]
    tokens = []
    for token_by_sent in tokens_:
        tokens += token_by_sent
    # 全部单词小写并去掉停用词
    tokens = list(filter(lambda t: t.lower() not in stop, tokens))
    filtered_tokens = [w for w in tokens if re.search('[a-zA-Z]', w)]
    # 去掉长度小于3的单词
    filtered_tokens = [w.lower() for w in filtered_tokens if len(w)>=3]
   
    return ' '.join(filtered_tokens)
    
df['tokens'] = df['item_description'].map(tokenize)
```

这里我们通过tokenize函数将**item_description**特征做了一些清洗，去掉了一些我们认为没用的信息。但是通过对比实验，我们发现新的**tokens**特征并没有原来的**item_description**特征好，所以我们放弃了这个处理，保持原来的特征。

##### 2. 清洗奇异值

```python
m = data['price'].mean()
std = data['price'].std()
error = data[np.abs(data['price']-m) > 3*std]
correct = data[np.abs(data['price']-m) <= 3*std]
data = data.drop(error,axis=1)
```

这样做得到的data去掉了一部分偏差比较大的价格，最终得到的结果比现在的结果上升了0.01，但是后来我们发现这种做法并不可取，因为如果这样处理了，通过留出法划分出来的测试集和训练集分布会更相似，而真正要预测的data分布就不一样了，所以我们也舍弃了这种处理方式。

##### 3. Tfidf与Count

最开始**name**这个特征我们用的是CountVectorizer来将其转变为词频矩阵，但是我们后来发现，**name**中可能存在出现频率大但却不重要的词，所以我们将其乘上一个idf权重，即我们把CountVectorizer变成TfidfVectorizer，经过测试，确实TfidfVectorizer让结果优化了不少。

![](D:\learn\数据科学导论\大作业\29.png)

这是我们最终的特征组合，其中分类的特征用的是CountVectorizer，而对于句子，描述等特称我们用的是TfidfVectorizer。我们还分别测试了ngram_range以及max_features不同的值对结果的影响，最终确定了以上的参数为我们的最优化模型。这也导致我们的模型太大，特征维度太高。

### 七. 调用的库

| 运行环境     | 版本   |
| ------------ | ------ |
| Python       | 3.7.4  |
| Keras        | 2.3.1  |
| lightgbm     | 2.3.0  |
| scipy        | 1.3.1  |
| numpy        | 1.16.5 |
| pandas       | 0.25.1 |
| pillow       | 6.2.1  |
| seaborn      | 0.9.0  |
| matplotlib   | 3.1.1  |
| scikit-learn | 0.21.3 |

