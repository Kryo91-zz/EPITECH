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


Test(eq, sould_return_a_bool_true_to_check_eqality_Float)
{
    Object *in1 = new(Float, 10.0);
    Object *in2 = new(Float, 10.0);

    bool res_eq = eq(in1, in2);

    cr_assert_eq(res_eq, 1);
}

Test(eq, sould_return_a_bool_false_to_check_eqality_Float)
{
    Object *in1 = new(Float, 10.0);
    Object *in2 = new(Float, 11.0);

    bool res_eq = eq(in1, in2);

    cr_assert_eq(res_eq, 0);
}

Test(eq, sould_return_a_bool_true_to_check_greater_Float)
{
    Object *in1 = new(Float, 100.0);
    Object *in2 = new(Float, 11.0);

    bool res_gt = gt(in1, in2);

    cr_assert_eq(res_gt, 1);
}

Test(eq, sould_return_a_bool_false_to_check_greater_Float)
{
    Object *in1 = new(Float, 10.0);
    Object *in2 = new(Float, 11.0);

    bool res_gt = gt(in1, in2);

    cr_assert_eq(res_gt, 0);
}

Test(eq, sould_return_a_bool_true_to_check_less_Float)
{
    Object *in1 = new(Float, 10.0);
    Object *in2 = new(Float, 11.0);

    bool res_lt = lt(in1, in2);

    cr_assert_eq(res_lt, 1);
}

Test(eq, sould_return_a_bool_false_to_check_less_Float)
{
    Object *in1 = new(Float, 10.0);
    Object *in2 = new(Float, 1.0);

    bool res_lt = lt(in1, in2);

    cr_assert_eq(res_lt, 0);
}

Test(addition, sould_add_Float)
{
    Object *in1 = new(Float, 10.0);
    Object *in2 = new(Float, 1.0);

    Object *res = addition(in1, in2);

    cr_assert_str_eq(str(res), "<Float (11.000000)>");
}

Test(subtraction, sould_sub_Float)
{
    Object *in1 = new(Float, 10.0);
    Object *in2 = new(Float, 1.0);

    Object *res = subtraction(in1, in2);

    cr_assert_str_eq(str(res), "<Float (9.000000)>");
}

Test(multiplication, sould_mul_Float)
{
    Object *in1 = new(Float, 10.0);
    Object *in2 = new(Float, 1.0);

    Object *res = multiplication(in1, in2);

    cr_assert_str_eq(str(res), "<Float (10.000000)>");
}

Test(division, sould_div_Float)
{
    Object *in1 = new(Float, 10.0);
    Object *in2 = new(Float, 1.0);

    Object *res = division(in1, in2);

    cr_assert_str_eq(str(res), "<Float (10.000000)>");
}