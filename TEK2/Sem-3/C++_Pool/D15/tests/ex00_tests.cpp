/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD15-alec.ferrari
** File description:
** ex00_tests.cpp
*/

#include "criterion/criterion.h"
#include "criterion/redirect.h"
#include <cassert>
#include <assert.h>
#include <iostream>
#include "../ex00/ex00.hpp"

Test(operations, should_swap)
{
    int a = 3, b = 2;

    swap(a, b);
    cr_assert((a == 2 && b == 3) == true, "(a == 2 && b == 3) isn't true");
}

Test(operations, should_return_min)
{
    int a = 3, b = 2;

    cr_assert(min(a, b) == 2, "min(a, b) isn't 2");
}

Test(operations, should_return_max)
{
    int a = 3, b = 2;

    cr_assert(max(a, b) == 3, "max(a, b) isn't 3");
}

Test(operations, should_return_sum)
{
    int a = 3, b = 2;

    cr_assert(add(a, b) == 5, "add(a, b) isn't 5");
}

Test(operations, should_return_min1)
{
    int a = 1, b = 2;

    cr_assert(min(a, b) == 1, "min(a, b) isn't 1");
}

Test(operations, should_return_max1)
{
    int a = 1, b = 2;

    cr_assert(max(a, b) == 2, "min(a, b) isn't 2");
}