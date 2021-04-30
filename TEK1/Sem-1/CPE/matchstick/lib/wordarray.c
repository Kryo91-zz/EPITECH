/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** wordarray.c
*/

#include <stdlib.h>
#include <stdio.h>

int countslines(char const *str)
{
    int count = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n') {
            count += 1;
        }
        i += 1;
    }
    return (count);
}

int countwords(char const *str)
{
    int count = 0;
    int nbr = 0;
    int i = 0;

    while (str[i] != '\0') {
        while (str[i] == '\n') {
            count += 1;
            i += 1;
        }
        if (count > nbr) {
            nbr = count;
        }
        i += 1;
    }
    return (nbr);
}

char **wordarray(char *str)
{
    int count = countslines(str);
    int length = countwords(str);
    char **array = malloc(sizeof(char *) * count + 1);
    int index = 0;
    int indexx = 0;
    int indexy = 0;

    while (indexy <= count) {
        indexx = 0;
        array[indexy] = malloc(sizeof(char) * length);
        while (str[index] != '\0' && str[index] != '\n') {
            array[indexy][indexx] = str[index];
            indexx += 1;
            index += 1;
        }
        array[indexy][indexx] = '\0';
        index += 1;
        indexy += 1;
    }
    return (array);
}
