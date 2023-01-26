#include "sort.h"

void	insert_sort(int *arr, int n)
{
	int key;
	int j;

	for (int i = 1; i < n; i++)
	{
		key = arr[i];
		j = i;
		for (; j > 0 && key < arr[j - 1]; j--)
			arr[j] = arr[j - 1];
		arr[j] = key;
	}
}