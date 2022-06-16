/*
** EPITECH PROJECT, 2021
** my_revstr
** File description:
** my_revstr
*/

#include "my.h"

char *my_revstr(char *str)
{
    int str_len1 = my_strlen(str);
    int str_len2 = str_len1;
    int counter = 0;
    char evil_str[str_len1];

    str_len1 -= 1;
    while (str_len1 != -1) {
        evil_str[counter] = str[str_len1];
        str_len1 -= 1;
        counter += 1;
    }
    evil_str[counter] = '\0';
    while (str_len2 != -1) {
        str[str_len2] = evil_str[str_len2];
        str_len2 -= 1;
    }
    return (str);
}
