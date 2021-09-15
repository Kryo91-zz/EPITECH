/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD15-corentin.petrau
** File description:
** ex02_test.cpp
*/

#include "../ex02/ex02.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_stdout(void)
{
        cr_redirect_stdout();
        cr_redirect_stderr();
}

void do_a_test()
{
    int tab[2] = {3, 0};
    int minimum = templateMin(tab, 2);
    std::cout << "templateMin(tab, 2) = " << minimum << std::endl;
    minimum = nonTemplateMin(tab, 2);
    std::cout << "nonTemplateMin(tab, 2) = " << minimum << std::endl;
    minimum = templateMin(tab, 2);
    std::cout << "templateMin(tab, 2) = " << minimum << std::endl;
    minimum = nonTemplateMin(tab, 2);
    std::cout << "nonTemplateMin(tab, 2) = " << minimum << std::endl;
    minimum = templateMin(tab, 2);
    std::cout << "templateMin(tab, 2) = " << minimum << std::endl;
    minimum = nonTemplateMin(tab, 2);
    std::cout << "nonTemplateMin(tab, 2) = " << minimum << std::endl;
    minimum = templateMin(tab, 2);
    std::cout << "templateMin(tab, 2) = " << minimum << std::endl;
    minimum = nonTemplateMin(tab, 2);
    std::cout << "nonTemplateMin(tab, 2) = " << minimum << std::endl;
}

Test(try_template_min, try_to_do_a_template_min, .init=redirect_all_stdout)
{
    do_a_test();
    cr_assert_stdout_eq_str("template min\ntemplateMin(tab, 2) = 0\nnon-template min\nnonTemplateMin(tab, 2) = 0\ntemplate min\ntemplateMin(tab, 2) = 0\nnon-template min\nnonTemplateMin(tab, 2) = 0\ntemplate min\ntemplateMin(tab, 2) = 0\nnon-template min\nnonTemplateMin(tab, 2) = 0\ntemplate min\ntemplateMin(tab, 2) = 0\nnon-template min\nnonTemplateMin(tab, 2) = 0\n", "");
}
