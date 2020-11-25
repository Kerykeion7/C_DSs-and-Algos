#include <stdlib.h>

int binary_search(int* array, int arraySize, int searchValue) {
	if (!array) exit(EXIT_FAILURE);
	int middle = (int)(arraySize / 2);
	int val = array[middle];

	if (arraySize > 1)
	{
		if (searchValue < val) {
			int* left = (int*)malloc(middle * sizeof(int));
			if (!left) exit(EXIT_FAILURE);
			for (int i = 0; i < middle; i++)
			{
				*(left + i) = array[i];
			}
			return binary_search(left, middle, searchValue);
		}
		if (searchValue > val)
		{
			int s = arraySize - middle;
			int j = s;
			int* right = (int*)malloc(s * sizeof(int));
			if (!right) exit(EXIT_FAILURE);
			for (int i = 0; i < arraySize - middle; i++)
			{
				right[i] = array[j];
				j++;
			}
			return binary_search(right, s, searchValue);
		}
	}

	return val;
}