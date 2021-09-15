/*
** EPITECH PROJECT, 2020
** assign.c
** File description:
** string assign
*/

#include "string.h"

void assign_s(string_t *this, const string_t *str)
{
    if (!this || !str)
        return;
    if (this->str)
        free(this->str);
    if (!str->str) {
        this->str = NULL;
        return;
    }
    this->str = malloc(sizeof(char) * (strlen(str->str) + 1));
    memset(this->str, 0, strlen(str->str) + 1);
    strcpy(this->str, str->str);
}

void assign_c(string_t *this, const char *s)
{
    if (!this)
        return;
    if (this->str)
        free(this->str);
    if (!s) {
        this->str = NULL;
        return;
    }
    this->str = malloc(sizeof(char) * (strlen(s) + 1));
    memset(this->str, 0, strlen(s) + 1);
    strcpy(this->str, s);
}