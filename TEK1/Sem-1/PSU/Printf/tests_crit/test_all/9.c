/*
** EPITECH PROJECT, 2019
**  criterion_test
** File description:
** yo
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdarg.h>
#include "../../inc/my.h"

Test(my_strlen, test_on_potentially_broken_strings)
{
    int result = my_strlen("Hello+-*/\nworld");
    cr_assert_eq(result, 15);
}

Test(my_strcpy, should_return_string_Oui_from_src_string)
{
    char src[] = " Oui ";
    char dest[] = "";
    char *result = my_strcpy(dest, src);
    cr_assert_eq(result, dest);
}

Test(my_strcpy, should_find_empty_string_in_src)
{
    char src[] = "";
    char dest[] = "";
    char *result = my_strcpy (dest, src);
    cr_assert_eq (result, dest);
}