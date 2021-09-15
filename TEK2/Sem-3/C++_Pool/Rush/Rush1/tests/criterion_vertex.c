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

Test(addition, sould_add_Vertex)
{
    Object *in1 = new(Vertex, 12, -24, 42);
    Object *in2 = new(Vertex, 3, -6, 64);

    Object *res = addition(in1, in2);

    cr_assert_str_eq(str(res), "<Vertex (15, -30, 106)>");
}

Test(subtraction, sould_sub_Vertex)
{
    Object *in1 = new(Vertex, 27, 9, 74);
    Object *in2 = new(Vertex, -3, -1, 88);

    Object *res = subtraction(in1, in2);

    cr_assert_str_eq(str(res), "<Vertex (30, 10, -14)>");
}