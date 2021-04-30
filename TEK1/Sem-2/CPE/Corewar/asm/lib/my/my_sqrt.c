/*
** EPITECH PROJECT, 2019
** square root
** File description:
** my square root
*/

int my_sqrt(int nb)
{
    int sqrt = 2;

    if (nb <= 2)
        return (-1);
    for (int sqrt = 2; sqrt * sqrt != nb && sqrt < nb; sqrt++)
        if (sqrt * sqrt == nb)
            return (sqrt);
    return (-1);
}
