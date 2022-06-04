標籤: #python 

---

# import

```python
import numpy as np
```

# np.array()

`np.array()` 與 list 不同的地方在於 `np.array()` 使用依整塊的記憶體儲存資料，相對 list 運算較快

![[numpy_list.png]]

```python
import time

t0 = time.time()
# python list
l = list(range(100))
for _ in range(10000):
    for i in range(len(l)):
        l[i] += 1

t1 = time.time()
# numpy array
a = np.array(l)
for _ in range(10000):
    a += 1

print("Python list spend {:.3f}s".format(t1-t0))
print("Numpy array spend {:.3f}s".format(time.time()-t1))
```

## 定義

```python
np.array([1,2,3])
```

## 存儲、提取

### index

```python
import numpy as np

# 單個選取
a = np.array([1, 2, 3])
print("a[0]:", a[0])
print("a[1]:", a[1])
```

### 多個 index

```python
# 多個選取(一維)
print("a[[0,1]]:\n", a[[0,1]])
print("a[[1,1,0]]:\n", a[[1,1,0]])
```

```python
# 多個選取(多維)
b = np.array([
[1,2,3,4],
[5,6,7,8],
[9,10,11,12]
])

# 选第 2 行所有数
print("b[1]:\n", b[1])   

# 选第 2 行，第 1 列的数
print("b[1,0]:\n", b[1,0])   

# 这个看着有点纠结，如果对应到数据，
# 第一个拿的是数据位是 [1,2]
# 第二个拿的是 [0,3]
print("b[[1,0],[2,3]]:\n", 
b[[1,0],
[2,3]])
```

### 切片劃分

```python
# 多個選取(切片劃分)
a = np.array([1, 2, 3])
print("a[0:2]：\n", a[0:2])
print("a[1:]：\n", a[1:])
print("a[-2:]：\n", a[-2:])
```

### 條件選取

```python
a = np.array([
[1,2,3,4],
[5,6,7,8],
[9,10,11,12]
])

print(a[a>7])
```

> 其中 `a > 7` 產生了一個布林陣列
> ```python
> condition = a > 7
> print(condition)
> 
> print(a[condition])
> ```
> 
> ```
> [[False False False False]  
> [False False False True]  
> [ True True True True]]  
> [ 8 9 10 11 12]
> ```

除了使用 `[]` ，還有函數可以用來篩選數據

```python
condition = a > 7
print(np.where(condition, -1, a))
```

```
[[ 1 2 3 4]  
[ 5 6 7 -1]  
[-1 -1 -1 -1]]
```

其中滿足條件的數字都改成 `-1` ，不滿足條件的設為 `a` 中的數字

## 陣列屬性

### 維度

```python
import numpy as np

cars = np.array([5, 10, 12, 6])
print("数据：", cars, "\n维度：", cars.ndim)
```

可以使用 `cars.ndim` 看出維度多少，在這個情況下是 `1`

### 總個數

```python
print("总共多少测试数据：", cars.size)
```

## 創建多維數據

二維數據:
```python
cars = np.array([
[5, 10, 12, 6],
[5.1, 8.2, 11, 6.3],
[4.4, 9.1, 10, 6.6]
])

print("数据：\n", cars, "\n维度：", cars.ndim)
```

三維數據:
```python
cars = np.array([
[
    [5, 10, 12, 6],
    [5.1, 8.2, 11, 6.3],
    [4.4, 9.1, 10, 6.6]
],
[
    [6, 11, 13, 7],
    [6.1, 9.2, 12, 7.3],
    [5.4, 10.1, 11, 7.6]
],
])

print("总维度：", cars.ndim)
print("场地 1 数据：\n", cars[0], "\n场地 1 维度：", cars[0].ndim)
print("场地 2 数据：\n", cars[1], "\n场地 2 维度：", cars[1].ndim)
```

## 添加資料

### np.concatenate()

一維：
```python
cars1 = np.array([5, 10, 12, 6])
cars2 = np.array([5.2, 4.2])
cars = np.concatenate([cars1, cars2])
print(cars)
```

多維：

先將陣列增加維度，再把兩個陣列疊起來

```python
test1 = np.array([5, 10, 12, 6])
test2 = np.array([5.1, 8.2, 11, 6.3])

# 首先需要把它们都变成二维，下面这两种方法都可以加维度
test1 = np.expand_dims(test1, 0)
test2 = test2[np.newaxis, :]

print("test1加维度后 ", test1)
print("test2加维度后 ", test2)

# 然后再在第一个维度上叠加
all_tests = np.concatenate([test1, test2])
print("括展后\n", all_tests)
```

```
test1加维度后 [[ 5 10 12 6]]  
test2加维度后 [[ 5.1 8.2 11. 6.3]]  
括展后  
[[ 5. 10. 12. 6. ]  
[ 5.1 8.2 11. 6.3]]
```

---

使用參數在不同方向疊加陣列

```python
print("第一维度叠加：\n", np.concatenate([all_tests, all_tests], axis=0))
print("第二维度叠加：\n", np.concatenate([all_tests, all_tests], axis=1))
```

```python
第一维度叠加：  
[[ 5. 10. 12. 6. ]  
[ 5.1 8.2 11. 6.3]  
[ 5. 10. 12. 6. ]  
[ 5.1 8.2 11. 6.3]]  
第二维度叠加：  
[[ 5. 10. 12. 6. 5. 10. 12. 6. ]  
[ 5.1 8.2 11. 6.3 5.1 8.2 11. 6.3]]
```

> 要使用 `np.concatenate()` 疊加陣列需要兩個陣列的對應長或寬一樣
> ```python
> a = np.array([
> [1,2,3],
> [4,5,6]
> ])
> b = np.array([
> [7,8],
> [9,10]
> ])
> 
> print(np.concatenate([a,b], axis=1))  # 这个没问题
> # print(np.concatenate([a,b], axis=0))  # 这个会报错
> ```

### np.vstack(), np.hstack()

這兩個函式專門用在二維陣列上面

```python
a = np.array([
[1,2],
[3,4]
])
b = np.array([
[5,6],
[7,8]
])
print("竖直合并\n", np.vstack([a, b]))
print("水平合并\n", np.hstack([a, b]))
```

```
竖直合并  
[[1 2]  
[3 4]  
[5 6]  
[7 8]]  
水平合并  
[[1 2 5 6]  
[3 4 7 8]]
```

### np.column_stack()

```python
feature_a = np.array([1,2,3,4,5,6])
feature_b = np.array([11,22,33,44,55,66])
c_stack = np.column_stack([feature_a, feature_b])
print(c_stack)
```

```
[[ 1 11]  
[ 2 22]  
[ 3 33]  
[ 4 44]  
[ 5 55]  
[ 6 66]]
```

### np.row_stack()

```python
sample_a = np.array([0, 1.1])
sample_b = np.array([1, 2.2])
c_stack = np.row_stack([sample_a, sample_b])
print(c_stack)
```

```
[[0. 1.1]  
[1. 2.2]]
```

## 分割陣列

### np.vsplit(), np.hsplit()

```python
a = np.array(
[[ 1, 11, 2, 22],
 [ 3, 33, 4, 44],
 [ 5, 55, 6, 66],
 [ 7, 77, 8, 88]]
)
print(np.vsplit(a, indices_or_sections=2))  # 分成两段
print(np.vsplit(a, indices_or_sections=[2,3]))  # 0~2 一段，2~3 一段，3~一段
```

```
[array([[ 1, 11, 2, 22],  
[ 3, 33, 4, 44]]), array([[ 5, 55, 6, 66],  
[ 7, 77, 8, 88]])]  
[array([[ 1, 11, 2, 22],  
[ 3, 33, 4, 44]]), array([[ 5, 55, 6, 66]]), array([[ 7, 77, 8, 88]])]
```

### np.split()

```python
a = np.array(
[[ 1, 11, 2, 22],
 [ 3, 33, 4, 44],
 [ 5, 55, 6, 66],
 [ 7, 77, 8, 88]]
)
print(np.split(a, indices_or_sections=2, axis=0))  # 分成两段
print(np.split(a, indices_or_sections=[2,3], axis=1))  # 在第二维度， 0~2 一段，2~3 一段，3~一段
```

```
[array([[ 1, 11, 2, 22],  
[ 3, 33, 4, 44]]), array([[ 5, 55, 6, 66],  
[ 7, 77, 8, 88]])]  
[array([[ 1, 11],  
[ 3, 33],  
[ 5, 55],  
[ 7, 77]]), array([[2],  
[4],  
[6],  
[8]]), array([[22],  
[44],  
[66],  
[88]])]
```

## 添加維度

### np.newaxis

```python
import numpy as np

a = np.array([1,2,3,4,5,6])
a_2d = a[np.newaxis, :]
print(a.shape, a_2d.shape)
```

### None, np.expand_dims()

```python
a = np.array([1,2,3,4,5,6])
a_none = a[:, None]
a_expand = np.expand_dims(a, axis=1)
print(a_none.shape, a_expand.shape)
```

## 減少維度

```python
a_squeeze = np.squeeze(a_expand)
a_squeeze_axis = a_expand.squeeze(axis=1)
print(a_squeeze.shape)
print(a_squeeze_axis.shape)
```

## 更改 shape

```python
a = np.array([1,2,3,4,5,6])
a1 = a.reshape([2, 3])
a2 = a.reshape([3,1,2])
print("a1 shape:", a1.shape)
print(a1)
print("a2 shape:", a2.shape)
print(a2)
```

## 加減乘除與數據分析

### 矩陣相乘

```python
a = np.array([
[1, 2],
[3, 4]
])
b = np.array([
[5, 6],
[7, 8]
])

print(a.dot(b))
print(np.dot(a, b))
```

### 矩陣內積

`np.inner(a, b)`

### 矩陣外積

`np.outer(a, b)`

### 矩陣轉置

```python
a = np.array([1,2,3,4,5,6]).reshape([2, 3])
aT1 = a.T
aT2 = np.transpose(a)

print(aT1)
print(aT2)
```

### 最大值、最小值

```python
a = np.array([150, 166, 183, 170])
print("最大：", np.max(a))
print("最小：", a.min())
```

### 總和

```python
print(a.sum())
```

### 累乘

```python
print("累乘：", a.prod())
```

### 非零個數

```python
print("非零总数：", np.count_nonzero(a))
```

### 平均數、中位數、標準差

```python
month_salary = [1.2, 20, 0.5, 0.3, 2.1]
print("平均工资：", np.mean(month_salary))
print("工资中位数：", np.median(month_salary))
print("标准差：", np.std(month_salary))
```

如果不想要那個值，而是想要對應的 index

```python
a = np.array([150, 166, 183, 170])
name = ["小米", "OPPO", "Huawei", "诺基亚"]
high_idx = np.argmax(a)
low_idx = np.argmin(a)
print("{} 最高".format(name[high_idx]))
print("{} 最矮".format(name[low_idx]))
```

### 無條件進位、捨去

```python
a = np.array([150.1, 166.4, 183.7, 170.8])
print("ceil:", np.ceil(a))
print("floor:", np.floor(a))
```

### 將數字限制在一定範圍

```python
a = np.array([150.1, 166.4, 183.7, 170.8])
print("clip:", a.clip(160, 180))
```

上面的例子，大於 `180` 會變成 `180` ，小於 `160` 會變成 `160`



---

參考資料:

[莫煩 numpy 教學](https://mofanpy.com/tutorials/data-manipulation/numpy/)

---

link:

