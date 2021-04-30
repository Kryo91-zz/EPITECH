/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** get_name.c
*/

#include "asm.h"

char *remove_blanks(const char *str)
{
    char *res = malloc(sizeof(char) * (my_strlen(str) + 1));
    int j = 0;
    int pair = 0;

    set_buff(res, 0, my_strlen(str) + 1);
    for (int i = 0; str && str[i]; i++ )
        if (str[i] == '"') {
            i++ ;
            pair++;
            for (; str[i] && str[i] != '"'; i++) {
                res[j] = str[i];
                j += 1;
            }
            pair++;
        } else if (str[i] == ' ' || str[i] == '\t');
        else {
            res[j] = str[i];
            j += 1;
        }
    return (pair == 2 ? res : NULL);
}

char *offset_str(const char *str, int offset)
{
    char *res = str ? malloc(sizeof(char) * (my_strlen(str) - offset + 1)) : 0;
    int j = 0;

    if (!str || !res || offset >= my_strlen(str))
        return (NULL);
    set_buff(res, 0, my_strlen(str) - offset + 1);
    for (int i = offset; str[i]; i++ ) {
        res[j] = str[i];
        j++;
    }
    return (res);
}

bool empty_comment_handling(FILE *filestream, file_data_t *data)
{
    char *temp = NULL;
    char *line = NULL;

    if (get_line_no_comment(filestream, &line, COMMENT_CHAR) == -1)
        return (bool_message("Warning: No comment found\n", true, 2, line));
    temp = remove_blanks(line);
    if (my_strncmp(".comment", temp, 8)) {
        if (!is_correct(line))
            return (bool_message("Invalid comment\n", false, 2, line));
        write(2, "Warning: No comment found\n", 26);
        data->file = append_array(data->file, line);
        return (true);
    }
    data->comment = offset_str(temp, 8);
    free(temp);
    free(line);
    return (true);
}

bool get_name_and_comment(file_data_t *data, FILE *filestream)
{
    char *line = NULL;
    char *temp = NULL;

    if (!get_line_no_comment(filestream, &line, COMMENT_CHAR))
        return (bool_message("Getline failed or empty file", false, 2, line));
    temp = remove_blanks(line);
    if (my_strncmp(".name", temp, 5) != 0)
        return (bool_message("First line isn't \".name\"\n", \
        false, 2, line));
    data->name = offset_str(temp, 5);
    free(temp);
    free(line);
    return (empty_comment_handling(filestream, data));
}