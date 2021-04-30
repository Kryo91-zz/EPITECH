/*
** EPITECH PROJECT, 2019
** EvalExpr
** File description:
** Basic Function
*/

#include <stdlib.h>
#include <unistd.h>

int    eval_expr(char const *str);

void    my_putchar(char c)
{
    write(1, &c, 1);
}

void    my_put_nbr(int nb)
{
    if (nb < 0)
    {
        my_putchar('-');
        my_put_nbr(-nb);
        return;
    }
    if (nb >= 10)
    {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    else
        my_putchar(nb + '0');
}

int    my_convert_chars_to_nb(char **c)
{
    int num = 0;

    while (**c >= '0' && **c <= '9') {
        num = num * 10 + (**c - 48);
        (*c)++;
    }
    return (num);
}
int        main(int ac, char **av)
{
    if (ac == 2)
    {
        my_put_nbr(eval_expr(av[1]));
        my_putchar('\n');
        return (0);
    }
    return (84);
}
