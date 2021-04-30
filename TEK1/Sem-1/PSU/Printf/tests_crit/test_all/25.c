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

Test(my_str_islower, should_return_0_full_maj)
{
    int ret = my_str_islower("AEJDDBDZOZDNZDZDP");
    cr_assert_eq(ret, 0);
}

Test(my_str_islower, should_return_0_mix)
{
    int ret = my_str_islower("efkuzefbjkpADJHDBDjrgbjzefjio");
    cr_assert_eq(ret, 0);
}

Test(my_str_islower, should_return_0_non_alpha_chars)
{
    int ret = my_str_islower("efkuzefbjk({(((%ddodozdjzd");
    cr_assert_eq(ret, 0);
}