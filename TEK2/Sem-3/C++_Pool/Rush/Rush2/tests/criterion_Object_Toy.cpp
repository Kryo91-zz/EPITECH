/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPrush2-lyvia.mallereau
** File description:
** criterion_Object_Toy.cpp
*/

#include "../object/Object.hpp"
#include "../object/toy/Teddy.hpp"
#include "../object/toy/LittlePony.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <assert.h>
#include <cassert>

void redirect_all_stdout(void)
{
        cr_redirect_stdout();
        cr_redirect_stderr();
}

void do_a_test()
{
    Object **tab = MyUnitTests();
    COUT << *tab[1];
    delete(tab[1]);
}

void do_a_test1()
{
    Object **tab = MyUnitTests();
    COUT << *tab[0];
    delete(tab[0]);
}

void do_a_test2()
{
    Teddy c("Teddy");
    c.isTaken();
}

void do_a_test3()
{
    LittlePony c("LittlePony");
    c.isTaken();
}

Test(init_object, test_the_initialization_of_the_object, .init=redirect_all_stdout)
{
    do_a_test();
    const char *str = "Object is a Teddy titled 'cuddles'\n";
    cr_assert_stdout_eq_str(str, "");
}

Test(init_object, test_the_initialization_of_the_object1, .init=redirect_all_stdout)
{
    do_a_test1();
    const char *str = "Object is a LittlePony titled 'happy pony'\n";
    cr_assert_stdout_eq_str(str, "");
}

Test(init_object, test_the_initialization_of_the_object_no_name)
{
    Object c;
    const char *str = c.getTitle().c_str();
    cr_assert_str_eq(str, "");
}

Test(init_Teddy, test_the_initialization_of_the_Teddy1, .init=redirect_all_stdout)
{
    do_a_test2();
    const char *str = "gra hu\n";
    cr_assert_stdout_eq_str(str, "");
}

Test(init_LittlePony, test_the_initialization_of_the_LittlePony1, .init=redirect_all_stdout)
{
    do_a_test3();
    const char *str = "yo man\n";
    cr_assert_stdout_eq_str(str, "");
}

Test(init_Teddy, test_the_initialization_of_the_Teddy_no_name)
{
    Teddy c("Test");
    const char *str = c.getType().c_str();
    cr_assert_str_eq(str, "Teddy");
}

Test(init_LittlePony, test_the_initialization_of_the_LittlePony_no_name)
{
    LittlePony c("test");
    const char *str = c.getType().c_str();
    cr_assert_str_eq(str, "LittlePony");
}

Test(init_toy, test_the_init_of_toy)
{
    Toy c("kiwi");
    const char *str = c.getType().c_str();

    cr_assert_str_eq(str, "Toy");
}

Test(init_toy, test_the_init_of_toy_tittle)
{
    Toy c("kiwi");
    const char *str = c.getTitle().c_str();

    cr_assert_str_eq(str, "kiwi");
}