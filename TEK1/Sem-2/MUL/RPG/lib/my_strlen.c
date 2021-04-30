/*
** EPITECH PROJECT, 2019
** my_strlen.c
** File description:
** bistro
*/

int my_strlen(char const *str)
{
    int result;

    result = 0;
    while (str[result] != '\0') {
        result++;
    }
    return (result);
}