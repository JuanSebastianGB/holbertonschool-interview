#include "substring.h"

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int *indices;
	int i;
	int j;
	int k;
	int l;
	int m;
	int len;
	int count;
	int *check;

	*n = 0;
	if (s == NULL || words == NULL || nb_words == 0)
		return (NULL);
	len = strlen(s);
	indices = malloc(sizeof(int) * len);
	check = malloc(sizeof(int) * nb_words);
	for (i = 0; i < len; i++)
	{
		for (j = 0; j < nb_words; j++)
			check[j] = 0;
		count = 0;
		for (j = i; j < len; j++)
		{
			for (k = 0; k < nb_words; k++)
			{
				if (check[k] == 0)
				{
					for (l = 0; words[k][l] != '\0'; l++)
					{
						if (s[j + l] != words[k][l])
							break;
					}
					if (words[k][l] == '\0')
					{
						check[k] = 1;
						count++;
						j += l - 1;
						break;
					}
				}
			}
			if (count == nb_words)
			{
				indices[*n] = i;
				(*n)++;
				break;
			}
		}
	}
	free(check);
	return (indices);
}
