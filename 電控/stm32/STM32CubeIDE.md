標籤: #stm32 

---

# core/src/main.c

主程式

## 用戶自定義區

最前面有一些註解是使用者可以自行定義的地方。

```c
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */
```

例如這裡，可以把定義寫在 `USER CODE BEGIN` 和 `USER CODE END` 之間，如果放在這之外的地方的話 IDE 會清除這些程式碼(因為這個 IDE 會自己產生程式碼在 `USER CODE BEGIN` 和 `USER CODE END` 以外的地方)。

# Run

- 編譯器不支援中文路徑

# Debug

IDE 不允許使用 print 與 cout ，可以使用他的 debug 功能

- 快捷鍵: F11
- 繼續執行: F8

# Memory

可以在 IDE 直接修改變數值

# GPIO

![[GPIO of STM32]]

---

參考資料:

[【Day4】:來使用STM32CubeIDE吧!](https://ithelp.ithome.com.tw/articles/10267024)
[【Day6】:GPIO輸入輸出(中)](https://ithelp.ithome.com.tw/articles/10268197)
[【Day7】:GPIO輸入輸出(下)](https://ithelp.ithome.com.tw/articles/10268523)

---

link:

[[Transistor]]