/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** my_put_nbr
*/

#include "my.h"

long size_number(long number)
{
    long size2 = 1;

    while (number != 0) {
        size2 *= 10;
        number /= 10;
    }
    size2 /= 10;
    return size2;
}

int my_put_nbr(int true_number)
{
    long nb = true_number;
    long size;
    long digit;

    if (nb < 0) {
        nb *= -1;
        my_putchar('-');
    }
    if (nb == 0) {
        my_putchar('0');
    } else {
        size = size_number(nb);
        while (size > 0) {
            digit = nb / size;
            my_putchar('0' + digit);
            nb -= digit * size;
            size /= 10;
        }
    }
    return (0);
}
