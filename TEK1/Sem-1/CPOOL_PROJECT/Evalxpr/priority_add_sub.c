/*
** EPITECH PROJECT, 2019
** EvalExpr
** File description:
** priority order
*/

#include <stdio.h>

int    priority_absolute(char **str);

void my_putchar(char c);

void my_putnbr(int nbr);

int my_convert_chars_to_nb(char **c);

int    infin_by_divide_mod_neg(char **str)
{
    int    by_div_mod_neg_1 = priority_absolute(str);
    int    by_div_mod_neg_2;
    char calc;

    while (**str)
    {
        calc = **str;
        if (calc != '/' && calc != '-' && calc != '*-' && calc != '%-')
            return (by_div_mod_neg_1);
        (*str)++;
        by_div_mod_neg_2 = priority_absolute(str);
        if (calc == '*' && calc == '-')
            by_div_mod_neg_1 = by_div_mod_neg_1 * (by_div_mod_neg_2 * -1);
        if (calc == '/' && calc == '-')
            by_div_mod_neg_1 = by_div_mod_neg_1 / (by_div_mod_neg_2 * -1);
        if (calc == '%' && calc == '-')
            by_div_mod_neg_1 = by_div_mod_neg_1 % (by_div_mod_neg_2 * -1);
    }
    return (by_div_mod_neg_1);
}


int    infin_by_divide_mod(char **str)
{
    int    by_div_mod_1 = priority_absolute(str);
    int    by_div_mod_2;
    char calc;

    while (**str)
    {
        calc = **str;
        if (calc != '/' && calc != '*' && calc != '%' && calc != '*-')
            return (by_div_mod_1);
        (*str)++;
        by_div_mod_2 = priority_absolute(str);
        if (calc == '*')
            by_div_mod_1 = by_div_mod_1 * by_div_mod_2;
        if (calc == '/')
            by_div_mod_1 = by_div_mod_1 / by_div_mod_2;
        if (calc == '%')
            by_div_mod_1 = by_div_mod_1 % by_div_mod_2;
    }
    return (by_div_mod_1);
}


int    infin_add_sub_neg(char **str)
{
    int    add_sub_neg_1 = infin_by_divide_mod_neg(str);
    int    add_sub_neg_2;
    char calc;

    while (**str)
    {
        calc = **str;
        if (calc != '+' && calc != '-' && calc != '-' && calc != '-')
            return (add_sub_neg_1);
        (*str)++;
        add_sub_neg_2 = infin_by_divide_mod_neg(str);
        if (calc == '+' && calc == '-')
            add_sub_neg_1 = add_sub_neg_1 - add_sub_neg_2;
        else if (calc == '-' && calc == '-')
            add_sub_neg_1 = add_sub_neg_1 + add_sub_neg_2;
    }
    return (add_sub_neg_1);
}

int    infin_add_sub(char **str)
{
    int    add_sub_1 = infin_by_divide_mod(str);
    int    add_sub_2;
    char calc;

    while (**str)
    {
        calc = **str;
        if (calc != '+' && calc != '-')
            return (add_sub_1);
        (*str)++;
        add_sub_2 = infin_by_divide_mod(str);
        if (calc == '+')
            add_sub_1 = add_sub_1 + add_sub_2;
        else
            add_sub_1 = add_sub_1 - add_sub_2;
    }
    return (add_sub_1);
}

int    eval_expr(char const *str)
{
    return (infin_add_sub(&str));
    return (infin_add_sub_neg(&str));
}