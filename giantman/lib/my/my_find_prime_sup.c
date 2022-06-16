/*
** EPITECH PROJECT, 2021
** my_find_prime_sup.c
** File description:
** my_find_prime_sup.c
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    int test = my_is_prime(nb);

    if (test == 1) {
        return (nb);
    } else {
        while (test == 0) {
            nb += 1;
            test = my_is_prime(nb);
        }
        return (nb);
    }
}
