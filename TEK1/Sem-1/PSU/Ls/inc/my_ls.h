/*
** EPITECH PROJECT, 2019
** ls
** File description:
** .h
*/

#ifndef _MYLS_H_
#define _MYLS_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <getopt.h>
#include <fcntl.h>
#include <string.h>
#include <getopt.h>

typedef struct my_ls_s
{
    char **directory;
}my_ls_t;

#endif