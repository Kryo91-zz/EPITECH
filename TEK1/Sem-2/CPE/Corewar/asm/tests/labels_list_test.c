/*
** EPITECH PROJECT, 2019
** asm
** File description:
** labels_list.c
*/

#include "asm.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(add_label, should_add_label_to_list)
{
    label_t *list = NULL;
    char *name = my_strdup("live:");

    add_label(&list, name, 4);
    cr_assert_not_null(list);
    add_label(&list, name, 5);
    cr_assert_not_null(list->next);
}