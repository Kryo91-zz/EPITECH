/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPrush2-lyvia.mallereau
** File description:
** criterion_Object_Toy.cpp
*/

#include "../object/Object.hpp"
#include "../object/wrap/Box.hpp"
#include "../object/toy/Teddy.hpp"
#include "../object/wrap/GiftPaper.hpp"
#include "../object/wrap/Wrap.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <assert.h>
#include <cassert>

void redirect_all_stdout1(void)
{
        cr_redirect_stdout();
        cr_redirect_stderr();
}

void do_a_tes()
{
    Object **tab = new Object*[4];
    Teddy *roosevelt = new Teddy("roosevelt");
    Box *box = new Box("box");
    GiftPaper *paper = new GiftPaper("paper");

    tab[0] = roosevelt;
    tab[1] = box;
    tab[2] = paper;
    tab[3] = nullptr;

    GiftPaper *res = dynamic_cast<GiftPaper *>(MyUnitTests(tab));

    Box *res_box = dynamic_cast<Box *>(res->getContent());
    res_box->openMe();
    Teddy *res_teddy = dynamic_cast<Teddy *>(res_box->getContent());
    COUT << res_teddy;
    delete[] tab;
    delete(res);
}

void do_a_tes1()
{
    Object **tab = new Object*[4];
    Teddy *roosevelt = new Teddy("roosevelt");
    Box *box = new Box("box");
    GiftPaper *paper = new GiftPaper("paper");

    tab[0] = roosevelt;
    tab[1] = box;
    tab[2] = paper;
    tab[3] = nullptr;

    GiftPaper *res = dynamic_cast<GiftPaper *>(MyUnitTests(tab));

    Box *res_box = dynamic_cast<Box *>(res->getContent());
    res_box->closeMe();
    Teddy *res_teddy = dynamic_cast<Teddy *>(res_box->getContent());
    COUT << res_teddy;
    delete[] tab;
    delete(res);
}

Test(init_box, test_the_initialization_of_the_box, .init=redirect_all_stdout1)
{
    do_a_tes();
    const char *str = "gra hu\n";
    cr_assert_stdout_eq_str(str, "");
}

Test(init_box, test_the_initialization_of_the_box1, .init=redirect_all_stdout1)
{
    do_a_tes1();
    const char *str = "Box is closed.\n";
    cr_assert_stderr_eq_str(str, "");
}

Test(init_box, test_the_initialization_of_the_box2)
{
    Box c("kiwi");
    cr_assert_str_eq(c.getTitle().c_str(), "kiwi");
}

Test(init_box, test_the_initialization_of_the_box3)
{
    Box c("kiwi");
    cr_assert_str_eq(c.getType().c_str(), "Box");
}

Test(init_box, test_the_initialization_of_the_box4)
{
    GiftPaper c("kiwi");
    cr_assert_str_eq(c.getTitle().c_str(), "kiwi");
}

Test(init_box, test_the_initialization_of_the_box5)
{
    Wrap c("kiwi");
    cr_assert_str_eq(c.getTitle().c_str(), "kiwi");
}
