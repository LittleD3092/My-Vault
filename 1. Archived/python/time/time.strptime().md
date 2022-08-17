標籤: #python 

---

與[[time.strftime()]]相反，可以把指定格式字串變成[[struct_time]]

```python
import time

time_string = "09/25/2019, 14:57:52"

result = time.strptime(time_string, "%m/%d/%Y, %H:%M:%S")
print(result)
```

> 輸出: `time.struct_time(tm_year=2019, tm_mon=9, tm_mday=25, tm_hour=14, tm_min=57, tm_sec=52, tm_wday=2, tm_yday=268, tm_isdst=-1)`

---

參考資料:

[python time - blog](time.struct_time(tm_year=2019, tm_mon=9, tm_mday=25, tm_hour=14, tm_min=57, tm_sec=52, tm_wday=2, tm_yday=268, tm_isdst=-1))

---

link:

[[time]]