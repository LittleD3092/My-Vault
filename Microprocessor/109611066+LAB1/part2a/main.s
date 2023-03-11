	.syntax unified
	.cpu cortex-m4
	.thumb

	.text
	.global main
	.equ AA, 0x55

main:
	movs r0, #0x20
	movs r1, #0x10
	subs r2, r0, r1
