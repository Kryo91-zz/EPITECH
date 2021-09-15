#include "point.h"
#include "vertex.h"
#include "new.h"
#include "int.h"
#include "float.h"
#include "char.h"
#include "object.h"
#include <stdio.h>

int main ( void )
{
    Object *i1 = new(Float, 13.0);
    Object *i2 = new(Float, 46.0);
    Object *i3 = new(Float, 0.0);

    Object *res_add = addition(i1, i2);
    Object *res_sub = subtraction(i1, i2);
    Object *res_mul = multiplication(i1, i2);
    Object *res_div = division(i1, i2);
    //Object *res_div2 = division(i3, i1);
    bool res_eq = eq(i1, i2);
    bool res_gr = gt(i1, i2);
    bool res_ls = lt(i1, i2);

    printf("addition : %s\n", str(res_add));
    printf("subtraction : %s\n", str(res_sub));
    printf("multiplication : %s\n", str(res_mul));
    printf("division : %s\n", str(res_div));
    //printf("division by zero : %s\n", str(res_div2));
    printf("Bool eq : %i\n", res_eq);
    printf("Bool gt : %i\n", res_gr);
    printf("Bool lt : %i\n", res_ls);

    Object *i4 = new(Int, 13);
    Object *i5 = new(Int, 46);
    Object *i6 = new(Int, 0);

    Object *res_add = addition(i4, i5);
    Object *res_sub = subtraction(i4, i5);
    Object *res_mul = multiplication(i4, i5);
    Object *res_div = division(i4, i5);
    //Object *res_div2 = division(i3, i4);
    bool res_eq = eq(i4, i5);
    bool res_gr = gt(i4, i5);
    bool res_ls = lt(i4, i5);

    printf("addition : %s\n", str(res_add));
    printf("subtraction : %s\n", str(res_sub));
    printf("multiplication : %s\n", str(res_mul));
    printf("division : %s\n", str(res_div));
    //printf("division by zero : %s\n", str(res_div2));
    printf("Bool eq : %i\n", res_eq);
    printf("Bool gt : %i\n", res_gr);
    printf("Bool lt : %i\n", res_ls);

    return (0) ;
}