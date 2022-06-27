標籤: #stm32 

---

> 延遲:
> - [[#HAL_Delay]]
> 
> 輸出:
> - [[#HAL_GPIO_WritePin]]
> - [[#HAL_GPIO_TogglePin]]
> 
> 輸入:
> - [[#HAL_GPIO_ReadPin]]
> 
> Analog:
> - [[#ADC]]

# HAL_Delay

```c
HAL_Delay(500);
```

裡面放要暫停幾毫秒

# HAL_GPIO_WritePin

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

# HAL_GPIO_TogglePin

和 [[#HAL_GPIO_WritePin]] 很像，只是他會輸出跟現在相反的電位，例如若現在是高電位他就會輸出低電位。

```c
HAL_GPIO_TogglePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_PIN);
```

例如改變 `PB0` 的電位

```c
HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0);
```

# HAL_GPIO_ReadPin

讀取輸入的電位為高或低

```c
HAL_GPIO_ReadPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_PIN);
```

例如偵測 `PF13` 的電位

```c
bool state = HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_13);
```

# ADC

ADC 是將類比訊號轉換為數位訊號的轉換器 (analog-to-digital converter) ，每個板子有的轉換器數量與負責的腳位都不同，使用前需要先看說明書。

以下是其中一個板子的分配：

![[adc io distribution.jpg]]

## 單通道轉換

要使用 adc ，需要

1. 進入 `.ioc` 檔定義 adc
2. 在需要檢測類比訊號的地方使用以下三個函式

```c
HAL_ADC_Start(ADC_HandleTypeDef* hadc)
HAL_ADC_PollForConversion(ADC_HandleTypeDef* hadc, uint32_t Timeout)
HAL_ADC_GetValue(ADC_HandleTypeDef* hadc)
```

- 第一個函式：啟用 adc 轉換器
- 第二個函式：等待轉換完成，第二個參數需要寫下等待的毫秒。因為轉換有可能出錯，造成程式卡在這裡，因此會需要 `Timeout`。通常設置 `1`
- 第三個函式：回傳讀到的值，範圍是 `0~4095`

以下為例子：

```
/* USER CODE BEGIN WHILE */
while (1)
{
/* USER CODE END WHILE */

/* USER CODE BEGIN 3 */

    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1,1);
    value = HAL_ADC_GetValue(&hadc1);
}
```

注意第二個函式會將 adc 轉換器關閉，因此第一個函式需要寫在 while 裡面重複執行。

---

參考資料:

[【Day6】:GPIO輸入輸出(中)](https://ithelp.ithome.com.tw/articles/10268197)
[【Day7】:GPIO輸入輸出(下)](https://ithelp.ithome.com.tw/articles/10268523)

---

link:

[[Transistor]]