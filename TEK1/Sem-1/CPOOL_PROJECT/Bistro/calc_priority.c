/*
** EPITECH PROJECT, 2019
** EvalExpr
** File description:
** Priority parantheses
*/

#include <stdio.h>

int    my_strlen(char const *str);

int    my_putstr(char const *str);

void my_putchar(char c);

void my_putnbr(int nbr);

int my_convert_chars_to_nb(char **c);

int    infin_add_sub(char **str);

int    infin_add_sub_neg(char **str);

int    priority_absolute(char **str)
{
    int nb = 0;

    while (**str == ' ')
        (*str)++;

    if (**str == '(')
    {
        (*str)++;
        nb = infin_add_sub(str);
        if (**str == ')')
            (*str)++;
        return (nb);
    }
    return (my_convert_chars_to_nb(str));
}