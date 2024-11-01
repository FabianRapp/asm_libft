#void	*ft_memcpy(void *dest, const void *src, size_t n);

.global ft_memcpy

ft_memcpy:
	movq	%rdi, %rax	 # return val

	testq	$0xFFFFFFFFFFFFFFF0, %rdx
	je		if_N_less_than_16

move_16byte_chunk:
	mov		%rdx, %rcx
	xorq	$0xF, %rcx //rcx for later smaller ranges
	shr		$4, %rdx

loop16:
	movdqa	(%rsi), %xmm0
	movdqa	%xmm0, (%rdi)
	add		$16, %rsi
	add		$16, %rdi

	dec		%rdx
	testq	%rdx, %rdx
	jne		loop16

if_N_less_than_16:
	testb	$248, %cl
	je		if_N_less_than_8

move_8byte_chunk:
	subb	$8, %cl
	movq	(%rsi), %r10
	movq	%r10, (%rdi)
	add		$8, %rdi
	add		$8, %rsi

if_N_less_than_8:
	rep		movsb		//rep: repeat movsb %rcx times
						//moves: moves (%rsi) to (%rdi) and increases
						//	rsi/rdi by 1 (b(yte) size)
						//(no other regs possible)
						// todo: movsb is makred as legacy:
						// would it be better not to use it?

return:
	ret

.section .note.GNU-stack, "", @progbits
