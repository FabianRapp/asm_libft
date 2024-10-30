#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <libft.h>
#include <stdbool.h>

//expects 'bool fail' to exist
#ifndef TEST_CHAR_FN_VAL
# define TEST_CHAR_FN_VAL(fn, val) \
do {\
	int	expect = !!fn((unsigned char)val); \
	int	actual = !!ft_##fn((unsigned char)val); \
	if (expect != actual) { \
		fprintf(stderr, "Fail: " #fn ": for value %d (0x%08x)"\
			": expected: %d actual: %d\n", val, val, expect, actual); \
		fail = true; \
	} \
	else if (0) { \
		fprintf(stderr, "Pass: " #fn ": for value %d (0x%08x)"\
			": expected: %d actual: %d\n", val, val, expect, actual); \
	} \
} while(0)
#endif // TEST_CHAR_FN_VAL

#ifndef TEST_CHAR_FN
# include <limits.h>
# define TEST_CHAR_FN(fn) \
{ \
	bool	fail = false; \
 \
	int	c = -500; \
	while (c <= 500) { \
		int	expect = fn(c); \
		int	actual = ft_##fn(c); \
		if (expect != actual) { \
			fail = true; \
			fprintf(stderr, "test fail: " #fn ": for int(%d) / char(%c): " \
				"expected: %d, actual: %d\n", \
				c, (char)c, actual, expect); \
		} \
		c++; \
	} \
	{ \
		c = INT_MAX; \
		int	expect = fn(c); \
		int	actual = ft_##fn(c); \
		if (expect != actual) { \
			fail = true; \
			fprintf(stderr, "test fail: " #fn ": for int(%d) / char(%c): " \
				"expected: %d, actual: %d\n", \
				c, (char)c, actual, expect); \
		} \
	} \
	{ \
		c = INT_MIN; \
		int	expect = fn(c); \
		int	actual = ft_##fn(c); \
		if (expect != actual) { \
			fail = true; \
			fprintf(stderr, "test fail: " #fn ": for int(%d) / char(%c): " \
				"expected: %d, actual: %d\n", \
				c, (char)c, actual, expect); \
		} \
	} \
	if (!fail) { \
		printf(#fn " passed!\n"); \
	} \
}
#endif //TEST_CHAR_FN


int main(void) {
	bool	fail = false;

/*
	for (int i = EOF; i < 530; i++) {
		TEST_CHAR_FN_VAL(isalpha, i);
	}
	for (int i = EOF; i < 530; i++) {
		TEST_CHAR_FN_VAL(isdigit, i);
	}
*/
	for (int i = EOF; i < 530; i++) {
		TEST_CHAR_FN_VAL(isalnum, i);
	}
	if (!fail) {
		printf("passed\n");
	}
	return (0);
}
