#include "slide_line.h"

/**
 * slide - It takes a line of numbers, an index, and a placeholder,
 * and if the number at the index is not zero,it adds it to the
 * number at the placeholder and sets the number at the index to zero
 *
 * @line: the array of integers
 * @index: the index of the tile to be moved
 * @placeholder: the index of the tile that is being moved to
 */
void slide(int *line, int index, int placeholder)
{
	line[placeholder] += line[index];
	line[index] = 0;
}

/**
 * slide_right - It slides the numbers to the right, and if two
 * numbers are equal,
 * it adds them together
 *
 * @aux_index: the index of the last non-zero element in the line
 * @line: the array of integers
 * @index: the index of the current number in the line
 * @size: the size of the array
 */
void slide_right(int aux_index, int *line, int index, int size)
{
	for (index = size; index >= 0; index--)
	{
		if (line[index] == line[aux_index] && line[index])
		{
			slide(line, index, aux_index--);
			continue;
		}
		if (line[index] != line[aux_index] && line[index])
		{
			if (line[aux_index] != 0)
				aux_index--;
			if (line[aux_index] == 0)
				slide(line, index, aux_index);
		}
	}
}

/**
 * slide_left - It slides the numbers to the left, and if two numbers
 * are equal, it adds them
 *
 * @aux_index: the index of the first non-zero number in the line
 * @initial: the index of the first element of the line
 * @line: the array of integers
 * @index: the index of the current number in the line
 * @size: the size of the array
 */
void slide_left(int aux_index, int initial, int *line, int index, int size)
{
	for (index = initial; index < (int)size; index++)
	{
		if (line[index] == line[aux_index] && line[index])
			slide(line, index, aux_index++);
		else if (line[index] != line[aux_index] && line[index])
		{
			if (line[aux_index] != 0)
				aux_index++;
			if (line[aux_index] == 0)
				slide(line, index, aux_index);
		}
	}
}

/**
 * slide_line - takes an array of integers,
 * the size of the array, and a direction (left
 * or right) as parameters. It then slides the array
 * in the direction specified and returns 1 if
 * successful or 0 if not
 *
 * @line: array of integers
 * @size: the size of the array
 * @direction: the direction to slide and merge the numbers
 *
 * Return: 1 if the line was successfully slid, otherwise 0.
 */
int slide_line(int *line, size_t size, int direction)
{
	int index = 0, initial = 1;

	if (size < 1 || (direction != SLIDE_RIGHT && direction != SLIDE_LEFT))
		return (0);

	if (direction == SLIDE_RIGHT)
		slide_right((size - 1), line, index, (size - 2));
	if (direction == SLIDE_LEFT)
		slide_left(0, initial, line, index, size);
	return (1);
}
