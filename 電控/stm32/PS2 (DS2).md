標籤: #電路 

---

# Pin

| 手把     | stm32    |
| -------- | -------- |
| `GND`    | `GND`    |
| `VCC`    | `3.3V`   |
| `DI/DAT` | 任一接腳 |
| `DO/CMD` | 任一接腳 |
| `CS`     | 任一接腳 |
| `CLK`    | 任一接腳 | 

# 原理

![[ps2 溝通原理.png]]

- `CS`: 傳輸時為低電位
- `DI`, `DO`: 傳輸的資料，8bit
- `CLK`: 傳輸 1bit 時由高變低

## 注意

1. `CS` 在資料傳輸的時候先拉高再拉低，進行資料傳輸，之後把 `CS` 拉高
2. `DI`(data input) 與 `DO`(data output) 是同時完成的
3. `CLK` 電壓調高時 `DI`, `DO` 電壓不穩定，應該在拉低時讀寫
4. 可以把資料放在陣列中

## 傳輸資料型態

|     | `DO`   | `DI`                                    | Bit0 ~ 7                                                          |
| --- | ------ | --------------------------------------- | ----------------------------------------------------------------- |
| 0   | `0x01` | idle                                    |                                                                   |
| 1   | `0x42` | ID (`0x41`: 綠燈模式, `0x73`: 紅燈模式) |                                                                   |
| 2   | idle   | `0x5A`                                  |                                                                   |
| 3   | WW     | data                                    | `SELECT`, `L3`, `R3`, `START`, `UP`, `RIGHT`, `DOWN`, `LEFT`      |
| 4   | YY     | data                                    | `L2`, `R2`, `L1`, `R1`, $\triangle$, $\circ$, $\times$, $\square$ |
| 5   | idle   | data                                    | `PSS_RX` (`0x00` = left, `0xFF` = right)                          |
| 6   | idle   | data                                    | `PSS_RY` (`0x00` = up, `0xFF` = down)                             |
| 7   | idle   | data                                    | `PSS_LX` (`0x00` = left, `0xFF` = right)                          |
| 8   | idle   | data                                    | `PSS_LY` (`0x00` = up, `0xFF` = down)                             |

- `CLK` 頻率: $250kHZ$ ($4\mu s$)，若資料不穩定可以適當增加
- `data[3]`, `data[4]`: 若有按鍵按下，那個按鍵的值為 `0` ，沒按的按鍵為 `1`
如 `SELECT` 按下: `0b 1111 1110`

> ### 紅燈與綠燈模式
> 紅燈模式的搖桿會亮紅燈和綠燈，綠燈模式則只亮綠燈，可以透過 mode 按鍵切換
> 
> - 紅燈模式的搖桿會輸出類比值
> - 綠燈模式的搖桿不輸出類比值，左搖桿推到底輸出 `UP`, `DOWN`, `RIGHT`, `LEFT` ，右搖桿推到底輸出相對應 $\triangle$, $\circ$, $\times$, $\square$
> 
> ### 震動
> - WW: 右側的振動馬達， `0x00` 代表關，其他值開
> - YY: 左側的振動馬達，`0x40` ~ `0xff` 代表開，值越大越強，其他值關

---

參考資料:

[PS2手柄移植到STM32上面的小筆記 - blog](https://www.uj5u.com/qita/357205.html)

---

link:

[[STM32CubeIDE]]
[[PS2X_lib.h]]