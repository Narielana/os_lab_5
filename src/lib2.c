#include "my_lib.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int prime_count(int a, int b) {
	printf("Counting prime numbers using the second implementation.\n");
	int cnt = 0;
	int *c = malloc((b + 1)*sizeof(int));
	for (int i = 0; i <= b; i++) {
		c[i] = i;
	}
	for (int i = 2; i <= b; i++) {
		if (c[i] != 0) {
			for (int k = 2*i; k <= b; k += i) {
				c[k] = 0;
			}
		}
	}
	for (int i = a; i <= b; i++) {
		if (c[i] != 0) {
			cnt++;
		}
	}
	free(c);
	return cnt;
}

int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

void sort(int* array, int size) {
	printf("Sorting integers using the second implementation.\n");
	qsort(array, size, sizeof(int), compare);
}
