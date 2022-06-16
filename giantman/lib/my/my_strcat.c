/*
** EPITECH PROJECT, 2021
** my_strcat.c
** File description:
** my_strcat.c
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i;
    int len_dest = my_strlen(dest);

    for (i = 0; src[i] != '\0'; i++) {
        dest[len_dest + i] = src[i];
    }
    dest[len_dest + i] = '\0';
    return (dest);
}
