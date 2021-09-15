/*
** EPITECH PROJECT, 2020
** B-ASM-400-MPL-4-1-asmminilibc-corentin.petrau
** File description:
** include_criterion.h
*/

#include <assert.h>
#include <criterion/criterion.h>
#include <dlfcn.h>

void    *handle;
size_t  (*my_strlen)(char*);
char  *(*my_strchr)(char*, int);
void *(*my_memset)(char*, char, int);
int (*my_strcmp)(char*, char*);
void *(*my_memcpy)(void*, const void *, size_t);
int (*my_strncmp)(char*, char*, int);
void *(*my_memmove)(void*, void*, size_t);
int (*my_strcasecmp)(char*, char*);
char *(*my_rindex)(char*, char);
char *(*my_strstr)(char*, char*);
char *(*my_strpbrk)(char*, char*);
int (*my_strcspn)(char*, char*);
char    *str;


static void init(void)
{
    handle = dlopen("./libasm.so", RTLD_LAZY);
    assert(handle);
    my_strlen = dlsym(handle, "strlen");
    my_strchr = dlsym(handle, "strchr");
    my_memset = dlsym(handle, "memset");
    my_strcmp = dlsym(handle, "strcmp");
    my_memcpy = dlsym(handle, "memcpy");
    my_strncmp = dlsym(handle, "strncmp");
    my_memmove = dlsym(handle, "memmove");
    my_strcasecmp = dlsym(handle, "strcasecmp");
    my_rindex = dlsym(handle, "rindex");
    my_strstr = dlsym(handle, "strstr");
    my_strpbrk = dlsym(handle, "strpbrk");
    my_strcspn = dlsym(handle, "strcspn");
    assert(!dlerror());
}

static void fini(void)
{
    dlclose(handle);
    free(str);
}
