/*
** EPITECH PROJECT, 2019
** MY_STRNCPY
** File description:
** write a function that copy a strin of n character into another
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    i = 0;
    for(i = 0; i < n || i != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}
