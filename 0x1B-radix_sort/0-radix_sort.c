#include "sort.h"

/**
 * swap - Change the greatest with the lowest value
 * @arr: original array
 * @digit: array of least significant digits
 * @mv_idx: array idx to move
 * @mv_to: array idx to move mv_idx to
 *
 * Return: nothing
 **/
void swap(int *arr, int *digit, int mv_idx, int mv_to)
{
	int tmp = arr[mv_idx];
	int tmp2 = digit[mv_idx];

	while (mv_idx > mv_to)
	{
		arr[mv_idx] = arr[mv_idx - 1];
		digit[mv_idx] = digit[mv_idx - 1];
		mv_idx--;
	}
	arr[mv_to] = tmp;
	digit[mv_to] = tmp2;
}

/**
 * radix_sort - radix sort
 *
 * @array: array of integers t sort
 * @size: number of elements in array
 *
 * Return: nothing
 **/
void radix_sort(int *array, size_t size)
{
	int *lsd, max_digits = 0;
	int i = -1, j = -1, k, l, tens, digits, size2, num;

	if (size < 2)
		return;
	lsd = malloc(sizeof(int) * size);
	if (!lsd)
		return;
	size2 = (int)size;
	while (i++ < size2 - 1)
	{
		digits = 0;
		num = array[i];
		while (num > 0)
		{
			num /= 10;
			digits++;
		}
		if (digits > max_digits)
			max_digits = digits;
	}
	i = 0;
	tens = 1;
	while (i++ < max_digits)
	{
		if (i == 10)
			tens /= 10;
		else
			tens *= 10;
		j = -1;
		while (j++ < size2 - 1)
		{
			if (i == 10)
				lsd[j] = array[j] / tens / 10;
			else
				lsd[j] = array[j] % tens / (tens / 10);
		}
		k = 0;
		while (k++ < size2 - 1)
		{
			l = -1;
			while (l++ < k)
				if (lsd[k] < lsd[l])
					swap(array, lsd, k, l);
		}
		print_array(array, size);
	}
	free(lsd);
}
