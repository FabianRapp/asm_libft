.global ft_isascii

ft_isascii:
	cmpl	$0, %edi
	jb		return_false

	cmpl	$128, %edi
	jae		return_false

return_true:
	mov $1, %eax
	ret

return_false:
	xor %eax, %eax
	ret

.section .note.GNU-stack, "", @progbits
