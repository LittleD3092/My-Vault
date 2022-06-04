標籤: #python 

---

和[[time.localtime()]]互為反函數

這個函式可以把[[struct_time]]轉換成秒數

```python
import time
t = time.localtime(1569376996)
s = time.mktime(t)
print(s)
```

> 輸出: `1569376996.0`

---

參考資料:

[python time - blog](https://officeguide.cc/python-time-tutorial-examples/)

---

link:

[[time]]