#void	*ft_memset(void *buf, int c, size_t n);

.global ft_memset

ft_memset:
	movq		%rdi, %rax #setup return value and never change it

	cmp		$0, %rdx
	je		return

loop:
	dec		%rdx
	movb	%sil, (%rdi)
	inc		%rdi
	cmp		$0, %rdx
	jne		loop

return:
	ret

.section .note.GNU-stack, "", @progbits
