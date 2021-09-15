/*
** EPITECH PROJECT, 2020
** at.c
** File description:
** string at
*/

#include "string.h"

char at(const string_t *this, size_t pos)
{
    if (this == NULL)
        return (-1);
    if (pos >= strlen(this->str))
        return (-1);
    return (this->str[pos]);
}

void clear(string_t *this)
{
    if (!this)
        return;
    if (this->str)
        free(this->str);
    this->str = malloc(sizeof(char));
    this->str[0] = 0;
}

int size(const string_t *this)
{
    int len = -1;

    if (!this)
        return (len);
    if (!this->str)
        return (len);
    for (len = 0; this->str[len]; ++len);
    return (len);
}

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    int len = 0;
    size_t count = 0;

    if (!this || n == 0 || pos >= strlen(this->str))
        return (len);
    for (int i = 0; count < n && this->str[pos]; ++i, ++pos, ++count)
        s[i] = this->str[pos];
    return (count);
}