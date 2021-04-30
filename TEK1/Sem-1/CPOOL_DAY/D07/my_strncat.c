/*
** EPITECH PROJECT, 2019
** MY_STRNCAT
** File description:
** return another string to the n character at the following one
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int j = 0;

    while(dest[i] != '\0') {
        i++;
    }
    while(src[j] != '\0' || src[j] != nb)
    {
        dest[i] = src[j];
        j++;
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
