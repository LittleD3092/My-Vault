標籤: #cpp 

---

[TOC]

---

# C++

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

# Javascript

To generate random number in javascript, we use function `Math.random()`. This function generates a floating point number in range $[0, 1)$.

```js
// generate a number between 0 (inclusive) and 1 (exclusive).
var num = Math.random();
```

However, we may want to obtain larger number than 1. For example, a DND dice has 20 faces. In this case, a simple math operator `*` and the function `Math.floor()` can modify the range of `Math.random()` to the desired range.

```js
// generate a number between 1 and 20 (both inclusive).
var dndNum = Math.floor(Math.random() * 20) + 1;
```

The following process shows how a range $[1, 20]$ is obtained.

$$
\begin{array}{l}
             & Math.random() & [0, 1), double \\
    \implies & Math.random() * 20 & [0, 20), double \\
    \implies & Math.floor(Math.random() * 20) &
               [0, 19], int \\
    \implies & Math.floor(Math.random() * 20) + 1 & 
               [1, 20], int
\end{array}
$$

---

參考資料:

[rand 教學 - blog](https://blog.gtwang.org/programming/c-cpp-rand-random-number-generation-tutorial-examples/)
[javascript tutorial - youtube](https://youtu.be/PkZNo7MFNFg)

---

link:

