/*
** EPITECH PROJECT, 2021
** my_compute_square_root.c
** File description:
** my_compute_square_root.c
*/

int my_compute_square_root(int nb)
{
    for (int a = 0; a < nb; a++) {
        if (a * a == nb) {
            return a;
        }
    }
    return (0);
}
