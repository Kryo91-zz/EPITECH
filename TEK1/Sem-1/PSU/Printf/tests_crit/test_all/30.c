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

Test(my_strcmp, should_test_strings) {

    char message[] = "hello";
    char message2[] = "hello";
}

Test(my_strcmp, should_test2_strings) {

    char message[] = "hello";
    char message2[] = "";
    cr_assert_eq(my_strcmp(message, message2), 104);
}

Test(my_strcmp, should_test3_strings) {

    char message[] = "hello";
    char message2[] = "hel";
    cr_assert_eq(my_strcmp(message, message2), 108);
}