/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** my_putstr
*/

#include "my.h"

int my_putstr(char const *str)
{
    int len = my_strlen(str);
    write(1, str, len);
    return (0);
}
