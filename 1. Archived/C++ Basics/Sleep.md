標籤: #cpp

---

[TOC]

---

# sleep

`sleep()` 可以將程式暫停執行數秒，在括號中可以填入暫停的秒數(`int`)。

```cpp
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include<iostream>
#include <cstdlib>
using namespace std;
int main()
{
  cout << "Before sleep call "<<endl;
  cout.flush();
  sleep(9);
  cout << "After sleep call"<< endl;

  return 0;
}
```

`sleep` 的函式在 c++ 中沒有定義，是由特定作業系統提供。因此 `include` 的地方 windows 和 linux 的寫法不同，如果是 windows 的環境需要引入 `Windows.h` ，而若是 linux 的環境則需要引入 `unistd.h`。

# usleep

使用 [[#sleep]] 時指定的秒數只能精確到一秒，若是我們需要半秒的暫停時間的話可以使用 `usleep` ，這個函式以 $\mu s$ 作為秒數的單位，可以提供更精確的暫停時間。

這個函式包含在 `unistd.h` 中。

```cpp
#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;
int main()
{
  cout << "Hello ";
  cout.flush();
  usleep(10000);
  cout << "World";
  cout << endl;

  return 0;
}
```

---

參考資料:

[c++ sleep 教學 - blog](https://www.delftstack.com/zh-tw/howto/cpp/cpp-delay/)

---

link:

[[Sleep Sort]]