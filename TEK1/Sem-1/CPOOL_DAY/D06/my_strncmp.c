/*
** EPITECH PROJECT, 2019
** MY_STRNCMP
** File description:
** compare two string to the n bytes characters
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int result = 0;
    int result2 = 0;
    char *str;
    char *str2;
    int i = 0;
    int j = 0;
    int res;

    while(s1[i] <= n || s1[i] != '\0')
    {
        result = result + s1[i];
        i++;
    }
    while(s2[j] <= n || s2[j] != '\0')
    {
        result2 = result2 + s2[j];
        j++;
    }
    res = result - result2;

    if(res > 0) {
        return(1);
    }
    if(res == 0) {
        return(0);
    }
    if(res < 0) {
        return(-1);
    }
}
