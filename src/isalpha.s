#int ft_isalpha(int c);
.global ft_isalpha
.equ _CHAR_A, 65
.equ _CHAR_Z, 90
.equ _CHAR_a, 97
.equ _CHAR_z, 122

ft_isalpha:
#check if the value is less than any ascii (<'A')
	cmpl $_CHAR_A, %edi
	jb return_false

#check if the value is more than any ascii (>'z')
	cmpl $_CHAR_z, %edi
	ja return_false

#check if the value is >= 'a'
	cmpl $_CHAR_a, %edi
	jae return_true

#check if the value is <= 'Z'
	cmpl $_CHAR_Z, %edi
	jbe return_true

return_false:
	xor %rax, %rax
	mov $0, %rax
	ret

return_true:
	xor %rax, %rax
	mov $1024, %rax
	ret
