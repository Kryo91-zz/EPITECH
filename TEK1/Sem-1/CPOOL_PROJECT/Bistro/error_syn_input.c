/*
** EPITECH PROJECT, 2019
** error
** File description:
** errors input
*/

int    errors_syn(char const *str)
{
    int count = 0;
    int count2 = 0;
    int size = my_strlen(str);
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '(')
            ++count;
        if (str[i] == ')')
            ++count2;
        ++i;
    }
    if (count != count2 || size == 1)
        return (84);
    return (0);
}