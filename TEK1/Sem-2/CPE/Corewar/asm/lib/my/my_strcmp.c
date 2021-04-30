/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** compare one string's length to another
*/

int my_strcmp(char const *s1, char const *s2)
{
    int a = 0;

    if (!s1 && !s2)
        return (0);
    if (!s1 && s2)
        return (-1 * s2[0]);
    if (s1 && !s2)
        return (s1[0]);
    for (int a = 0; s1[a] || s2[a]; a += 1) {
        if (s1[a] != s2[a])
            return (s1[a] - s2[a]);
    }
    return (0);
}
