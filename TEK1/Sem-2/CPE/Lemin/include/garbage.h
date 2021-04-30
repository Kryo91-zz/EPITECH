/*
** EPITECH PROJECT, 2020
** free
** File description:
** fonction
*/

#ifndef GARBAGE_H_
#define GARBAGE_H_

#define UNUSED __attribute__((unused))
#define CONST __attribute__((const))
#define VOID __attribute__((noreturn))
#define STR char *__attribute__((__cleanup__(destroy_str)))
#define ARRAY char **__attribute__((__cleanup__(destroy_array)))
#define INTAB int **__attribute__((__cleanup__(destroy_intab)))

void destroy_intab(int ***array);
void destroy_array(char ***array);
void destroy_str(char **str);

#endif /* !GARBAGE_H_ */
