#include <stdio.h>
#include "libft.h"

int main(void) {
	printf("!: %d\n A: %d\n", ft_isalpha('!'), ft_isalpha('A'));
	printf("@: %d\n g: %d\n", ft_isalpha('@'), ft_isalpha('G'));
	return (0);
}
