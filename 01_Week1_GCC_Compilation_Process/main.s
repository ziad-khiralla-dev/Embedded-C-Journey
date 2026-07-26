	.file	"main.c"
	.text
	.section .rdata,"dr"
.LC0:
	.ascii "0b\0"
.LC1:
	.ascii "%d\0"
	.text
	.globl	print_binary
	.def	print_binary;	.scl	2;	.type	32;	.endef
	.seh_proc	print_binary
print_binary:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movb	%cl, 16(%rbp)
	leaq	.LC0(%rip), %rax
	movq	%rax, %rcx
	call	__mingw_printf
	movl	$7, -4(%rbp)
	jmp	.L2
.L3:
	movzbl	16(%rbp), %edx
	movl	-4(%rbp), %eax
	movl	%eax, %ecx
	sarl	%cl, %edx
	movl	%edx, %eax
	andl	$1, %eax
	movl	%eax, %edx
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	call	__mingw_printf
	subl	$1, -4(%rbp)
.L2:
	cmpl	$0, -4(%rbp)
	jns	.L3
	movl	$10, %ecx
	call	putchar
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 8
.LC2:
	.ascii "Hello! gcc compiler is working perfectly.\0"
	.align 8
.LC3:
	.ascii "Bitwise Test Result in Hex: 0x%02X\12\0"
.LC4:
	.ascii "Bitwise Test Result in Bin: \0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	call	__main
	leaq	.LC2(%rip), %rax
	movq	%rax, %rcx
	call	puts
	movb	$1, -1(%rbp)
	orb	$8, -1(%rbp)
	movzbl	-1(%rbp), %eax
	leaq	.LC3(%rip), %rcx
	movl	%eax, %edx
	call	__mingw_printf
	leaq	.LC4(%rip), %rax
	movq	%rax, %rcx
	call	__mingw_printf
	movzbl	-1(%rbp), %eax
	movl	%eax, %ecx
	call	print_binary
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (Rev1, Built by MSYS2 project) 16.1.0"
	.def	putchar;	.scl	2;	.type	32;	.endef
	.def	puts;	.scl	2;	.type	32;	.endef
