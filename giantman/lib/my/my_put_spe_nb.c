/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** A function who print a number.
*/

#include "my.h"

unsigned int my_put_unsigned_nbr(unsigned int nb)
{
    unsigned long max = 1;
    unsigned long number = nb;

    if (number == 0) {
        my_putchar('0');
    }
    while (number / max != 0) {
        max = max * 10;
    }
    while (max != 1) {
        number = number - number / max * max;
        max = max / 10;
        my_putchar(number / max + 48);
    }
    return (0);
}

int my_put_long_nbr(long int nb)
{
    long long max = 1;
    long long number = nb;

    if (nb < 0) {
        nb *= -1;
        my_putchar('-');
    }
    if (number == 0) {
        my_putchar('0');
    }
    while (number / max != 0) {
        max = max * 10;
    }
    while (max != 1) {
        number = number - number / max * max;
        max = max / 10;
        my_putchar(number / max + 48);
    }
    return (0);
}

int my_put_unsigned_long_nbr(unsigned long int nb)
{
    unsigned long long max = 1;
    unsigned long long number = nb;

    if (number == 0) {
        my_putchar('0');
    }
    while (number / max != 0) {
        max = max * 10;
    }
    while (max != 1) {
        number = number - number / max * max;
        max = max / 10;
        my_putchar(number / max + 48);
    }
    return (0);
}