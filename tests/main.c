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
	for (int i = EOF; i < 256; i++) { \
		TEST_CHAR_FN_VAL(fn, i);\
	}\
	if (!fail) { \
		printf(#fn " passed!\n"); \
	} \
}
#endif //TEST_CHAR_FN


int main(void) {
	TEST_CHAR_FN(isalpha);
	TEST_CHAR_FN(isdigit);
	TEST_CHAR_FN(isalnum);
	TEST_CHAR_FN(isascii);
	return (0);
}
