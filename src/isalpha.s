#int ft_isalpha(int c);
#97 == 'a'
#122 == 'z'
#65 == 'A'
#90 == 'Z'
.global ft_isalpha
ft_isalpha:
#check if the value is less than any ascii (<'A')
	mov $65, %rbx
	cmp %rdi, %rbx
	jg return_false

#check if the value is more than any ascii (>'z')
	mov $122, %rbx
	cmp %rbx, %rdi
	jg return_false

#check if the value is >= 'a'
	mov $97, %rbx
	cmp %rbx, %rdi
	jge return_true

#check if the value is <= 'Z'
	mov $90, %rbx
	cmp %rbx, %rdi
	jle return_true

	jmp return_false

return_false:
mov $0, %rax
	ret
return_true:
mov $1024, %rax
	ret
