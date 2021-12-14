#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "my_lib.h"

void prime_count_() {
	int a, b;
	if (scanf("%d%d", &a, &b) != 2) {
		fprintf(stderr, "Function prime_count error input.\n");
		exit(1);
	}
	printf("The count of prime numbers is %d\n", prime_count(a, b));
}

void read_array(int* array, size_t size) {
	for (size_t i = 0; i < size; ++i) {
		if (scanf("%d", array + i) != 1) {
			fprintf(stderr, "Function sort array input error\n");
			exit(2);
		}
	}
}

void print_array(int* array, size_t size) {
	printf("Sorted sequence: ");
	for (size_t i = 0; i < size; ++i) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

void sort_() {
	int size;
	if (scanf("%d", &size) != 1) {
		fprintf(stderr, "Function sort size input error\n");
		exit(3);
	}
	int* array = malloc(size * sizeof(int));
	read_array(array, size);
	sort(array, size);
	print_array(array, size);
}

int main() {
	int cmd;
	printf("prime_count - 1 (int)arg1 (int)arg2\n");
	printf("sort - 2 (int)arg1 (int)arg2 ... \n");
	printf("Enter number the command and args: ");
	while (scanf("%d", &cmd) == 1) {
		if (cmd == 1) {
			prime_count_();
		}
		else if (cmd == 2) {
			sort_();
		}
		else {
			fprintf(stderr, "Undefined command.\n");
		}
		printf("Enter number the command and args: ");
	}
	return 0;
}
