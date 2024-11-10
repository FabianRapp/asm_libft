//int ft_toupper(int c);
.global ft_toupper

.equ _CHAR_a, 97
.equ _CHAR_z, 122

ft_toupper:
	movl	%edi, %eax
	cmpl	$_CHAR_z, %eax
	jg		return
	cmpl	$_CHAR_a, %eax
	jl		return
	subl	$32, %eax

return:
	ret

.section .note.GNU-stack, "", @progbits
