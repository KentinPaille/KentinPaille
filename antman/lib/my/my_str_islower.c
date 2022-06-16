/*
** EPITECH PROJECT, 2021
** my_str_islower.c
** File description:
** my_str_islower.c
*/

#include "my.h"

int my_str_islower(char const *str)
{
    int i = 0;

    if (str == NULL || str[0] == '\0') {
        return (0);
    }
    while (str[i] != '\0') {
        if (!(str[i] >= 'a' && str[i] <= 'z')) {
            return (0);
        }
        i++;
    }
    return (1);
}
