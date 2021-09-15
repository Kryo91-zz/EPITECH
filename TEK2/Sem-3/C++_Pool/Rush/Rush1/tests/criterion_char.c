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


Test(eq, sould_return_a_bool_true_to_check_eqality_Char)
{
    Object *in1 = new(Char, 10);
    Object *in2 = new(Char, 10);

    bool res_eq = eq(in1, in2);

    cr_assert_eq(res_eq, 1);
}

Test(eq, sould_return_a_bool_false_to_check_eqality_Char)
{
    Object *in1 = new(Char, 10);
    Object *in2 = new(Char, 11);

    bool res_eq = eq(in1, in2);

    cr_assert_eq(res_eq, 0);
}

Test(gt, sould_return_a_bool_true_to_check_greater_Char)
{
    Object *in1 = new(Char, 100);
    Object *in2 = new(Char, 11);

    bool res_gt = gt(in1, in2);

    cr_assert_eq(res_gt, 1);
}

Test(gt, sould_return_a_bool_false_to_check_greater_Char)
{
    Object *in1 = new(Char, 10);
    Object *in2 = new(Char, 11);

    bool res_gt = gt(in1, in2);

    cr_assert_eq(res_gt, 0);
}

Test(lt, sould_return_a_bool_true_to_check_less_Char)
{
    Object *in1 = new(Char, 10);
    Object *in2 = new(Char, 11);

    bool res_lt = lt(in1, in2);

    cr_assert_eq(res_lt, 1);
}

Test(lt, sould_return_a_bool_false_to_check_less_Char)
{
    Object *in1 = new(Char, 10);
    Object *in2 = new(Char, 1);

    bool res_lt = lt(in1, in2);

    cr_assert_eq(res_lt, 0);
}

Test(addition, sould_add_Char)
{
    Object *in1 = new(Char, 64);
    Object *in2 = new(Char, 1);

    Object *res = addition(in1, in2);

    cr_assert_str_eq(str(res), "<Char (A)>");
}

Test(subtraction, sould_sub_Char)
{
    Object *in1 = new(Char, 69);
    Object *in2 = new(Char, 1);

    Object *res = subtraction(in1, in2);

    cr_assert_str_eq(str(res), "<Char (D)>");
}

Test(multiplication, sould_mul_Char)
{
    Object *in1 = new(Char, 72);
    Object *in2 = new(Char, 1);

    Object *res = multiplication(in1, in2);

    cr_assert_str_eq(str(res), "<Char (H)>");
}

Test(division, sould_div_Char)
{
    Object *in1 = new(Char, 90);
    Object *in2 = new(Char, 1);

    Object *res = division(in1, in2);

    cr_assert_str_eq(str(res), "<Char (Z)>");
}