    .syntax unified
    .cpu cortex-m4
    .thumb

    .text
    .global main
    .equ AA, 0x55

main:
    movs r0, #0x5
    movs r1, #0x9
    mul r2, r0, r1
