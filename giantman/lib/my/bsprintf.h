/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my.h
*/

#pragma once

#include "my.h"

void my_put_nbr_to_bin_from_va_list(va_list ap);
void my_putstr_octal_from_va_list(va_list ap);
void my_putstr_from_va_list(va_list ap);
void my_putchar_from_va_list(va_list ap);
void my_put_nbr_from_va_list(va_list ap);
void my_put_hexa_with_small_letters_from_va_list(va_list ap);
void my_put_hexa_with_high_letters_from_va_list(va_list ap);
void my_put_octan_from_va_list(va_list ap);
void my_putmodulo_from_va_list(va_list ap);
void my_putpoint(va_list ap);
void my_put_unsigned_nbr_from_va_list(va_list ap);
void my_puterror_from_va_list(va_list ap);

struct bsprintf {
    char flag;
    void(*fct_ptr)(va_list ap);
};

const struct bsprintf init_flag[] =
{
    {'s', &my_putstr_from_va_list},
    {'S', &my_putstr_octal_from_va_list},
    {'o', &my_put_octan_from_va_list},
    {'x', &my_put_hexa_with_small_letters_from_va_list},
    {'X', &my_put_hexa_with_high_letters_from_va_list},
    {'c', &my_putchar_from_va_list},
    {'i', &my_put_nbr_from_va_list},
    {'%', &my_putmodulo_from_va_list},
    {'u', &my_put_unsigned_nbr_from_va_list},
    {'d', &my_put_nbr_from_va_list},
    {'b', &my_put_nbr_to_bin_from_va_list},
    {'p', &my_putpoint},
    {-1, NULL},
};
