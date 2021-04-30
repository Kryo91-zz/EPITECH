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

Test(my_strcmp, should_test4_strings) {

    char message[] = "";
    char message2[] = "";
}

Test(my_strncmp, should_return_0_strings) {

    char message[] = "h";
    char message2[] = "h";
    int n = 2;
    cr_assert_eq(my_strncmp(message, message2, n), 0);
}

Test(my_strncmp, should_return_1) {

    char message[] = "hel";
    char message2[] = "h";
    int n = 4;
    cr_assert_eq(my_strncmp(message, message2, n), 1);
}