/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD15-alec.ferrari
** File description:
** ex01_tests.cpp
*/

#include "criterion/criterion.h"
#include "criterion/redirect.h"
#include <cassert>
#include <assert.h>
#include <iostream>
#include "../ex01/ex01.hpp"

class  toto
{
    public:
        toto() = default;
        toto &operator=(const toto&) = delete;
        toto(const toto &) = delete;
        bool operator==(const toto&) const { return true; }
        bool operator>( const toto&) const { return false; }
        bool operator<( const toto&) const { return false; }
};


Test(comparison, should_compare_class_eq)
{
    toto a, b;
    cr_assert(compare(a, b) == 0, "compare(a, b) isn't 0");
}

Test(comparison, should_return_negative_one)
{
    int a = 2, b = 3;
    cr_assert(compare(a, b) == -1, "compare(a, b) isn't -1");
}

Test(comparison, should_return_one)
{
    int a = 2, b = 3;
    cr_assert(compare(b, a) == 1, "compare(b, a) isn't 1");
}

Test(comparison, should_return_zero)
{
    int a = 2, b = 2;
    cr_assert(compare(a, b) == 0, "compare(a, b) isn't 0");
}

Test(comparison, should_return_one1)
{
    int a = 5, b = 2;
    cr_assert(compare(a, b) == 1, "compare(a, b) isn't 1");
}

Test(comparison, should_equal)
{
    const char *str = "pomme";
    const char *src = "pomme";

    int res = compare(str, src);
    cr_assert_eq(res, 0);
}

Test(comparison, should_eq_1)
{
    const char *str = "Tototo";
    const char *src = "Toto";

    int res = compare(str, src);
    cr_assert_eq(res, 1);
}

Test(comparison, should_eq_m1)
{
    const char *str = "Toto";
    const char *src = "Tototo";

    int res = compare(str, src);
    cr_assert_eq(res, -1);
}