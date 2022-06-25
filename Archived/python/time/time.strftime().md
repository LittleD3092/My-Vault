標籤: #python 

---

這個函數可以依照指定的格式把[[struct_time]]改變成字串

```python
import time

t = time.localtime()

result = time.strftime("%m/%d/%Y, %H:%M:%S", t)
print(result)
```

> 輸出: `09/25/2019, 14:57:52`

---

參考資料:

[python time - blog](https://officeguide.cc/python-time-tutorial-examples/)

---

link:

[[time]]