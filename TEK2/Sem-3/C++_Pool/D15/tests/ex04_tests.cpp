/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD15-corentin.petrau
** File description:
** ex04_tests.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <cassert>
#include <assert.h>
#include <iostream>
#include "../ex04/ex04.hpp"

void redir_stdout(void)
{
    cr_redirect_stdout();
}

void do_a_test1()
{
    float nb = 1, nb2 = 0, nb3 = 1;
    double nb4 = 1, nb5 = 0, nb6 = 1;
    std::cout << "1 == 0 ? " << equal(1 , 0) << std::endl;
    std::cout << "1 == 1 ? " << equal(1 , 1) << std::endl;
    std::cout << "1 == 1 ? " << equal(nb , nb3) << std::endl;
    std::cout << "1 == 0 ? " << equal(nb , nb2) << std::endl;
    std::cout << "1 == 1 ? " << equal(nb4 , nb6) << std::endl;
    std::cout << "1 == 0 ? " << equal(nb4 , nb5) << std::endl;
    std::cout << "1 == 1 ? " << equal("1" , "1") << std::endl;

    Tester <int> iT;
    Tester <float> It;
    Tester <double> IT;
    Tester <std::string> it;

    std::cout << "41 == 42 ? " << iT.equal(41 , 42) << std::endl;
    std::cout << "42 == 42 ? " << iT.equal(42 , 42) << std::endl;
    std::cout << "41 == 42 ? " << IT.equal(41 , 42) << std::endl;
    std::cout << "42 == 42 ? " << IT.equal(42 , 42) << std::endl;
    std::cout << "41 == 42 ? " << It.equal(41 , 42) << std::endl;
    std::cout << "42 == 42 ? " << It.equal(42 , 42) << std::endl;
    std::cout << "chaine1 == 42 ? " << it.equal("chaine1" , "42") << std::endl;
    std::cout << "chaine1 == 42 ? " << it.equal("42" , "42") << std::endl;
}

Test(ex04, looking_for_ex04, .init=redir_stdout)
{
    do_a_test1();
    cr_assert_stdout_eq_str("1 == 0 ? 0\n1 == 1 ? 1\n1 == 1 ? 1\n1 == 0 ? 0\n1 == 1 ? 1\n1 == 0 ? 0\n1 == 1 ? 1\n41 == 42 ? 0\n42 == 42 ? 1\n41 == 42 ? 0\n42 == 42 ? 1\n41 == 42 ? 0\n42 == 42 ? 1\nchaine1 == 42 ? 0\nchaine1 == 42 ? 1\n", "");
}