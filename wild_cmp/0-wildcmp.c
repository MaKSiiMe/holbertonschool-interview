#include "holberton.h"

/**
 * skip_stars - skip consecutive '*' characters in a pattern string
 * @s2: pointer to the pattern string
 *
 * Return: pointer to the first non-'*' character or the last '*' in a run
 */
char *skip_stars(char *s2)
{
	if (*s2 == '*' && *(s2 + 1) == '*')
		return (skip_stars(s2 + 1));
	return (s2);
}

/**
 * wildcmp - compare two strings allowing '*' wildcards in s2
 * @s1: first string to compare
 * @s2: second string containing wildcards
 *
 * Return: 1 if the strings can be considered identical, otherwise 0
 */
int wildcmp(char *s1, char *s2)
{
	if (*s2 == '*')
	{
		s2 = skip_stars(s2);
		if (*(s2 + 1) == '\0')
			return (1);
		if (wildcmp(s1, s2 + 1))
			return (1);
		if (*s1 == '\0')
			return (0);
		return (wildcmp(s1 + 1, s2));
	}
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s1 == '\0' || *s2 == '\0')
		return (0);
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));
	return (0);
}
