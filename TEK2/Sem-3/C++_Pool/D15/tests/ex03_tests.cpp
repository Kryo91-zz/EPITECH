/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD15-alec.ferrari
** File description:
** ex03_tests.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <cassert>
#include <assert.h>
#include <iostream>
#include "../ex03/ex03.hpp"

void redirect_stdout(void)
{
    cr_redirect_stdout();
}

Test(print_test, should_print_ints, .init=redirect_stdout)
{
    print<int>(3);
    print<char>('c');
    print<std::string>(std::string("TEST"));
    cr_assert_stdout_eq_str("3\nc\nTEST\n", "stdout isn't correct");
}

Test(foreach_test, should_print_everything, .init=redirect_stdout)
{
    int  tab[] = { 11, 3, 89, 42 };
    foreach(tab , print <int >, 4);
    std:: string  tab2[] = { "j'", "aime", "les", "templates", "!" };
    foreach(tab2 , print , 5);
    cr_assert_stdout_eq_str("11\n3\n89\n42\nj'\naime\nles\ntemplates\n!\n", "stdout isn't correct");
}