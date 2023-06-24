# 微處理機 LAB 4 KeyPad

## Part 1

### Lab 4.2

在 `main.c` 中加入以下 `define` 來執行此部份：

```c
#define lab_keypad_calculator_2_operands
```

Demo 影片在 `doc/lab_keypad_calculator_2_operands.mp4`。

## Part 2

- 說明open-drain 和push-pull 在本實驗應用上的差異。
keypad在使用open-drain需要提供外接電源，否則無法運作。 使用open-drain時，keypad的輸出電位是0.2V，使用push-pull時則是high voltage(3.3V)

- 本實驗KeyPad 的運作原理。
當按下按鍵時，會形成通路輸出電壓，然後根據哪一行以及哪一列有輸出訊號便可以判斷哪一個按鈕被按下

## Part 3

### Lab 4.3

在 `main.c` 中加入以下 `define` 來執行此部份：

```c
#define lab_keypad_calculator_multi_operands
```

Demo 影片在 `doc/lab_keypad_calculator_multi_operands.mp4`。

## Part 4

### Lab 4.4

在 `main.c` 中加入以下 `define` 來執行此部份：

```c
#define lab_keypad_multi_key
```

Demo 影片在 `doc/lab_keypad_multi_key.mp4`。