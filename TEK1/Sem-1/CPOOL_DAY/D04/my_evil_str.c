/*
** EPITECH PROJECT, 2019
** MY_EVIL_STR
** File description:
** swap each of the string's characters, two by two
*/
    
char    *my_evil_str(char *str)
{
    int j = my_strlen(str) - 1;
    int i = 0;
    char m;

    while (j < i) {
        m = str[i];
        str[i] = str[j];
        str[j] = m;
        i = i + 1;
        j = j - 1;
    }
     return(str);
}
    
    
