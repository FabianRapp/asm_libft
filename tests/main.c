#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include "../libft.h"

void	test_isalpha(void) {
	for (int c = 0; c <= 500; c++) {
		if (isalpha(c) != ft_isalpha(c)) {
			fprintf(stderr, "test fail: isalpha: for int(%d) / char(%c): "
				"expected: %d, actual: %d\n",
				c, (char)c, isalpha(c), ft_isalpha(c));
		}
	}
}


int main(void) {
	//test_isalpha();
	for (int c = 30; c <= 70; c++) {
		printf("%d(%c): %d\n", c, c, ft_isalpha(c));
	}
	return (0);
}
