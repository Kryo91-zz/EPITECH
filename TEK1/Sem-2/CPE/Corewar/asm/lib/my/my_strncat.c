/*
** EPITECH PROJECT, 2019
** my_strncat.c
** File description:
** my_strncat.c
*/

char *my_strncat(char *dest, char const *src, int n)
{
    int a = 0;
    int c = 0;

    while (dest[a] != '\0')
        a++;
    for (int c = 0; c != n; c += 1) {
        dest[a] = src[c];
        a++;
    }
    return (dest);
}
