/*
** EPITECH PROJECT, 2019
** Corewar, asm
** File description:
** defines and typedefs
*/

#ifndef DEFINES_H_
    #define DEFINES_H_

    typedef unsigned char byte_t;
    typedef struct label_s label_t;
    typedef struct instruction_s instruction_t;
    typedef struct file_data_s file_data_t;

    struct label_s {
        char *name;
        int pos;
        label_t *next;
    };

    struct instruction_s {
        char **to_free;
        char *op;
        byte_t opcode;
        char **args;
        byte_t coding_byte;
        int size;
        int pos;
    };

    struct file_data_s {
        char *name;
        char *comment;
        char **file;
        instruction_t **inst;
        long int size;
        label_t *labels;
    };

#endif