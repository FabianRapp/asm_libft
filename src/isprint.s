#int	ft_isprint(int c);
.global ft_isprint

ft_isprint:
	cmpl	$32, %edi
	jb		return_false

	cmpl	$126, %edi
	ja		return_false

return_true:
	mov		$1, %eax
	ret

return_false:
	xor		%eax, %eax
	ret

.section .note.GNU-stack, "", @progbits
