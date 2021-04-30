/*
** EPITECH PROJECT, 2019
** CAT
** File description:
** program of the function cat
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int fonc()
{
    int ret;
    char buffer[30000];

    while (1)
    {
        ret = read(0, buffer, 30000);
        buffer[ret] = '\0';
        if (ret == 0) 
            return (0);
        my_putstr(buffer);
    }
}

void error(char **argv, int i, int errsv)
{
    if (argv[i][0] == '-')
        fonc();
    else if (errsv == EACCES) {
        write(2, "cat: ", 5);
        write(2, argv[i], my_strlen(argv[i]));
        write( 2, ": Error\n", 8);
    }else if (errsv == ENOENT) {
        write(2, "cat: ", 5);
        write(2, argv[i], mystrlen(argv[i]));
        write(2, ": No such files or directories\n", 28);
    }else if (errsv == EISDIR) {
        write(2, "cat: ", 5);
        write(2, argv[i], my_strlen(argv[i]));
        write(2, ": Is a directory\n", 17);
    }
}
int main (int argc, char **argv)
{
    int err;
    int fd;
    int ret;
    char buffer[30000];

    if (argc == 1)
        fonc();
    for (int i = 0; i < argc; i++) {
        fd = read(fd, buffer, 30000);
        if (fd == -1) err = 1;
        ret = read(fd, buffer, 30000);
        buffer[ret] = '\0';



