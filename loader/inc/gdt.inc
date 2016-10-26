bits 16

LoadGDT:
	cli
	pusha
	lgdt [toc]
	sti
	popa
	ret

; This is really bad. You should not simply keep the data
; descriptor initialized. Lacks a couple of other descriptors
; Also very generic code, found all over the internet everywhere.
; http://stackoverflow.com/questions/28645439/how-do-i-enter-32-bit-protected-mode-in-nasm-assembly
; http://forum.osdev.org/viewtopic.php?f=1&t=26382
; https://github.com/randcode-generator/RandCodeOS/blob/de7760e31832cb93861421fc5c30505708809938/boot.asm

gdt_data:

	dd	0
	dd	0
	
	dw	0xffff
	dw	0x0
	db	0x0
	db 	10011010b
	db	11001111b
	db	0x0

	dw	0xffff
	dw	0x0
	db	0x0
	db	10010010b
	db	11001111b
	db	0x0

	dw	0xffff
	dw	0x0
	db	0x0
	db	11111010b
	db	11001111b
	db	0x0

	dw	0xffff
	dw	0x0
	db	0x0
	db	11110010b
	db	11001111b
	db	0x0
	
	
gdt_end:

toc:
	dw 	gdt_end - gdt_data - 1
	dd	gdt_data

%define	NULL_DESC	0
%define CODE_DESC	0x8
%define	DATA_DESC	0x10
