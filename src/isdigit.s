#int	ft_isdigit(int c);
.global ft_isdigit

.equ _CHAR_0, 48
.equ _CHAR_9, 57

ft_isdigit:
#if c - '0' < 0 return false
	mov $(_CHAR_0), %rbx
	cmp %rbx, %rdi
	jl return_false

#else if c - '9' > 0 return false
	mov $(_CHAR_9), %rbx
	cmp %rbx, %rdi
	jg return_false
#else
	jmp return_true


return_false:
	mov $0, %rax
	ret

return_true:
	mov $1, %rax
	ret

.section .note.GNU-stack, "", @progbits
