/*
** EPITECH PROJECT, 2019
** my_getnbr.c
** File description:
** getnbr
*/

#include <stdio.h>
#include <string.h>

int ifneg(int calcul, int nombre)
{
    if (calcul == -1)
        nombre = -nombre;
    return (nombre);
}

int my_getnbr(char const *str)
{
    int calcul = 1;
    long nombre = 0;
    int i;

    for (i = 0; str[i] == '-' || str[i] == '+'; i++)
        if (str[i] == '-')
            if (str[i + 1] >= '0' && str[i + 1] <= '9')
                calcul = -1;
    for (int j = i; str[j] != '\0' && str[j] >= '0' && str[j] <= '9'; j++) {
        if (nombre > 2147483647 || nombre < -2147483648)
            return (-1);
        nombre = nombre * 10 + str[j] - 48;
    }
    return (ifneg(calcul, nombre));
}