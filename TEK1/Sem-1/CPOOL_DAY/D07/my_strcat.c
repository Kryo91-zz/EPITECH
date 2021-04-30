/*
** EPITECH PROJECT, 2019
** MY_STRCAT
** File description:
** add another string to the following one
*/


char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0') {
        i++;
    }

    while(src[j] != '\0')
    {
        dest[i] = src[j];
        j++;
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
