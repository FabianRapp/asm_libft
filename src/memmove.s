#void	*ft_memmove(void *dest, const void *src, size_t n);
.global ft_memmove

//TODO: alignment for simd operations

ft_memmove:
//init
	movq	%rdi, %rax	 # return val
	cmp		%rdi, %rsi
	jl		right_to_left

left_to_right:
#todo: this was done before right to left:
#can be done much cleaner and efficent now
#also right to left does not use any simd right now
	//jmp		copy_bytes_left_to_right_init
/*
   if (abs(rdi - rsi) >= 16) {
		memcpy
   } else {
		copy_bytes_left_to_right
   }
*/
	cmpq	%rdi, %rsi
	jl		rdi_greater_rsi
	jg		rdi_smaller_rsi
	jmp		return

rdi_greater_rsi:
	movq	$16, %r10
	addq	%rsi, %r10
	cmpq	%rdi, %rsi
	jge		copy_bytes_left_to_right_init
	jmp		_memcpy

rdi_smaller_rsi:
	movq	$-16, %r10
	addq	%rsi, %r10
	cmpq	%rdi, %rsi
	jl		copy_bytes_left_to_right_init


_memcpy:
	movq	%rdx, %rcx #cl counter for later loops
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
	je		copy_bytes_left_to_right

move_8byte_chunk:
	sub		$8, %cl
	mov		(%rsi), %r10
	mov		%r10, (%rdi)
	add		$8, %rdi
	add		$8, %rsi


copy_bytes_left_to_right:
	testq	%rcx, %rcx
	jz		return
copy_bytes_left_to_right_n0:
	decq	%rcx
	movb	(%rsi), %r10b
	movb	%r10b, (%rdi)
	addq	$1, %rdi
	addq	$1, %rsi
	testq	%rcx, %rcx
	jne		copy_bytes_left_to_right_n0

return:
	ret

copy_bytes_left_to_right_init:
	movq	%rdx, %rcx
	jmp copy_bytes_left_to_right

right_to_left:

	testq	%rdx, %rdx
	jz		return

	addq	%rdx, %rdi
	addq	%rdx, %rsi


loop_right_left:

	decq	%rsi
	decq	%rdi

	movb	(%rsi), %r10b
	movb	%r10b, (%rdi)

	cmpq	%rdi, %rax
	jnz		loop_right_left

return2:
	ret


copy_bytes_right_to_left:

.section .note.GNU-stack, "", @progbits


