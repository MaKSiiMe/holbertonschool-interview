#include "holberton.h"

char *skip_stars(char *s2)
{
    if (*s2 == '*' && *(s2 + 1) == '*')
        return (skip_stars(s2 + 1));
    return (s2);
}

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
