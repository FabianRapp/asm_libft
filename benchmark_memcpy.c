
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "libft.h"

#define TINY_SIZE 1            // Tiny range size
#define SMALL_SIZE 7          // Small range size
#define MEDIUM_SIZE  25      // Medium range size
#define LARGE_SIZE 100       // Large range size
#define LARGE_SIZE2 200       // Large range size
#define LARGE_SIZE3 400       // Large range size
#define LARGE_SIZE4 800       // Large range size
#define LARGE_SIZE5 2000       // Large range size
#define HUGE_SIZE 1048576      // Huge range size (1 MB)
#define REPEAT 10000            // Number of repetitions for each test
#ifndef DO_RANDOM_STUFF
# define DO_RANDOM_STUFF \
	do { \
		const size_t s = 100; \
		volatile long long buf[s]; \
		for (size_t i = 0; i < 1000; i++) { \
			buf[i % s] = buf[s - (i % s) - 1]; \
		}\
	} while (0)
#endif //DO_RANDOM_STUFF

void benchmark(void *(*memcpy_func)(void *, const void *, size_t),
	const char *func_name, char *dest, char volatile *src, volatile size_t size) {
    clock_t start, end;
    double cpu_time_used;

    // Start timing
	DO_RANDOM_STUFF;
    start = clock();

    for (int i = 0; i < REPEAT; i++) {
        memcpy_func(dest, (char *)src, (size_t)size);
		src[size - 1]++;
    }

    // End timing
    end = clock();
	DO_RANDOM_STUFF;
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Print results
    printf("%s (%zu bytes) took %f seconds for %d repetitions\n", func_name, size, cpu_time_used, REPEAT);
}


//alignmend seems not to be the issue for ranges of 10^2 - 10^
//somehow ft_memcpy seems to consitantly perform 25% worse for aligned data of 1mb vs unaliged
void	*malloc(size_t s) {
	if (1) {
		return (aligned_alloc(512, s));
	} else {
		return (calloc(s, 1));
	}
}

int main() {
    // Allocate memory for the source and destination buffers for each size
    char *src_tiny = malloc(TINY_SIZE);
    char *dest_std_tiny = malloc(TINY_SIZE);
    char *dest_ft_tiny = malloc(TINY_SIZE);

    char *src_small = malloc(SMALL_SIZE);
    char *dest_std_small = malloc(SMALL_SIZE);
    char *dest_ft_small = malloc(SMALL_SIZE);

    char *src_medium = malloc(MEDIUM_SIZE);
    char *dest_std_medium = malloc(MEDIUM_SIZE);
    char *dest_ft_medium = malloc(MEDIUM_SIZE);

    char *src_large = malloc(LARGE_SIZE);
    char *dest_std_large = malloc(LARGE_SIZE);
    char *dest_ft_large = malloc(LARGE_SIZE);

    char *src_large2 = malloc(LARGE_SIZE2);
    char *dest_std_large2 = malloc(LARGE_SIZE2);
    char *dest_ft_large2 = malloc(LARGE_SIZE2);

    char *src_large3 = malloc(LARGE_SIZE3);
    char *dest_std_large3 = malloc(LARGE_SIZE3);
    char *dest_ft_large3 = malloc(LARGE_SIZE3);
    char *src_large4 = malloc(LARGE_SIZE4);
    char *dest_std_large4 = malloc(LARGE_SIZE4);
    char *dest_ft_large4 = malloc(LARGE_SIZE4);
    char *src_large5 = malloc(LARGE_SIZE5);
    char *dest_std_large5 = malloc(LARGE_SIZE5);
    char *dest_ft_large5 = malloc(LARGE_SIZE5);

    char *src_huge = malloc(HUGE_SIZE);
    char *dest_std_huge = malloc(HUGE_SIZE);
    char *dest_ft_huge = malloc(HUGE_SIZE);

    // Initialize the source buffers with some data
    memset(src_tiny, 'A', TINY_SIZE);
    memset(src_small, 'B', SMALL_SIZE);
    memset(src_medium, 'C', MEDIUM_SIZE);
    memset(src_large, 'D', LARGE_SIZE);
    memset(src_large2, 'D', LARGE_SIZE);
    memset(src_large3, 'D', LARGE_SIZE);
    memset(src_large4, 'D', LARGE_SIZE);
    memset(src_large5, 'D', LARGE_SIZE);
    memset(src_huge, 'E', HUGE_SIZE);

	void	*(*const fn2)(void *, const void *, size_t) = memcpy;
	void	*(*const fn1)(void*, const void *, size_t) = ft_memcpy;

    // Benchmark for tiny size
    benchmark(fn1, "Standard memcpy", dest_std_tiny, src_tiny, TINY_SIZE);
    benchmark(fn2, "Custom ft_memcpy", dest_ft_tiny, src_tiny, TINY_SIZE);
	printf("\n");

    // Benchmark for small size
    benchmark(fn1, "Standard memcpy", dest_std_small, src_small, SMALL_SIZE);
    benchmark(fn2, "Custom ft_memcpy", dest_ft_small, src_small, SMALL_SIZE);
	printf("\n");

    // Benchmark for medium size
    benchmark(fn1, "Standard memcpy", dest_std_medium, src_medium, MEDIUM_SIZE);
    benchmark(fn2, "Custom ft_memcpy", dest_ft_medium, src_medium, MEDIUM_SIZE);
	printf("\n");

    // Benchmark for large size
    benchmark(fn1, "Standard memcpy", dest_std_large, src_large, LARGE_SIZE);
    benchmark(fn2, "Custom ft_memcpy", dest_ft_large, src_large, LARGE_SIZE);
	printf("\n");

    benchmark(fn1, "Standard memcpy", dest_std_large2, src_large2, LARGE_SIZE2);
    benchmark(fn2, "Custom ft_memcpy", dest_ft_large2, src_large2, LARGE_SIZE2);
	printf("\n");

    benchmark(fn1, "Standard memcpy", dest_std_large3, src_large3, LARGE_SIZE3);
    benchmark(fn2, "Custom ft_memcpy", dest_ft_large3, src_large3, LARGE_SIZE3);
	printf("\n");

    benchmark(fn1, "Standard memcpy", dest_std_large4, src_large4, LARGE_SIZE4);
    benchmark(fn2, "Custom ft_memcpy", dest_ft_large4, src_large4, LARGE_SIZE4);
	printf("\n");

    benchmark(fn1, "Standard memcpy", dest_std_large5, src_large5, LARGE_SIZE5);
    benchmark(fn2, "Custom ft_memcpy", dest_ft_large5, src_large5, LARGE_SIZE5);
	printf("\n");

    // Benchmark for huge size
    benchmark(fn1, "Standard memcpy", dest_std_huge, src_huge, HUGE_SIZE);
    benchmark(fn2, "Custom ft_memcpy", dest_ft_huge, src_huge, HUGE_SIZE);
	printf("\n");

    // Cleanup
    free(src_tiny);
    free(dest_std_tiny);
    free(dest_ft_tiny);

    free(src_small);
    free(dest_std_small);
    free(dest_ft_small);

    free(src_medium);
    free(dest_std_medium);
    free(dest_ft_medium);

    free(src_large);
    free(dest_std_large);
    free(dest_ft_large);

    free(src_large2);
    free(dest_std_large2);
    free(dest_ft_large2);

    free(src_large3);
    free(dest_std_large3);
    free(dest_ft_large3);

    free(src_large4);
    free(dest_std_large4);
    free(dest_ft_large4);

    free(src_large5);
    free(dest_std_large5);
    free(dest_ft_large5);

    free(src_huge);
    free(dest_std_huge);
    free(dest_ft_huge);

    return 0;
}

