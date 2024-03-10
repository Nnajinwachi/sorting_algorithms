#include "sort.h"

/**
 * swap_sort - function to swap values
 * @array: pointer to the array
 * @i: first value
 * @j: second_value
 */
void swap_sort(int *array, int i, int j)
{
	int tmp = array[i];

	array[i] = array[j];
	array[j] = tmp;
}

/**
 * quick_sort - function to the quick_sort sorting algorithm
 * @array: pointer to the array
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	sorting(array, 0, (size - 1), size);
}

/**
 * split - function to split the unsorted list
 * @array: pointer to the array
 * @first_val: first value
 * @sec_val: second value
 * @size: size of the array
 *
 * Return: the minimum value
 */
int split(int *array, int first_val, int sec_val, size_t size)
{
	int pivot, x, y;

	pivot = array[sec_val];
	x = first_val;

	for (y = first_val; y < sec_val; y++)
	{
		if (array[y] < pivot)
		{
			if (x != y)
			{
				swap_sort(array, y, x);
				print_array(array, size);
			}
			x++;
		}
	}
	if (array[x] != array[sec_val])
	{
		swap_sort(array, x, sec_val);
		print_array(array, size);
	}

	return (x);
}

/**
 * sorting - function to sort the list
 * @array: pointer to the array
 * @first_val: first value
 * @sec_val: second value
 * @size: size of the array
 */
void sorting(int *array, int first_val, int sec_val, size_t size)
{
	int pivot;

	if (first_val < sec_val)
	{
		pivot = split(array, first_val, sec_val, size);
		sorting(array, first_val, (pivot - 1), size);
		sorting(array, (pivot + 1), sec_val, size);
	}
}
