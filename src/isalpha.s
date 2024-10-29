.global ft_isalpha
#141 == 'a'
#172 == 'z'
#101 == 'A'
#132 == 'Z'
ft_isalpha:
	mov $101, %rax
	cmp %rdi, %rax
	jl return_false

	mov $172, %rax
	cmp %rdi, %rax
	jg return_false

	mov $140, %rax
	cmp %rdi, %rax
	jg return_true

	mov $142, %rax
	cmp %rdi, %rax
	jl return_true

	jmp return_false

return_false:
	mov $0, %rax
	ret
return_true:
	mov $1, %rax
	ret
