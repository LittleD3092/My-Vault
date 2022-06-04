標籤: #python 

---

可以將[[struct_time]]轉換為文字

```python
import time
t = time.localtime(1569376996)
result = time.asctime(t)
print(result)
```

> 輸出: `Wed Sep 25 10:03:16 2019`

---

參考資料:

[python time - blog](https://officeguide.cc/python-time-tutorial-examples/)

---

link:

[[time]]
[[time.localtime()]]