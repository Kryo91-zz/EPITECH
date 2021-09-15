/*
** EPITECH PROJECT, 2020
** string.c
** File description:
** string init
*/

#include "string.h"

void assign(string_t *this)
{
    this->assign_c = &assign_c;
    this->assign_s = &assign_s;
    this->append_c = &append_c;
    this->append_s = &append_s;
    this->at = &at;
    this->clear = &clear;
    this->size = &size;
    this->compare_s = &compare_s;
    this->compare_c = &compare_c;
    this->copy = &copy;
    this->c_str = &c_str;
    this->empty = &empty;
}

void string_init(string_t *this , const char *s)
{
    if (this == NULL)
        return;
    if (s == NULL) {
        assign(this);
        this->str = NULL;
    } else {
        this->str = malloc(sizeof(char) * (strlen(s) + 1));
        memset(this->str, 0, strlen(s) + 1);
        strcpy(this->str, s);
        assign(this);
    }
}

void string_destroy(string_t *this)
{
    if (this)
        free(this->str);
}