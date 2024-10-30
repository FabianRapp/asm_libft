#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <libft.h>
#include <stdbool.h>
# include <string.h>

char *test_strs[] = {
    "!",
    "Hello, world!",
    "OpenAI GPT",
    "C programming is fun",
    "Sample string",
    "Another example",
    "Yet another string",
    "Test case 1",
    "Test case 2",
    "Random text",
    "",
    "End of array",
};

#ifndef CMP_RESULT
# define CMP_RESULT(fn, expect, actual, i, printf_type) \
	if ((expect) != (actual)) { \
	fprintf(stderr, "Fail: " #fn ": for value %" #printf_type " (0x%08x)"\
			": expected: %" #printf_type " actual: %" #printf_type "\n", \
			i, (unsigned)i, expect, actual); \
		fail = true; \
	} \
	else if (0) { \
		fprintf(stderr, "Pass: " #fn ": for value %" #printf_type " (0x%08x)"\
			": expected: %" #printf_type " actual: %" #printf_type "\n", \
				i, (unsigned)i, expect, actual); \
	}
#endif // CMP_RESULT

#ifndef TEST_CHAR_FN
# define TEST_CHAR_FN(fn) \
{ \
	bool	fail = false; \
 \
	for (int i = EOF; i < 256; i++) { \
		int	expect = !!fn((unsigned char)i); \
		int	actual = !!ft_##fn((unsigned char)i); \
		CMP_RESULT(fn, expect, actual, i, d); \
	}\
	if (!fail) { \
		printf(#fn " passed!\n"); \
	} \
}
#endif //TEST_CHAR_FN

#ifndef TEST_1STR_FN
# define TEST_1STR_FN(fn) \
{ \
	bool	fail = false; \
	for (size_t i = 0; i < sizeof test_strs / sizeof test_strs[0]; i++) { \
		size_t	expect = fn(test_strs[i]); \
		size_t	actual = ft_##fn(test_strs[i]); \
		CMP_RESULT(fn, expect, actual, i, lu); \
	} \
	if (!fail) { \
		printf(#fn " passed!\n"); \
	} \
}
#endif // TEST_1STR_FN


int main(void) {
	//printf("sizeof size_t: %lu\n", sizeof(size_t));
	TEST_CHAR_FN(isalpha);
	TEST_CHAR_FN(isdigit);
	TEST_CHAR_FN(isalnum);
	TEST_CHAR_FN(isascii);
	TEST_CHAR_FN(isprint);
	TEST_1STR_FN(strlen);
	return (0);
}
