/*
** EPITECH PROJECT, 2021
** my_strcapitalize.c
** File description:
** my_strcapitalize.c
*/

#include "my.h"

int check_2(char *str, int i)
{
    if (str[i] >= 'a' && str[i] <= 'z') {
        return (1);
    } else {
        return (0);
    }
}

char *my_strcapitalize(char *str)
{
    int a;

    if (str == NULL) {
        return (NULL);
    }
    my_strlowcase(str);
    if (str[0] >= 'a' && str[0] <= 'z') {
        str[0] -= 32;
    }
    for (int i = 1; str[i] != '\0'; i++) {
        if ((str[i - 1] >= '0' && str[i - 1] <= '9') || (str[i - 1] >= 'A'
        && str[i - 1] <= 'Z')) {
            a++;
        } else if (!(str[i - 1] >= 'a' && str[i - 1] <= 'z')
        && check_2(str, i)) {
            str[i] = str[i] - 32;
        }
    }
    return (str);
}
