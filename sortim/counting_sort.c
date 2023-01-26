#include "sort.h"
#include <string.h>

void	counting_sort(int *arr, int n)
{
	int	max = get_max(arr, n);
	int	min = get_min(arr, n);
	int	output[n];
	int range = max - min + 1;
	int count[range];

	printf("range:%d \n", range);
	memset(count, 0, sizeof(count));
	for (int i = 0; i < n; i++)
		count[arr[i] - min]++;
	for (int i = 1; i < range; i++)
		count[i] += count[i - 1];
	for (int i = n - 1; i >= 0; i--)
	{
		output[count[arr[i] - min] - 1] = arr[i];
		count[arr[i] - min]--;
	}
	for (int i = 0; i < n; i++)
		arr[i] = output[i];
}
