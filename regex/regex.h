#ifndef REGEX_H
#define REGEX_H

/**
 * regex_match - Checks whether a pattern matches a string
 * @str: The string to scan
 * @pattern: The regular expression pattern
 *
 * Description:
 *   - Returns 1 if pattern matches string, 0 otherwise
 *   - str can be empty and contain any ASCII character except . and *
 *   - pattern can be empty and contain any ASCII character including . and *
 *   - . matches any single character
 *   - * matches zero or more of the preceding character
 *
 * Return: 1 if pattern matches, 0 otherwise
 */
int regex_match(char const *str, char const *pattern);

#endif /* REGEX_H */
