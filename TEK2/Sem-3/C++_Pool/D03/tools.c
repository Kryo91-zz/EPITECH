/*
** EPITECH PROJECT, 2020
** tool.c
** File description:
** string tool
*/

#include "string.h"


const char *c_str(const string_t *this)
{
    if (!this)
        return (NULL);
    if (!this->str)
        return (NULL);
    return (this->str);
}

int empty(const string_t *this)
{
    if (size(this) != 0)
        return (0);
    return (1);
}