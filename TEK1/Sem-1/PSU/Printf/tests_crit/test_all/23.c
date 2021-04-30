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

Test(my_revstr, should_return_string_Z)
{
    char message[] = "Z";
    my_revstr(message);
    cr_assert_str_eq(message, "Z");
}

Test(my_revstr, should_return_string_TOTO)
{
    char message[] = "TOTO";
    my_revstr(message);
    cr_assert_str_eq(message, "OTOT");
}

Test (my_str_isalpha, should_print_empty_string)
{
    int result = my_str_isalpha ("");
    cr_assert_eq (result, 1);
}