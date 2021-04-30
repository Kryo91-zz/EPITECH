/*
** EPITECH PROJECT, 2020
** find problem
** File description:
** all
*/

#include "../include/main.h"
#include "../include/garbage.h"

int my_isnum(char *str)
{
    int i = 0;
    while (*str)
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (0);
        i++;
    }
    return (1);
}

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
    for (int j = i; str[j] != '\0' && str[j] >= '0' && str[j] <= '9'; j++)
    {
        if (nombre > 2147483647 || nombre < -2147483648)
            return (0);
        nombre = nombre * 10 + str[j] - 48;
    }
    return (ifneg(calcul, nombre));
}

int find_start_end(char **pars)
{
    int ret = 0;

    for (int i = 0; pars[i] != NULL; i++) {
        if (my_strncmp(pars[i], "##start", 7) == 0)
            ret += 2;
        if (my_strncmp(pars[i], "##end", 5) == 0)
            ret += 3;
    }
    return (ret);
}

int error(main_t *my_struct)
{
    int bol = 0;
    ARRAY pars = my_str_to_word_array(my_struct->input, '\n');

    bol = (my_isnum(pars[0]) == 1 || my_getnbr(pars[0]) <= 0) ? 1 : 0;
    bol = (bol != 0 || find_start_end(pars) != 5) ? 1 : 0;
    return (bol);
}