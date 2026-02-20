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
 * mul_print - multiply two positive number-strings and print result
 * @s1: first number string
 * @s2: second number string
 */
void mul_print(const char *s1, const char *s2)
{
	size_t n1 = strlen(s1), n2 = strlen(s2);
	size_t len = n1 + n2;
	int *res;
	size_t i, j, start = 0;

	res = calloc(len, sizeof(int));
	if (!res)
		print_error();

	for (i = 0; i < n1; i++)
	{
		int a = s1[n1 - 1 - i] - '0';
		for (j = 0; j < n2; j++)
		{
			int b = s2[n2 - 1 - j] - '0';
			res[i + j] += a * b;
		}
	}

	/* propagate carries */
	for (i = 0; i < len; i++)
	{
		if (res[i] > 9)
		{
			res[i + 1] += res[i] / 10;
			res[i] %= 10;
		}
	}

	/* find most significant non-zero digit */
	for (i = len; i > 0; i--)
	{
		if (res[i - 1] != 0)
		{
			start = i - 1;
			break;
		}
	}

	/* if all zeros, print single 0 */
	if (start == 0 && res[0] == 0)
	{
		putchar('0');
		putchar('\n');
		free(res);
		return;
	}

	/* print digits from most-significant to least */
	for (i = start + 1; i > 0; i--)
		putchar(res[i - 1] + '0');
	putchar('\n');
	free(res);
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
