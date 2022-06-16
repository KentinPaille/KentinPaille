/*
** EPITECH PROJECT, 2021
** my_strdup.c
** File description:
** my_strdup.c
*/

#include "my.h"

char *my_strdup(char const *src)
{
    char *cpy_src;
    int src_len = my_strlen(src) + 1;

    cpy_src = malloc(sizeof(char) * src_len);
    return (my_strcpy(cpy_src, src));
}
