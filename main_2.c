#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <dlfcn.h>

void* lib1;
void* lib2;
int (*prime_count_)(int, int);
void (*sort_)(int*, int);

void prime_count() {
	int a, b;
	if (scanf("%d%d", &a, &b) != 2) {
		fprintf(stderr, "Function prime_count error input.\n");
		exit(1);
	}
	printf("The count of prime numbers is %d\n", prime_count_(a, b));
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

void sort() {
	int size;
	if (scanf("%d", &size) != 1) {
		fprintf(stderr, "Function sort size input error\n");
		exit(3);
	}
	int* array = malloc(size * sizeof(int));
	read_array(array, size);
	sort_(array, size);
	print_array(array, size);
}

int main() {
	lib1 = dlopen("lib1.so", RTLD_LAZY);
	if (!lib1) {
		fprintf(stderr, "Cannot open library lib1.so\n");
		return -2;
	}
	lib2 = dlopen("lib2.so", RTLD_LAZY);
	if (!lib2) {
		fprintf(stderr, "Cannot open library lib2.so\n");
		return -2;
	}
	prime_count_ = dlsym(lib1, "prime_count");
	sort_ = dlsym(lib1, "sort");
	int cmd;
	bool first_realise = false;
	printf("Change lib - 0\n");
	printf("prime_count - 1 (int)arg1 (int)arg2\n");
	printf("sort - 2 (int)arg1 (int)arg2 ... \n");
	printf("Enter number the command and args: ");
	while (scanf("%d", &cmd) == 1) {
		if (cmd == 0) {
			if (first_realise) {
				prime_count_ = dlsym(lib1, "prime_count");
				sort_ = dlsym(lib1, "sort");
			} 
			else {
				prime_count_ = dlsym(lib2, "prime_count");
				sort_ = dlsym(lib2, "sort");
			}
			first_realise = !first_realise;
			if (prime_count_ == NULL || sort_ == NULL) {
				fprintf(stderr, "Cannot find functions\n");
				exit(2);
			}
		}
		else if (cmd == 1) {
			prime_count();
		}
		else if (cmd == 2) {
			sort();
		}
		else {
			fprintf(stderr, "Undefined command\n");
			dlclose(lib1);
			dlclose(lib2);
			return -1;
		}
		printf("Enter number the command and args: ");
	}
	dlclose(lib1);
	dlclose(lib2);
	return 0;
}
