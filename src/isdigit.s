#int	ft_isdigit(int c);
.global ft_isdigit

.equ _CHAR_0, 48
.equ _CHAR_9, 57

ft_isdigit:
#if c - '0' < 0 return false
	cmpl $_CHAR_0, %edi
	jb return_false
#else if c - '9' > 0 return false
	cmpl $_CHAR_9, %edi
	ja return_false
#else
#	return true;
	mov $1, %eax
	ret

return_false:
	xor %eax, %eax
	ret

.section .note.GNU-stack, "", @progbits
