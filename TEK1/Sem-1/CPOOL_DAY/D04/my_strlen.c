/*
** EPITECH PROJECT, 2019
** MY_STRLEN
** File description:
** counts and returns the number of characters in the string
*/

int my_strlen(char const *str)
{
    int i = 0;
    for (;str[i];i++);
    return (i);
}