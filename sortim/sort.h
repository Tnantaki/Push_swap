#ifndef SORT_H
# define SORT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

//utils
void	printArray(int *arr, int n);
void	swap(int *a, int *b);
int		get_max(int *arr, int n);
int		get_min(int *arr, int n);

//sort
void	bubble_sort(int *arr, int n);
void	select_sort(int *arr, int n);
void	insert_sort(int *arr, int n);
void	merge_sort(int *arr, int n);
void	quick_sort(int *arr, int n);
void	heap_sort(int *arr, int n);
void	counting_sort(int *arr, int n);
void	radix_sort(int *arr, int n);

#endif