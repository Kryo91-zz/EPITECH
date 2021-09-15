/*
** EPITECH PROJECT, 2020
** compare.c
** File description:
** string compare
*/

#include "string.h"

int compare_c(const string_t *this, const char *str)
{
    return (strcmp(this->str, str));
}

int compare_s(const string_t *this, const string_t *str)
{
    return (strcmp(this->str, str->str));
}