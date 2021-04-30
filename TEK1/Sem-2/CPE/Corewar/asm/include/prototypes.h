/*
** EPITECH PROJECT, 2019
** Corewar, asm
** File description:
** function prototypes
*/

#ifndef PROTOTYPES_H_
    #define PROTOTYPES_H_

    #include "op.h"

    void add_label(label_t **list, char *name, int pos);
    bool check_labels(char **instruction);
    bool check_params(char *str);
    int compile(char const *filepath);
    bool contains_spaces(char *str);
    args_type_t detect_types(char *str);
    void destroy_label_list(label_t *list);
    int direct_is_index(char *op);
    void disp_help(void);
    char *get_filename(char const *str);
    bool get_name_and_comment(file_data_t *data, FILE *filestream);
    bool is_correct(char *instruction);
    bool is_right_chars(char const *str, char const *right_chars);
    char *offset_str(const char *str, int offset);
    bool replace_labels(file_data_t *data, instruction_t *op);
    bool str_contains(char const *str, char const c);
    void write_big_endian(int fd, void *bytes, int size);
    bool write_into_new_file(file_data_t data, char const *name);
    void write_dir(int fd, char const *param, int dir_size);
    void write_header(int fd, file_data_t data);
    void write_ind(int fd, char const *param);
    void write_instruction(int fd, instruction_t *inst);
    void write_int_big_endian(int fd, int nb);
    void write_reg(int fd, char const *param);
    void write_short_big_endian(int fd, short nb);

#endif