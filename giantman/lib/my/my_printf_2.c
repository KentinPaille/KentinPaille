/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** put all type
*/

#include <stdarg.h>
#include <stddef.h>
#include <string.h>
#include "my.h"

void my_put_nbr_to_bin_from_va_list(va_list ap)
{
    unsigned int i = va_arg(ap, unsigned int);
    char res[i];
    int turn = 0;

    while (i / 2 != 0) {
        res[turn] = i % 2 + '0';
        i /= 2;
        turn += 1;
    }
    res[turn] = i % 2 + '0';
    res[turn + 1] = '\0';
    my_putstr(my_revstr(res));
}

void put_null(char str)
{
    if (str < 10) {
        my_putstr("00");
    } else if (str <= 32) {
        my_putstr("0");
    }
}

void my_putstr_octal_from_va_list(va_list ap)
{
    char *str = va_arg(ap, char *);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] <= 32 || str[i] == 127) {
            my_putstr("\\");
            put_null(str[i]);
            my_put_nbr(str[i]);
        } else {
            my_putchar(str[i]);
        }
    }
}

void my_put_octan_from_va_list(va_list ap)
{
    unsigned int i = va_arg(ap, unsigned int);
    char res[i];
    int turn = 0;

    while (i / 8 != 0) {
        res[turn] = i % 8 + '0';
        i /= 8;
        turn += 1;
    }
    res[turn] = i % 8 + '0';
    res[turn + 1] = '\0';
    my_putstr(my_revstr(res));
}

void my_put_hexa_with_small_letters_from_va_list(va_list ap)
{
    unsigned int i = va_arg(ap, unsigned int);
    unsigned int res;
    unsigned int hold;
    int j = 0;
    char hexa[i];

    res = i;
    while (res != 0) {
        hold = res % 16;
        if (hold < 10) {
            hexa[j] = 48 + hold;
        } else {
            hexa[j] = 97 + hold - 10;
        }
        res = res / 16;
        j += 1;
    }
    hexa[j] = '\0';
    my_putstr(my_revstr(hexa));
}