#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;



/* functions to print the list and array */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* sorting functions */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

/* helper functions */
void swap_fun(int *i, int *j);
void swap_sort(int *array, int i, int j);
int split(int *array, int first_val, int sec_val, size_t size);
void sorting(int *array, int first_val, int sec_val, size_t size);
int max_func(int *array, int size);
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
				size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);

#endif
