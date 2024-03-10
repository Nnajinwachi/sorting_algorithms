#include "sort.h"

/**
 * counting_sort - function to sort using counting method
 * @array: pointer to the array
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted_arr, i, max;

	if (array == NULL || size < 2)
		return;
	sorted_arr = malloc(sizeof(int) * size);
	if (sorted_arr == NULL)
		return;
	max = max_func(array, size) + 1;
	count = malloc(sizeof(int) * max);
	if (count == NULL)
	{
		free(sorted_arr);
		return;
	}

	for (i = 0; i < max; i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]]++;
	for (i = 0; i < max; i++)
		count[i] += count[i - 1];
	print_array(count, max);

	for (i = 0; i < (int)size; i++)
	{
		sorted_arr[--count[array[i]]] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted_arr[i];

	free(sorted_arr);
	free(count);
}

/**
 * max_func - function to determine maximum value
 * @array: pointer to the array
 * @size: size of the array
 *
 * Return: max value
 */
int max_func(int *array, int size)
{
	int max = array[0];
	int i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}
