/*
** EPITECH PROJECT, 2020
** func_ptr
** File description:
** func_ptr.h
*/

#ifndef FUNC_PTR_H_
#define FUNC_PTR_H_
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "func_ptr_enum.h"

void print_upper(const char *str);
void print_42(const char *str);
void print_reverse(const char *str);
void print_normal(const char *str);
void do_action(action_t action, const char *str);

typedef struct func_s {

    void (*p)(const char *);
    char *str;

} func_s ;

func_s tab[] = {
    {print_42, PRINT_42},
    {print_upper, PRINT_UPPER},
    {print_reverse, PRINT_REVERSE},
    {print_normal, PRINT_NORMAL},
    {NULL}
};


#endif 