標籤: #python 

---

```python
import time
result = time.localtime(1569376996)
print(result)
```

> 結果: `time.struct_time(tm_year=2019, tm_mon=9, tm_mday=25, tm_hour=10, tm_min=3, tm_sec=16, tm_wday=2, tm_yday=268, tm_isdst=0)`

可以將[[time.time()]]產生的秒數變成[[struct_time]]

---

參考資料:

[python time - blog](https://officeguide.cc/python-time-tutorial-examples/)

---

link:

[[time]]