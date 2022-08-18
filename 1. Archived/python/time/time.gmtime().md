標籤: #python 

---

用途跟[[time.localtime()]]類似，也是把[[time.time()]]產生的秒數轉換成[[struct_time]]，不過傳回的時間是世界協調時間(UTC)

```python
import time
result = time.gmtime(1569376996)
```

---

參考資料:

[python time - blog](https://officeguide.cc/python-time-tutorial-examples/)

---

link:

[[time]]
