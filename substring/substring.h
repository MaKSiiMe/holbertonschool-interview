#ifndef SUBSTRING_H
#define SUBSTRING_H

/**
 * find_substring - Finds all substrings that are concatenations of words
 * @s: The string to scan
 * @words: Array of words that must be concatenated
 * @nb_words: Number of words in the array
 * @n: Pointer to store the number of found indices
 *
 * Description:
 *   - Returns an allocated array of indices where valid substrings start
 *   - A valid substring is a concatenation of each word exactly once
 *   - All words in the array have the same length
 *   - Returns NULL if no valid substrings are found
 *
 * Return: Allocated array of indices, or NULL if none found
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n);

#endif /* SUBSTRING_H */
