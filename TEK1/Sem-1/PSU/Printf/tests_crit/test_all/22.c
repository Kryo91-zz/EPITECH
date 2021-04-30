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

Test(my_revstr, should_return_hello_revstr)
{
    char str[] = "Hello";
    my_revstr(str);
    cr_assert("olleH");
}

Test(my_revstr, should_return_helloworld_revstr)
{
    char str[] = "Hello World!";
    my_revstr(str);
    cr_assert("!dlroW olleH");
}

Test(my_revstr, should_return_string_HELLO)
{
    char message[] = "HELLO";
    my_revstr(message);
    cr_assert_str_eq(message, "OLLEH");
}