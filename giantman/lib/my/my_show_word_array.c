/*
** EPITECH PROJECT, 2021
** Task03
** File description:
** Displays every word of a string array, line by line
*/

#include "my.h"

void my_show_word_array(char *const *tab)
{
    int count = 0;

    while (tab[count]) {
        my_putstr(tab[count]);
        my_putchar('\n');
        count++;
    }
    return;
}
