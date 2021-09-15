/*
** EPITECH PROJECT, 2020
** append.c
** File description:
** string append
*/

#include "string.h"

void append_s(string_t *this, const string_t *ap)
{
    if (!this || !ap)
        return;
    if (!ap->str)
        return;
    if  (!this->str) {
        this->str = strdup(ap->str);
        return;
    }
    char *src = malloc(sizeof(char) * (strlen(ap->str) + \
    strlen(this->str) + 1));
    memset(src, 0, (strlen(ap->str) + strlen(this->str) + 1));
    strcpy(src, this->str);
    strcat(src, ap->str);
    free(this->str);
    this->str = malloc(sizeof(char) * (strlen(src) + 1));
    memset(this->str, 0, strlen(src) + 1);
    strcpy(this->str, src);
    free(src);
}

void append_c(string_t *this, const char *ap)
{
    if (!this)
        return;
    if (!ap)
        return;
    if  (!this->str) {
        this->str = strdup(ap);
        return;
    }
    char *src = malloc(sizeof(char) * (strlen(ap) + strlen(this->str) + 1));
    memset(src, 0, (strlen(ap) + strlen(this->str) + 1));
    strcpy(src, this->str);
    strcat(src, ap);
    free(this->str);
    this->str = malloc(sizeof(char) * (strlen(src) + 1));
    memset(this->str, 0, strlen(src) + 1);
    strcpy(this->str, src);
    free(src);
}