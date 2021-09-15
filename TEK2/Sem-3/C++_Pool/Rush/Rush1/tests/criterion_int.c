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
#include "../raise.h"
#include <stdarg.h>


Test(eq, sould_return_a_bool_true_to_check_eqality_int)
{
    Object *in1 = new(Int, 10);
    Object *in2 = new(Int, 10);

    bool res_eq = eq(in1, in2);

    cr_assert_eq(res_eq, 1);
}

Test(eq, sould_return_a_bool_false_to_check_eqality_int)
{
    Object *in1 = new(Int, 10);
    Object *in2 = new(Int, 11);

    bool res_eq = eq(in1, in2);

    cr_assert_eq(res_eq, 0);
}

Test(eq, sould_return_a_bool_true_to_check_greater_int)
{
    Object *in1 = new(Int, 100);
    Object *in2 = new(Int, 11);

    bool res_gt = gt(in1, in2);

    cr_assert_eq(res_gt, 1);
}

Test(eq, sould_return_a_bool_false_to_check_greater_int)
{
    Object *in1 = new(Int, 10);
    Object *in2 = new(Int, 11);

    bool res_gt = gt(in1, in2);

    cr_assert_eq(res_gt, 0);
}

Test(eq, sould_return_a_bool_true_to_check_less_int)
{
    Object *in1 = new(Int, 10);
    Object *in2 = new(Int, 11);

    bool res_lt = lt(in1, in2);

    cr_assert_eq(res_lt, 1);
}

Test(eq, sould_return_a_bool_false_to_check_less_int)
{
    Object *in1 = new(Int, 10);
    Object *in2 = new(Int, 1);

    bool res_lt = lt(in1, in2);

    cr_assert_eq(res_lt, 0);
}

Test(addition, sould_add_int)
{
    Object *in1 = new(Int, 10);
    Object *in2 = new(Int, 1);

    Object *res = addition(in1, in2);

    cr_assert_str_eq(str(res), "<Int (11)>");
}

Test(subtraction, sould_sub_int)
{
    Object *in1 = new(Int, 10);
    Object *in2 = new(Int, 1);

    Object *res = subtraction(in1, in2);

    cr_assert_str_eq(str(res), "<Int (9)>");
}

Test(multiplication, sould_mul_int)
{
    Object *in1 = new(Int, 10);
    Object *in2 = new(Int, 1);

    Object *res = multiplication(in1, in2);

    cr_assert_str_eq(str(res), "<Int (10)>");
}

Test(division, sould_div_int)
{
    Object *in1 = new(Int, 10);
    Object *in2 = new(Int, 1);

    Object *res = division(in1, in2);

    cr_assert_str_eq(str(res), "<Int (10)>");
}