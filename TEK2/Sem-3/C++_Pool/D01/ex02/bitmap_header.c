/*
** EPITECH PROJECT, 2020
** Bitmap_header
** File description:
** Bitmap_header.c
*/


#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "bitmap.h"

void make_bmp_header(bmp_header_t *header , size_t size)
{
    int headersize = sizeof(bmp_header_t) + sizeof(bmp_info_header_t);

    header->magic = 0x4D42;
    header->offset = headersize;
    header->_app1 = 0;
    header->_app2 = 0;
    header->size = headersize + (size*size * 4);
}

void make_bmp_info_header(bmp_info_header_t *header , size_t size)
{
    header->size = sizeof(bmp_info_header_t);
    header->compression = 0;
    header->palette_size = 0;
    header->important_colors = 0;
    header->width = size;
    header->height = size;
    header->v_resolution = 0;
    header->h_resolution = 0;
    header->planes = 1;
    header->bpp = 32;
    header->raw_data_size = size*size*4;
}