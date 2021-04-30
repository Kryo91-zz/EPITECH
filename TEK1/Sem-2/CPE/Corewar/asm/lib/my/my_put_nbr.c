/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** print the nbr
*/

void my_putchar(char c);

int my_putstr(char const *str);

void my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        my_putstr("-2147483648");
        return;
    }
    if (nb < 0) {
        nb *= -1;
        my_putchar('-');
    }
    if (nb >= 10)
        my_put_nbr(nb / 10);
    nb = nb % 10;
    my_putchar(nb + 48);
    return;
}
