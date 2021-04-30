/*
** EPITECH PROJECT, 2019
** BISTROMATIC
** File description:
** Fonc use
*/

char    *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char     *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int a = 0;

    while (dest[i] != '\0') {
        i++;
    }
    while (src[a] != '\0') {
        dest[i] = src[a];
        a++;
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *my_revstr(char *str)
{
    int i = 0;
    int j = 0;
    char str2;

    while (str[j] != '\0')
        j++;
    j = j - 1;
    while (i < j) {
        str2 = str[i];
        str[i] = str [j];
        str [j] = str2;
        i++;
        j--;
    }
    return (str);
}