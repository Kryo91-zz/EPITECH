/*
** EPITECH PROJECT, 2020
** criterion_test
** File description:
** test criterion
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../object.h"
#include "../char.h"
#include "../float.h"
#include "../int.h"
#include "../vertex.h"
#include "../point.h"
#include "../new.h"
#include <stdarg.h>

Test(addition, sould_add_Point)
{
    Object *in1 = new(Point, 12, -24);
    Object *in2 = new(Point, 3, -6);

    Object *res = addition(in1, in2);

    cr_assert_str_eq(str(res), "<Point (15, -30)>");
}

Test(subtraction, sould_sub_Point)
{
    Object *in1 = new(Point, 27, 9);
    Object *in2 = new(Point, -3, -1);

    Object *res = subtraction(in1, in2);

    cr_assert_str_eq(str(res), "<Point (30, 10)>");
}

Test(eq, sould_eq_false_Point)
{
    Object *in1 = new(Point, 27, 9);
    Object *in2 = new(Point, -3, -1);

    bool res = eq(in1, in2);

    cr_assert_eq(res, 0);
}

Test(eq, sould_eq_true_Point)
{
    Object *in1 = new(Point, 15, 15);
    Object *in2 = new(Point, 15, 15);

    bool res = eq(in1, in2);

    cr_assert_eq(res, 1);
}