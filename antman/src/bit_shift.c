/*
** EPITECH PROJECT, 2021
** bit_shift.c
** File description:
** Manage the bit shifting
*/
#include "binary_tree.h"
#include "my.h"
#include "antman.h"
#include <stddef.h>

void print_occurency(tree_binary_t *tree)
{
    while (tree->prev->prev != NULL)
        tree = tree->prev;
    while (tree != NULL) {
        my_printf("%c%i ", tree->letter, tree->nb_rec);
        tree = tree->next;
    }
}

stock_data_t *find_node_letter(char letter, stock_data_t *data)
{
    while (data->next != NULL)
        data = data->next;
    while (data->letter != letter)
        data = data->prev;
    return (data);
}

char fill_letter(char letter, stock_data_t *data, int len_char,
int spot_remaining)
{
    if (data->path[len_char / 8] & (1 << 7 - len_char % 8))
        letter |= 1 << spot_remaining;
    return (letter);
}

char print_letter(char letter, int *spot_remaining)
{
    if ((*spot_remaining) == 0) {
        (*spot_remaining) = 8;
        my_printf("%c", letter);
        letter = '\0';
    }
    return (letter);
}

void print_compressed(stock_data_t *data, char *file, tree_binary_t *tree)
{
    int spot_remaining = 7;
    int pos_char = 0;
    char letter = '\0';

    print_occurency(tree);
    my_printf("\n");
    while (data->next != NULL)
        data = data->next;
    for (int i = 0; file[i] != '\0'; i++) {
        data = find_node_letter(file[i], data);
        for (int len_char = 0; len_char != data->len_path; len_char++) {
            letter = fill_bits(data, len_char, letter, spot_remaining);
            letter = print_letter(letter, &spot_remaining);
            spot_remaining -= 1;
        }
    }
    if (spot_remaining != 8)
        my_printf("%c", letter);
}
