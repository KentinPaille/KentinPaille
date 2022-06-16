/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** put all type
*/

#include "my.h"
#include "bsprintf.h"

void my_putmodulo_from_va_list(va_list ap)
{
    my_putstr("%");
}

void my_put_unsigned_nbr_from_va_list(va_list ap)
{
    my_put_unsigned_nbr(va_arg(ap, unsigned int));
}

void find_my_fct(va_list ap, char str)
{
    int z = 0;

    while (init_flag[z].flag != -1) {
        if (init_flag[z].flag == str) {
            (*init_flag[z].fct_ptr)(ap);
            break;
        }
        z += 1;
    }
    if (init_flag[z].flag == -1) {
        my_putstr("%");
        my_putchar(str);
    }
}

int my_printf(const char *str, ...)
{
    va_list ap;

    va_start(ap, str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%') {
            i += 1;
            find_my_fct(ap, str[i]);
        } else {
            my_putchar(str[i]);
        }
    }
    va_end(ap);
    return (0);
}