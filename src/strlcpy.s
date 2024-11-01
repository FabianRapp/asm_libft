#size_t	ft_strlcpy(char *dest, const char *src, size_t n);
.global ft_strlcpy

ft_strlcpy:
	movq	$0, %rax
	testq	%rdx, %rdx
	je		_strlen

	decq	%rdx //leave 1 space for termination

	testq	%rdx, %rdx
	je		terminate

loop:
	movb	(%rsi), %r10b
	movb	%r10b, (%rdi)

	testb	%r10b, %r10b
	je		return

	incq	%rsi
	incq	%rdi
	incq	%rax
	decq	%rdx

	testq	%rdx, %rdx
	jne		loop

terminate:
	movb	$0, (%rdi)

//for some reason strlcpy returns the len of src if strlen(src) > n
_strlen:
	movb	(%rsi), %r10b
	testb	%r10b, %r10b
	je		return

_strlen_loop:
	incq	%rax
	incq	%rsi
	movb	(%rsi), %r10b
	testb	%r10b, %r10b
	jne		_strlen_loop

return:
	ret

.section .note.GNU-stack, "", @progbits
