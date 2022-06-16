/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** put all type
*/

#include "my.h"

void my_put_hexa_with_high_letters_from_va_list(va_list ap)
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
            hexa[j] = 65 + hold - 10;
        }
        res = res / 16;
        j += 1;
    }
    hexa[j] = '\0';
    my_putstr(my_revstr(hexa));
}

void my_putpoint(va_list ap)
{
    unsigned long res = (unsigned long)va_arg(ap, void *);
    unsigned int hold = 0;
    int j = 0;
    char hexa[32000];

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
    my_putstr("0x");
    my_putstr(my_revstr(hexa));
}

void my_putstr_from_va_list(va_list ap)
{
    my_putstr(va_arg(ap, char *));
}

void my_putchar_from_va_list(va_list ap)
{
    my_putchar(va_arg(ap, int));
}

void my_put_nbr_from_va_list(va_list ap)
{
    my_put_nbr(va_arg(ap, int));
}