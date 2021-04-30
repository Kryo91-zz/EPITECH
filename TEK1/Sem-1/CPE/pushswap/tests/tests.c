/*
** EPITECH PROJECT, 2019
** my_PUSH_SWAP_test
** File description:
** unit_test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void sort(char *str, char *dest, char *src, char **av);

void redirect(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(sort, error, .init = redirect)
{
    cr_redirect_stdout();
    char *str = "12";
    char *dest = "12";
    char *src = "13";
    char **av;
    sort(str, dest, src, av);
    cr_assert_stdout_eq_str("\n");
}
