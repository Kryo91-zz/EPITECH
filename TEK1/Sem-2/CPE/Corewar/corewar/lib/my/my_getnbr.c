/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** my getnbr
*/

int my_getnbr(char const *str)
{
    int minus_count = 0;
    int i = 0;
    int nb = 0;

    for (; str[i] == '-' || str[i] == '+'; i += 1) {
        if (str[i] == '-')
            minus_count += 1;
    }
    for (; str[i]; i += 1) {
        if (str[i] < '0' || str[i] > '9')
            break;
        nb = nb * 10 + (str[i] - 48);
    }
    if (minus_count % 2 == 1)
        nb = nb * (-1);
    return (nb);
}