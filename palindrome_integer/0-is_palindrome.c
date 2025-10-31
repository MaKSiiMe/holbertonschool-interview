#include "palindrome.h"

/**
 * is_palindrome - Checks whether or not a given unsigned integer
 *                 is a palindrome
 * @n: The number to be checked
 *
 * Return: 1 if n is a palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long reversed = 0;
	unsigned long original = n;
	unsigned long remainder;

	/* Reverse the number */
	while (n != 0)
	{
		remainder = n % 10;
		reversed = reversed * 10 + remainder;
		n /= 10;
	}

	/* Compare original with reversed */
	if (original == reversed)
		return (1);

	return (0);
}
