/*
** EPITECH PROJECT, 2019
** my_strncmp
** File description:
** compare one string's length to another up to n
*/

#include <stdlib.h>

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; i < n && (s1 || s2); i++) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    return (0);
}
