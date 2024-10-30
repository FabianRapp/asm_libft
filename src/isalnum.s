#include <libft.h>

#int	ft_isalnum(int c);
.global ft_isalnum
#include "../libft.h"
ft_isalnum:
	pushq %rdi
	call ft_isalpha
	cmpl $0, %eax
	ja return_true

	popq %rdi

	call ft_isdigit
	cmpl $0, %eax
	ja return_true

return_false:
	xor %eax, %eax
	ret

return_true:
	movl $1, %eax
	ret

.section .note.GNU-stack, "", @progbits
