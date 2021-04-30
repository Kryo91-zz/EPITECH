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

Test (my_str_isalpha, should_print_alpha_string)
{
    int result = my_str_isalpha ("hello");
    cr_assert_eq (result, 1);
}

Test (my_str_isalpha, should_print_no_alpha_string)
{
    int result = my_str_isalpha ("hello/");
    cr_assert_eq (result, 0);
}

Test(my_str_islower, should_return_1_full_low)
{
    int ret = my_str_islower("efkuzefbjkpjrgbjzefjio");
    cr_assert_eq(ret, 1);
}