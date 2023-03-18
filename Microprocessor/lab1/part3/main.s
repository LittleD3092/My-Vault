    .syntax unified
    .cpu cortex-m4
    .thumb

    .text
    .global main
    .equ AA, 0x55

fib:
    cmp r1, r0
    bge endfib

    add r3, r4, r2
    mov r4, r2
    mov r2, r3

    add r1, r1, #1
    b fib
endfib:

main:
    // N = &r0;
    // i = &r1;
    // a = &r4;
    // b = &r2;
    // c = &r3;

    // a = 0;
    // b = 1;
    // for(int i = 0; i < N; i++)
    //     c = a + b;
    //     a = b;
    //     b = c;

    mov r0, #9
    mov r1, #0
    mov r4, #0
    mov r2, #1
