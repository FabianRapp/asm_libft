#void	*ft_memmove(void *dest, const void *src, size_t n);
.global ft_memmove

//TODO: alignment at the beginning


ft_memmove:
	movq	%rdi, %rax	 # return val
	
	movb	%dl, %cl

	testq	$0xFFFFFFFFFFFFFFF0, %rdx
	je		less_than_16

move_16byte_chunks:
	andb	$0xF, %cl //cl for later smaller ranges
	shr		$4, %rdx

loop16:
	movdqa	(%rsi), %xmm0
	movdqa	%xmm0, (%rdi)
	add		$16, %rsi
	add		$16, %rdi

	dec		%rdx
	testq	%rdx, %rdx
	jne		loop16

less_than_16:
	testb	$248, %cl
	je		less_than_8

move_8byte_chunk:
	sub		$8, %cl
	mov		(%rsi), %r10
	mov		%r10, (%rdi)
	add		$8, %rdi
	add		$8, %rsi

less_than_8:
	testb	%cl, %cl
	je		return
less_than_8_n0:
	decb	%cl
	movb	(%rsi), %r10b
	movb	%r10b, (%rdi)
	add		$1, %rdi
	add		$1, %rsi
	testb	%cl, %cl
	jne		less_than_8_n0

return:
	ret

.section .note.GNU-stack, "", @progbits


