/*
** EPITECH PROJECT, 2019
** Corewar, asm
** File description:
** main usable in unit testing
*/

#include "asm.h"

void destroy_compilation(file_data_t *data)
{
    if (data->name)
        free(data->name);
    if (data->comment)
        free(data->comment);
    if (data->inst)
        free_array(data->inst);
    if (data->file)
        free_array(data->file);
    if (data->labels)
        destroy_label_list(data->labels);
}

file_data_t get_and_check_file(char const *filepath)
{
    FILE *file_stream = fopen(filepath, "r");
    char *line = NULL;
    file_data_t data = {};

    if (!file_stream || !get_name_and_comment(&data, file_stream) || \
    my_strlen(data.name) > NAME_LEN || my_strlen(data.comment) > COMM_LEN) {
        if (!file_stream)
            write(2, "fopen: No such file\n", 20);
        return ((file_data_t){});
    }
    while (get_line_no_comment(file_stream, &line, COMMENT_CHAR) > 0) {
        if (!is_correct(line)) {
            free_array(data.file);
            ptr_message("Compilation failed\n", NULL, 2, line);
            return ((file_data_t){});
        }
        data.file = append_array(data.file, line);
    }
    fclose(file_stream);
    return (data);
}

int compile(char const *filepath)
{
    file_data_t data = get_and_check_file(filepath);
    char *new_file = get_filename(filepath);

    if (!data.name)
        return (84);
    if (!write_into_new_file(data, new_file))
        return (84);
    destroy_compilation(&data);
    return (0);
}