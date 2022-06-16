/*
** EPITECH PROJECT, 2021
** my_strncat.c
** File description:
** my_strncat.c
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int n)
{
    int i;
    int len_dest = my_strlen(dest);

    for (i = 0; src[i] != '\0' && i < n; i++) {
        dest[len_dest + i] = src[i];
    }
    dest[len_dest + i] = '\0';
    return (dest);
}
