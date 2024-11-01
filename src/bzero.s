#void	ft_bzero(void *buf, size_t n);
.global ft_bzero

ft_bzero:
	cmp		$0, %rsi
	je		return
loop:
	dec		%rsi
	movb	$0, (%rdi)
	inc		%rdi
	cmp		$0, %rsi
	jne		loop


return:
	ret

.section .note.GNU-stack, "", @progbits
