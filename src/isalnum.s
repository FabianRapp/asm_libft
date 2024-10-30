#include <libft.h>

#int	ft_isalnum(int c);
.global ft_isalnum
#include "../libft.h"

#push/pop rdi should not be needed since i know the functions but let's keep it
#a little maintainalbe
ft_isalnum:
	push %rdi
	call ft_isalpha
	pop %rdi
	cmpl $0, %eax
	ja return_true

	push %rdi
	call ft_isdigit
	pop %rdi
	cmpl $0, %eax
	ja return_true

return_false:
	xor %eax, %eax
	ret

return_true:
	movl $1, %eax
	ret

.section .note.GNU-stack, "", @progbits
