#include "holberton.h"

/**
 * main - the entry point
 * @argc: Number of arguments
 * @argv: Arguments to multiply
 * Return: return 0, 98 otherwise and prints Error
 */
int main(int argc, char *argv[])
{
	int multi, res, total_len, number1_length, number2_length, i, j, *total;

	if (argc < 3 || argc > 3 || !(_isdigit(argv[1])) || !(_isdigit(argv[2])))
		puts("Error"), exit(98);
	if (argv[1][0] == '0' || argv[2][0] == '0')
	{
		printf("0\n");
		return (0);
	}
	number1_length = _strlen(argv[1]), number2_length = _strlen(argv[2]);
	total_len = number1_length + number2_length;
	total = calloc(total_len, sizeof(int *));
	if (total == NULL)
		puts("Error"), exit(98);
	for (i = (number2_length - 1); i > -1; i--)
	{
		res = 0;
		for (j = (number1_length - 1); j > -1; j--)
		{
			multi = (argv[2][i] - '0') * (argv[1][j] - '0');
			res = (multi / 10);
			total[(i + j) + 1] += (multi % 10);
			if (total[(i + j) + 1] > 9)
			{
				total[i + j] += total[(i + j) + 1] / 10;
				total[(i + j) + 1] = total[(i + j) + 1] % 10;
			}
			total[(i + j)] += res;
		}
	}
	if (total[0] == 0)
		i = 1;
	else
		i = 0;
	for (; i < total_len; i++)
		printf("%d", total[i]);
	printf("\n");
	free(total);
	return (0);
}

/**
 * _strlen - Return the len of a string
 * Description: This function shows the length of a given string
 * @s: Pointer that contains the string
 * Return: string length
 */
int _strlen(const char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

/**
 * _isdigit - check if a string is a digit
 * Description - This function is to check if a string is a digit
 * @n: char to check if is a digit
 * Return: 1 if n is a digit, 0 otherwise
 */
int _isdigit(char *n)
{
	int i = 0;

	while (*(n + i) != '\0')
	{
		if (*(n + i) < '0' || *(n + i) > '9')
			return (0);
		i++;
	}
	return (1);
}
