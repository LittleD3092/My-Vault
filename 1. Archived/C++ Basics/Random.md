標籤: #cpp 

---

[TOC]

---

```cpp
#include <stdio.h>
#include <stdlib.h> /* 亂數相關函數 */
#include <time.h>   /* 時間相關函數 */
int main(){
  /* 設定亂數種子 */
  srand( time(NULL) );

  /* 產生亂數 */
  int x = rand();

  printf("x = %d\n", x);
  return 0;
}
```

---

參考資料:

[rand 教學 - blog](https://blog.gtwang.org/programming/c-cpp-rand-random-number-generation-tutorial-examples/)

---

link:

