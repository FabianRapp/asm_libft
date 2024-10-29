#141 == 'a'
#172 == 'z'
#101 == 'A'
#132 == 'Z'
ft_isalpha:
	cmp %rdi, $101
	jl return_false

	cmp %rdi, $172
	jg return_false

	cmp %rdi, $140
	jg return_true

	cmp %rdi, $142
	jl return_true

	jmp return_false


return_false:
	mov %rax, $0
	ret
return_true:
	mov %rax, $1
	ret
