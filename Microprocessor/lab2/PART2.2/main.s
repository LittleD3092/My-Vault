.syntax unified
.cpu cortex-m4
.thumb

.data
    Leds: .byte 0

.text
    .global main
    .include "/home/littled3092/STM32CubeIDE/workspace_1.11.2/microprocessor-lab-1/Core/Src/pin.s"  // import GPIO constants


DisplayLED:
    PUSH {r1, r2, lr}
    lsl r0, #2
    ldr r1, =GPIOB_ODR
    ldr r2, [r1]          // Get Current Output
    and r2, #0xFFFFFFC3   // To clear PB3 to PB6: #0xFFFFFF87
                          // To clear PB2 to PB5: #0xFFFFFFC3
    eor r0, #0xFFFFFFFF   // Reverse r0 (Active Low)
    and r0, #0x3C         // To select the needed bits
                          // PB3 to PB6: #0x78
                          // PB2 to PB5: #0x3C
    orr r2, r0            // Set the output bits
    str r2, [r1]          // Write back to Output Reg
    POP {r1, r2, pc}

GPIO_init:
    // Enable AHB2 clock
    movs r0, #0x2
    ldr r1, =RCC_AHB2ENR
    str r0, [r1]
    // Set PB2 ~ PB5 to output mode
    ldr r1, =GPIOB_MODER
    ldr r0, [r1]
    and r0, #0xFFFFF00F
    orr r0, #0x550
    str r0, [r1]
    // Set PB2 ~ PB5 to high speed
    ldr r1, =GPIOB_OSPEEDR
    ldr r0, [r1]
    and r0, #0xFFFFF00F
    orr r0, #0xAA0
    str r0, [r1]
    // Set PB2 ~ PB5 to pullup
    ldr r1, =GPIOB_PUPDR
    ldr r0, [r1]
    and r0, #0xFFFFF00F
    orr r0, #0x550
    str r0, [r1]
    // Set PC13 to input mode
    ldr r1, =GPIOC_MODER
    ldr r0, [r1]
    and r0, #0xF3FFFFFF
    orr r0, #0x0
    str r0, [r1]
    bx lr

main:
    bl GPIO_init    // Setup GPIO
    movs r0, #0x6  // 0b0110
                   // 0b0000
    ldr r5, =Leds   // r5 = Leds addr
    strb r0, [r5]
    bl DisplayLED
L: b L
