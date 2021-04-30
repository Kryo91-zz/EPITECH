/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** copy n characters from a string to another
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int idx = 0;

    for (int i = 0; src[i]; i++) {
        if (i >= n) {
            dest[idx] = src[i];
            idx++;
        }
    }
}
