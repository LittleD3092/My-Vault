# 微處理機LAB 5 Clock and Timer

## Part 1. 實作題

### Lab 5.1 Modify system initial clock

實驗結果在 `video/lab_modify_system_clock.mp4`
在 `main.c` 中加入以下指令來執行此部份

```c
#define lab_modify_system_clock
```

## Part 2. 實作題

### Lab 5.2 Timer

實驗結果在 `video/lab_counter.mp4`
在 `main.c` 中加入以下指令來執行此部份

```c
#define lab_counter
```

## Part 3. 實作題

### Lab 5.3 電子琴

實驗結果在 `video/lab_music_keyboard.mp4`
在 `main.c` 中加入以下指令來執行此部份

```c
#define lab_music_keyboard
```

## Part 4. 問答題

1. Sysclk 的時鐘是用於同步整個系統，而timer內的時鐘只有計時功能。
2. 首先將腳位設定成Alternate function mode，再將外接Timer開啟，並將腳位設定成PWM輸出，最後啟動Timer的counter，透過設定arr, CCR1以及 PreScalar來決定duty cycle 和frequency。

## Part 4. 加分題

### 5.4 Music 音色體驗

實驗結果在 `video/lab_music_dutycycle.mp4`
在 `main.c` 中加入以下指令來執行此部份

```c
#define lab_music_dutycycle
```