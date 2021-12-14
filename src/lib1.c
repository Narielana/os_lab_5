#include "my_lib.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int prime_count(int a, int b) {
	printf("Counting prime numbers using the first implementation.\n");
	int cnt = 0;
	bool is_prime = true;
	for (int i = a; i <= b; i++) {
		for (int j = 2; j*j <= i; j++) {
			if (i % j == 0) {
				is_prime = false;
				break;
			}
		}
		if (is_prime && i != 1) {
			cnt++;
		}
		is_prime = true;
	}
	return cnt;
}

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void sort(int *array, int size) {
	printf("Sorting integers using the first implementation.\n");
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size - 1; ++j) {
			if (array[j] > array[j + 1]) {
				swap(array + j, array + j + 1);
			}
		}
	}
}
