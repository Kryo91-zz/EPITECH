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

Test(my_strncat_, should_concats_2_strings) {

    char message[] = "bonjour";
    char message2[] = "oui";
    int nb = 2;
}

Test(my_strncat_, should_concats_1_strings) {

    char message[] = "bonjour";
    char message2[] = "";
    int nb = 2;

    cr_assert_str_eq(my_strncat(message, message2, nb), "bonjour");
}

Test(my_strncat_, should_concats_0_strings) {

    char message[] = "";
    char message2[] = "";
    int nb = 1;

    cr_assert_str_eq(my_strncat(message, message2, nb), "");
}