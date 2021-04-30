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

Test(my_strcat, should_concats_2_strings) {

    char message[] = "bonjour";
    char message2[] = "oui";
}

Test(my_str_to_word_array, should_return_nothing) {
    char **result = my_str_to_word_array("", "");
    cr_assert_not_null(result);
    cr_assert_null(result[0]);
}

Test(my_compute_power_rec, should_return_0_power_1)
{
    cr_redirect_stdout();
    int number = 0;
    int power = 1;
    int result = my_compute_power_rec(number, power);
    cr_assert_eq(0, result);
}