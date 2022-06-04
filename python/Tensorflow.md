標籤: #AI

---

# Installing

```bash
pip install tensorflow
```

如果有 GPU

```bash
pip install tensorflow-gpu
```

```python
import tensorflow as tf
print(tf.version)
```

# Tensors

一種 tensorflow 常用的資料型態

## Data Type

### int, float, string

```python
string = tf.Variable("this is a string", tf.string)
number = tf.Variable(324, tf.int16)
floating = tf.Variable(3.567, tf.float64)
```

### matrix

```python
# Creating a 2D tensor

matrix = [[1,2,3,4,5],
[6,7,8,9,10],
[11,12,13,14,15],
[16,17,18,19,20]]

tensor = tf.Variable(matrix, dtype=tf.int32)
```

## Rank / Shape

每個 tensor 都有一個 [[Rank]] ，代表它的維度數量

```python
rank1_tensor = tf.Variable(["Test"], tf.string)
rank2_tensor = tf.Variable([["test", "ok"], ["test", "yes"]], tf.string)

# output rank
tf.rank(rank2_tensor)

# output shape
rank2_tensor.shape
```

## Changing Shape

可以改變形狀，但是裡面的 elements 必須相等

```python
tensor1 = tf.ones([1,2,3]) # tf.ones() creates a shape [1,2,3] tensor full of ones
tensor2 = tf.reshape(tensor1, [2,3,1]) # reshape existing data to shape [2,3,1]
tensor3 = tf.reshape(tensor2, [3, -1]) # -1 tells the tensor to calculate the size of the dimension in that place
# this will reshape the tensor to [3,2]
# The number of elements in the reshaped tensor MUST match the number in the original
```

## Slicing

提取其中的資料

```python
# Creating a 2D tensor
matrix = [[1,2,3,4,5],
[6,7,8,9,10],
[11,12,13,14,15],
[16,17,18,19,20]]

tensor = tf.Variable(matrix, dtype=tf.int32)
print(tf.rank(tensor))
print(tensor.shape)

# Now lets select some different rows and columns from our tensor

three = tensor[0,2] # selects the 3rd element from the 1st row
print(three) # -> 3

row1 = tensor[0] # selects the first row
print(row1)

column1 = tensor[:, 0] # selects the first column
print(column1)

row_2_and_4 = tensor[1::2] # selects second and fourth row
print(row2and4)

column_1_in_row_2_and_3 = tensor[1:3, 0]
print(column_1_in_row_2_and_3)
```

# Linear Regression

## install

```bash
pip install sklearn
```

## titanic example

```python
from __future__ import absolute_import, division, print_function, unicode_literals

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from IPython.display import clear_output
from six.moves import urllib

import tensorflow.compat.v2.feature_column as fc

import tensorflow as tf

# Load dataset.
dftrain = pd.read_csv('https://storage.googleapis.com/tf-datasets/titanic/train.csv') # training data
dfeval = pd.read_csv('https://storage.googleapis.com/tf-datasets/titanic/eval.csv') # testing data
y_train = dftrain.pop('survived')
y_eval = dfeval.pop('survived')

dftrain.head() # show first 5 items
dftrain.describe() # show analysis
dftrain.shape # show shape
y_train.head() # show first 5 survival information

```

---

參考資料:

[Module 2 - Introduction - colab](https://colab.research.google.com/drive/1F_EWVKa8rbMXi3_fG0w7AtcscFq7Hi7B#forceEdit=true&sandboxMode=true)
[Module 3 - Core Learning Algorithms - colab](https://colab.research.google.com/drive/15Cyy2H7nT40sGR7TBN5wBvgTd57mVKay#forceEdit=true&sandboxMode=true)
[Module 4 - Neural Networks - colab](https://colab.research.google.com/drive/1m2cg3D1x3j5vrFc-Cu0gMvc48gWyCOuG#forceEdit=true&sandboxMode=true)
[Module 5 - Computer Vision - colab](https://colab.research.google.com/drive/1ZZXnCjFEOkp_KdNcNabd14yok0BAIuwS#forceEdit=true&sandboxMode=true)
[Module 6 - Natural Language Processing with RNNs - colab](https://colab.research.google.com/drive/1ysEKrw_LE2jMndo1snrZUh5w87LQsCxk#forceEdit=true&sandboxMode=true)
[Module 7 - Reinforcement Learning - colab](https://colab.research.google.com/drive/1IlrlS3bB8t1Gd5Pogol4MIwUxlAjhWOQ#forceEdit=true&sandboxMode=true)

---

link:

