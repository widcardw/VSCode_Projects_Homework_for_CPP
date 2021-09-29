	.file	"shift_string.c"
	.text
	.globl	str
	.data
	.align 16
str:
	.ascii "??????$\0"
	.space 12
	.comm	len, 4, 2
	.def	__main;	.scl	2;	.type	32;	.endef
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
	movl	$0, -4(%rbp)
	jmp	.L2
.L3:
	addl	$1, -4(%rbp)
.L2:
	movl	-4(%rbp), %eax
	cltq
	leaq	str(%rip), %rdx
	movzbl	(%rax,%rdx), %eax
	cmpb	$36, %al
	jne	.L3
	jmp	.L4
.L5:
	movl	-4(%rbp), %eax
	leal	2(%rax), %ecx
	movl	-4(%rbp), %eax
	cltq
	leaq	str(%rip), %rdx
	movzbl	(%rax,%rdx), %edx
	movslq	%ecx, %rax
	leaq	str(%rip), %rcx
	movb	%dl, (%rax,%rcx)
.L4:
	cmpl	$0, -4(%rbp)
	jns	.L5
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (tdm64-1) 9.2.0"
