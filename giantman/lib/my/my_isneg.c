/*
** EPITECH PROJECT, 2021
** my_isneg
** File description:
** test
*/

#include "my.h"

int my_isneg(int nb)
{
    if (nb >= 0) {
        my_putchar('P');
    } else {
        my_putchar('N');
    }
    return (0);
}
