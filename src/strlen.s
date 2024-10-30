#size_t	ft_strlen(char *str);
.global ft_strlen

ft_strlen:
	xor		%rax, %rax
	ret

.section .note.GNU-stack, "", @progbits
