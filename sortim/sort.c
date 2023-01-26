#include "sort.h"

int main()
{
	// int	arr[] = {10, 80, 30, 60, 40, 50, 70, 90, 20};
	// int	arr[] = {5, 4, 2, 1, 3, -4, -8};
	// int	arr[] = {1, 2, 3, 4, 5};
	// int	arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
	int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };

	int	n = sizeof(arr) / sizeof(arr[0]);
	printf("Given array is \n");
	printArray(arr, n);

	radix_sort(arr, n);

	printf("\nSorted array is \n");
	printArray(arr, n);
// randow high-low arr
	// int m = 19;
	// int n = m;
	// int arr1[m];
	// for (int i = 0, q = m/2; i < n; i++)
	// {
	// 	if (i % 2 == 0)
	// 		arr1[i] = m--;
	// 	else
	// 		arr1[i] = q--;
	// }
	// printArray(arr1, n);
	// printf("-----------------\n");
	// printf("After sorting\n");
	// merge_sort(arr1, n);
	// printArray(arr1, n);
	// printf("-----------------\n");
	return 0;
}
