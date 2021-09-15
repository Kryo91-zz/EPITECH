/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD17-corentin.petrau
** File description:
** criterion_ex00.cpp
*/

#include "criterion_ex.hpp"

void redirect_all_std()
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

void do_a_test_ex00()
{
    std::vector<int> v = {1, 2, 3, 4, 5, 6};
    std::cout << *(do_find(v, 1)) << std::endl;
    std::cout << *(do_find(v, 6)) << std::endl;
    std::cout << *(do_find(v, 4)) << std::endl;
}

Test(do_find_func, check_if_find_iterator, .init=redirect_all_std)
{
    do_a_test_ex00();

    cr_assert_stdout_eq_str("1\n6\n4\n", "");
}