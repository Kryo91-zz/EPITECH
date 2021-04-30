/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** num_test.c
*/

int num_test(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] > '9' || str[i] < '0')
            return (1);
    return (0);
}