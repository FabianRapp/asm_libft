#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include "../libft.h"
#include <stdbool.h>

void	test_isalpha(void) {
	bool	fail = false;

	for (int c = 0; c <= 500; c++) {
		if (isalpha(c) != ft_isalpha(c)) {
			fail = true;
			fprintf(stderr, "test fail: isalpha: for int(%d) / char(%c): "
				"expected: %d, actual: %d\n",
				c, (char)c, isalpha(c), ft_isalpha(c));
		}
	}
	if (!fail) {
		printf("ft_isalpha passed!\n");
	}
}

int main(void) {
	test_isalpha();
	return (0);
}
