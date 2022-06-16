
#include "palindrome.h"

/**
 * is_palindrome- Reverse the number and compare it to the original.
 *
 * @n: The number to check if it's a palindrome.
 *
 * Return: The function is_palindrome returns 1 if the number is a
 * palindrome, and 0 otherwise.
 */
int is_palindrome(unsigned long n)
{
	unsigned long rev = 0, temp = n;

	while (n)
	{
		rev = rev * 10 + n % 10;
		n /= 10;
	}

	return (rev == temp);
}
