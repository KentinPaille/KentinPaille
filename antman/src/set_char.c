/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** The principal file
*/

#include "my.h"
#include "binary_tree.h"
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>

void set_bit(int *str_len, tree_binary_t *tree, stock_data_t *data)
{
    for (*str_len = 0; tree->up != NULL; data->len_path++) {
        if (data->len_path % 8 == 0 && data->len_path != 0) {
            *str_len += 1;
            data->path[*str_len] = '\0';
        }
        if (tree->bool_pos == 1) {
            data->path[*str_len] |= (1 << (7 - data->len_path +
            (8 * (*str_len))));
        }
        tree = tree->up;
    }
}