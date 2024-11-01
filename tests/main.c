#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <libft.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

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

#ifndef PRINT_PASS
# define PRINT_PASS false
#endif //PRINT_PASS


#ifndef CMP_RESULT
# define CMP_RESULT(fn, expect, actual, i, printf_type) \
	if ((expect) != (actual)) { \
		fprintf(stderr, "Fail: " #fn ": for value %" #printf_type " (0x%08x)"\
			": expected: %" #printf_type " actual: %" #printf_type "\n", \
			i, (unsigned)i, expect, actual); \
		fail = true; \
	} \
	else if (PRINT_PASS) { \
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

#ifndef CMP_BUF_RESULTS
# define CMP_BUF_RESULTS(fn, expect, actual, size) \
{\
	if (memcmp(expect, actual, size)) { \
		fprintf(stderr, "Fail: " #fn "\n"); \
		fail = true; \
	} \
	else if (PRINT_PASS) { \
		fprintf(stderr, "Pass: " #fn "\n"); \
	} \
}
#endif // CMP_BUF_RESULTS


#ifndef TEST_BUF_FN
# define TEST_BUF_FN(fn, ...) \
{ \
	for (size_t i = 0; i < sizeof test_strs / sizeof test_strs[0]; i++) { \
		char	*cur = test_strs[i]; \
		void	*expect = strdup(cur); \
		fn(expect, __VA_ARGS__); \
		void	*actual = strdup(cur); \
		ft_##fn(actual, __VA_ARGS__); \
		CMP_BUF_RESULTS(fn, expect, actual, strlen(cur)); \
		free(expect); \
		free(actual); \
	}\
}
#endif //TEST_1BUF_FN

void	test_memset(void) {
	bool	fail = false;
	for (int i = -300; i <= 300; i++ ) {
		TEST_BUF_FN(memset, i, strlen(cur));
	}
	TEST_BUF_FN(memset, INT_MAX, strlen(cur));
	TEST_BUF_FN(memset, INT_MIN, strlen(cur));
	for (size_t i = 0; i < sizeof test_strs / sizeof test_strs[0]; i++) {
		char	*test = strdup(test_strs[i]);
		if (ft_memset(test, i, strlen(test_strs[i])) != test)
			fail = true;
		free(test);
	}
	if (!fail)
		printf("memset passed\n");
}

int main(void) {
	//printf("sizeof size_t: %lu\n", sizeof(size_t));
	TEST_CHAR_FN(isalpha);
	TEST_CHAR_FN(isdigit);
	TEST_CHAR_FN(isalnum);
	TEST_CHAR_FN(isascii);
	TEST_CHAR_FN(isprint);
	TEST_1STR_FN(strlen);

	bool	fail = false;
	TEST_BUF_FN(bzero, strlen(cur));
	if (!fail)
		printf("bzero passed\n");
	test_memset();
	return (0);
}
