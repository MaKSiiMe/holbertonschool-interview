#include "regex.h"
#include <stddef.h>

/**
 * regex_match - Checks whether a pattern matches a string
 * @str: The string to scan
 * @pattern: The regular expression pattern
 *
 * Return: 1 if pattern matches, 0 otherwise
 */
int regex_match(char const *str, char const *pattern)
{
	/*
	 * Base case: both empty
	 */
	if (pattern == NULL || pattern[0] == '\0')
		return (str == NULL || str[0] == '\0');

	/*
	 * Check if next character in pattern is '*'
	 */
	if (pattern[1] != '\0' && pattern[1] == '*')
	{
		/*
		 * Case 1: match zero occurrences of pattern[0]
		 * (skip pattern[0] and pattern[1])
		 */
		if (regex_match(str, pattern + 2))
			return (1);

		/*
		 * Case 2: if first character matches, match one occurrence
		 * and try again with same pattern (because * allows multiple)
		 */
		if ((pattern[0] == '.' || pattern[0] == str[0]) && str[0] != '\0')
			return (regex_match(str + 1, pattern));

		return (0);
	}

	/*
	 * Regular character matching (no * following)
	 * Check if first characters match
	 */
	if ((pattern[0] == '.' || pattern[0] == str[0]) && str[0] != '\0')
		return (regex_match(str + 1, pattern + 1));

	return (0);
}
