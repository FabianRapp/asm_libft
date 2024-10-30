#size_t	ft_strlen(const char *str);
.global ft_strlen

ft_strlen:
	xor		%rax, %rax

	movb	(%rdi), %cl
	cmpb	$0, %cl
	je		return

loop:
	incq	%rax
	incq	%rdi
	movb	(%rdi), %cl
	cmpb	$0, %cl
	jne		loop

return:
	ret

.section .note.GNU-stack, "", @progbits
