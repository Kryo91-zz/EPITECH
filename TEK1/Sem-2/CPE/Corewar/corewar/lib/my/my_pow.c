/*
** EPITECH PROJECT, 2019
** pow
** File description:
** pow
*/

int my_pow(int nb, int p)
{
    int tmp = nb;

    if (p == 0)
        return (1);
    for (int i = 0; i < p; i++)
        nb *= tmp;
    return (nb);
}
