#include "substring.h"
#include <stdlib.h>
#include <string.h>

/**
 * is_valid_substring - Check if substring at position is valid concatenation
 * @s: The string
 * @pos: Position to start checking
 * @words: Array of words
 * @nb_words: Number of words
 * @word_len: Length of each word
 *
 * Return: 1 if valid, 0 otherwise
 */
static int is_valid_substring(char const *s, int pos, char const **words,
int nb_words, int word_len)
{
int *word_used;
int i;
int j;
int found;

word_used = malloc(nb_words * sizeof(int));
if (!word_used)
return (0);

for (i = 0; i < nb_words; i++)
word_used[i] = 0;

for (i = 0; i < nb_words; i++)
{
found = 0;
for (j = 0; j < nb_words; j++)
{
if (!word_used[j] &&
strncmp(s + pos + i * word_len, words[j], word_len) == 0)
{
word_used[j] = 1;
found = 1;
break;
}
}
if (!found)
{
free(word_used);
return (0);
}
}
free(word_used);
return (1);
}

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

if (!s || !words || nb_words <= 0 || !n)
return (NULL);

s_len = strlen(s);
word_len = strlen(words[0]);
	total_len = word_len *nb_words;

if (s_len < total_len)
{
*n = 0;
return (NULL);
}

result = malloc((s_len - total_len + 2) * sizeof(int));
if (!result)
return (NULL);

result_count = 0;

/*
 * For each starting position in the string
 */
for (i = 0; i <= s_len - total_len; i++)
{
if (is_valid_substring(s, i, words, nb_words, word_len))
result[result_count++] = i;
}

*n = result_count;

/*
 * Return NULL if no valid substrings found
 */
if (result_count == 0)
{
free(result);
return (NULL);
}

return (result);
}
