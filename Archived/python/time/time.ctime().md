標籤: #python 

---

將[[time.time()]]產生的時間轉換為本地時間

```python
import time
seconds = time.time()
local_time = time.ctime(seconds)
print(lacal_time)
```

輸出結果: `Wed Sep 25 10:17:09 2019`

如果不加入任何參數，[[time.ctime()]]會直接採用目前的時間

```python
import time
now = time.ctime()
print(now)
```

---

參考資料:

[python time - blog](https://officeguide.cc/python-time-tutorial-examples/)

---

link:

[[time]]
