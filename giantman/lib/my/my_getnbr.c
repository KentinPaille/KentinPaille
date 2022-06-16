/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** my_getnbr
*/

#include "my.h"

int check_sign(char const *str, int *count)
{
    char buffer = '+';

    while (str[*count] == '+' || str[*count] == '-') {
        if (buffer == str[*count]) {
            buffer = '+';
        } else {
            buffer = '-';
        }
        *count += 1;
    }
    if (buffer == '-') {
        return (-1);
    } else if (buffer == '+') {
        return (1);
    }
    return (0);
}

int my_getnbr(char const *str)
{
    int count = 0;
    int nb = 0;
    int sign;

    sign = check_sign(str, &count);
    if (str[count] < '0' && str[count] > '9') {
        return (0);
    }
    while (str[count] >= '0' && str[count] <= '9') {
        nb *= 10;
        nb += str[count] - '0';
        count += 1;
    }
    nb *= sign;
    return (nb);
}
