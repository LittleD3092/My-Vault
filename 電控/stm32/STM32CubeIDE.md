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

# run

- 編譯器不支援中文路徑

# debug

IDE 不允許使用 print 與 cout ，可以使用他的 debug 功能

- 快捷鍵: F11
- 繼續執行: F8

# memory

可以在 IDE 直接修改變數值

# functions

> 延遲:
> - [[#HAL_Delay]]
> 
> 輸出:
> - [[#HAL_GPIO_WritePin]]
> - [[#HAL_GPIO_TogglePin]]

## HAL_Delay

```c
HAL_Delay(500);
```

裡面放要暫停幾毫秒

## HAL_GPIO_WritePin

用來輸出高電位或低電位

```c
HAL_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_PIN, GPIO_PinState PinState);
```

例如將 `PB0` 輸出高電位

```c
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);
```

- `GPIOB`: `B` 為腳位 `PB0` 中的 `B`
- `GPIO_PIN_0`: `PB0` 中的 `0`
- `GPIO_PIN_SET`: 高電位，若是低電位則填 `GPIO_PIN_RESET`

## HAL_GPIO_TogglePin

和 [[#HAL_GPIO_WritePin]] 很像，只是他會輸出跟現在相反的電位，例如若現在是高電位他就會輸出低電位。

```c
HAL_GPIO_TogglePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_PIN);
```

例如改變 `PB0` 的電位

```c
HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0);
```

## HAL_GPIO_ReadPin

讀取輸入的電位為高或低

```c
HAL_GPIO_ReadPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_PIN);
```

例如偵測 `PF13` 的電位

```c
bool state = HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_13);
```

---

參考資料:

[【Day4】:來使用STM32CubeIDE吧!](https://ithelp.ithome.com.tw/articles/10267024)

---

link:

