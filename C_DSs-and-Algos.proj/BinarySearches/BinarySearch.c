#include <stdlib.h>

int bin_srch(int* array, int first, int last, int searchValue) {
	if (!array) exit(EXIT_FAILURE);
	if (first > last) exit(EXIT_FAILURE);

	int middle = (int)((last - first) / 2);
	if (middle <= first) middle += first;
	int val = array[middle];

	if (searchValue < val) return bin_srch(array, first, middle, searchValue);
	if (searchValue > val) return bin_srch(array, middle, last, searchValue);
	if(val == searchValue) return middle;

	return -1;
}

int binary_search(int* array, int arraySize, int searchValue) {
	if (!array) exit(EXIT_FAILURE);
	return bin_srch(array, 0, arraySize, searchValue);
}