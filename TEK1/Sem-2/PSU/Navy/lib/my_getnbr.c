/*
** EPITECH PROJECT, 2019
** getnbr
** File description:
** getnbr
*/

#include "../inc/my.h"

int    my_sign(char const *str)
{
    int i = 0;
    int y = 0;

    while ((str[i] == 43 || str[i] == 45) && str[i] != '\0') {
        if (str[i] == 45) {
            y++;
        }
        i++;
    }
    if (y % 2 == 0) {
        return (i);
    }
    return (-i);
}

int    my_long_number(char const *str, int letter, int size, int sign)
{
    long number = 0;
    int a = 0;

    size = size - 1;
    while (size >= 0) {
        number = number + ((str[letter] - 48) * my_compute_power_rec(10, size));
        if (number < 0)
            return (0);
        size = size - 1;
        letter = letter + 1;
    }
    a = number;
    return (a);
}

int    my_getnbr(char const *str)
{
    int  number = 0;
    int letter = my_sign(str);
    int sign = letter;
    int size = 0;

    if (letter < 0) {
        letter = - letter;
    }
    while ((str[letter] >= 48 && str[letter] <= 57) && str[letter] != '\0') {
        letter = letter + 1;
        size = size + 1;
    }
    letter = letter - size;
    number = my_long_number(str, letter, size, sign);
    if (number < 0)
        return (number);
    if (sign < 0) {
        number = (number * (-1));
    }
    return (number);
}