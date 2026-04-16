#include "substring.h"
#include <stdlib.h>
#include <string.h>

/**
 * find_substring - Finds all substrings that are concatenations of words
 * @s: The string to scan
 * @words: Array of words that must be concatenated
 * @nb_words: Number of words in the array
 * @n: Pointer to store the number of found indices
 *
 * Return: Allocated array of indices, or NULL if none found
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int word_len;
	int total_len;
	int s_len;
	int *result;
	int result_count;
	int i;
	int j;
	int k;
	int *word_used;
	int found;
	int valid;

	if (!s || !words || nb_words <= 0 || !n)
		return (NULL);

	s_len = strlen(s);
	word_len = strlen(words[0]);
	total_len = word_len * nb_words;

	if (s_len < total_len)
	{
		*n = 0;
		return (NULL);
	}

	result = malloc((s_len - total_len + 2) * sizeof(int));
	if (!result)
		return (NULL);

	word_used = malloc(nb_words * sizeof(int));
	if (!word_used)
	{
		free(result);
		return (NULL);
	}

	result_count = 0;

	/* For each starting position in the string */
	for (i = 0; i <= s_len - total_len; i++)
	{
		/* Initialize word used array for this position */
		for (j = 0; j < nb_words; j++)
			word_used[j] = 0;

		/* Check if substring starting at position i is valid */
		valid = 1;
		for (j = 0; j < nb_words; j++)
		{
			/* Try to find a matching word for this chunk */
			found = 0;
			for (k = 0; k < nb_words; k++)
			{
				/* Check if word k hasn't been used and matches this chunk */
				if (!word_used[k] && 
					strncmp(s + i + j * word_len, words[k], word_len) == 0)
				{
					word_used[k] = 1;
					found = 1;
					break;
				}
			}

			/* If no matching word found for this chunk, position is invalid */
			if (!found)
			{
				valid = 0;
				break;
			}
		}

		/* If all chunks matched, add this position to results */
		if (valid)
			result[result_count++] = i;
	}

	free(word_used);

	*n = result_count;

	/* Return NULL if no valid substrings found */
	if (result_count == 0)
	{
		free(result);
		return (NULL);
	}

	return (result);
}
