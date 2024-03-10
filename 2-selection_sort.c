#include "sort.h"

/**
 * selection_sort - function to display list using selection algorithm
 * @array: list of array to be sorted
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int *min_value;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < (size - 1); i++)
	{
		min_value = array + i;
		for (j = (i + 1); j < size; j++)
		{
			min_value = (array[j] < *min_value) ? (array + j) : min_value;
		}
		if ((array + i) != min_value)
		{
			swap_fun(array + i, min_value);
			print_array(array, size);
		}
	}
}

/**
 * swap_fun - function to swap the values of a list
 * @i: pointer to the first argument passed
 * @j: pointer to the second argumebt passed
 */
void swap_fun(int *i, int *j)
{
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
}
