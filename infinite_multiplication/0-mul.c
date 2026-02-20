#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * print_error - print "Error" and exit with status 98
 */
void print_error(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * is_digit_str - check that a string contains only digit characters
 * @s: input string
 *
 * Return: 1 if only digits, 0 otherwise
 */
int is_digit_str(const char *s)
{
	size_t i;

	if (!s)
		return (0);
	for (i = 0; s[i]; i++)
	{
		if (!isdigit((unsigned char)s[i]))
			return (0);
	}
	return (1);
}

/**
 * multiply_strs - multiply two positive numeric strings
 * @s1: first number string (base 10)
 * @s2: second number string (base 10)
 * @len_out: pointer to store length of returned array
 *
 * Description: returns a newly allocated array of digits (LSB first)
 * representing the product of @s1 and @s2. Caller must free the array.
 *
 * Return: pointer to int array on success, NULL on allocation failure
 */
static int *multiply_strs(const char *s1, const char *s2, size_t *len_out)
{
	size_t n1 = strlen(s1), n2 = strlen(s2);
	size_t len = n1 + n2;
	int *res;
	size_t i, j;

	res = calloc(len, sizeof(int));
	if (!res)
		return (NULL);

	for (i = 0; i < n1; i++)
	{
		int a = s1[n1 - 1 - i] - '0';

		for (j = 0; j < n2; j++)
			res[i + j] += a * (s2[n2 - 1 - j] - '0');
	}

	for (i = 0; i < len; i++)
	{
		if (res[i] > 9)
		{
			res[i + 1] += res[i] / 10;
			res[i] %= 10;
		}
	}

	*len_out = len;
	return (res);
}

/**
 * print_and_free - print number from digit-array (LSB first) and free it
 * @res: integer array of digits (least-significant digit first)
 * @len: length of the array
 *
 * Prints the numeric value represented by @res and frees the memory.
 */
static void print_and_free(int *res, size_t len)
{
	size_t i, start = 0;

	for (i = len; i > 0; i--)
	{
		if (res[i - 1] != 0)
		{
			start = i - 1;
			break;
		}
	}

	if (start == 0 && res[0] == 0)
	{
		putchar('0');
		putchar('\n');
		free(res);
		return;
	}

	for (i = start + 1; i > 0; i--)
		putchar(res[i - 1] + '0');
	putchar('\n');
	free(res);
}

/**
 * mul_print - multiply two numeric strings and print the product
 * @s1: first positive number string
 * @s2: second positive number string
 *
 * Uses `multiply_strs` and `print_and_free` to compute and display the
 * multiplication result for arbitrarily large positive integers.
 */
void mul_print(const char *s1, const char *s2)
{
	size_t len;
	int *res = multiply_strs(s1, s2, &len);

	if (!res)
		print_error();

	print_and_free(res, len);
}

/**
 * main - entry point for infinite multiplication
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, or exits with 98 on error
 */
int main(int argc, char **argv)
{
	if (argc != 3)
		print_error();
	if (!is_digit_str(argv[1]) || !is_digit_str(argv[2]))
		print_error();

	mul_print(argv[1], argv[2]);
	return (0);
}
