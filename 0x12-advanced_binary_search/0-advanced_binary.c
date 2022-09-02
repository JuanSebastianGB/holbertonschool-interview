#include "search_algos.h"

/**
 * advanced_binary - searches for a value in a sorted array of integers.
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 * Return: Index where value is located
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (size == 0 || !array)
		return (-1);
	return (binary_search(array, 0, size - 1, value));
}

/**
 * binary_search - Recursive Function to implement binary search algorithm
 * @array: array to search into
 * @min_value: minimum value to implement search
 * @max_value: maximum value to implement search
 * @value: Index to find
 * Return: value and index
 */
int binary_search(int *array, int min_value, int max_value, int value)
{
	int counter, mid;

	if (max_value < min_value)
		return (-1);
	printf("Searching in array: ");
	for (counter = min_value; counter <= max_value; counter++)
	{
		printf("%d", array[counter]);
		if (counter == max_value)
			printf("\n");
		else
			printf(", ");
	}
	if (min_value == max_value && array[max_value] == value)
		return (max_value);
	if (min_value == max_value && array[max_value] != value)
		return (-1);
	mid = min_value + ((max_value - min_value) / 2);
	if (
		(value != array[mid - 1] || mid == min_value) && array[mid] == value)
		return (mid);
	if (array[mid] >= value)
		return (binary_search(array, min_value, mid, value));
	return (binary_search(array, mid + 1, max_value, value));
}
