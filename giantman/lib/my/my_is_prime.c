/*
** EPITECH PROJECT, 2021
** my_is_prime.c
** File description:
** my_is_prime.c
*/

int my_is_prime(int nb)
{
    for (int a = 2; a < nb - 1; a++) {
        if (nb % a == 0) {
            return (0);
        }
    }
    return (1);
}
