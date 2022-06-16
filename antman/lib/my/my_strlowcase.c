/*
** EPITECH PROJECT, 2021
** my_lowercase.c
** File description:
** my_lowercase.c
*/

#include "my.h"

char *my_strlowcase(char *str)
{
    if (str == NULL) {
        return (NULL);
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
    return (str);
}
