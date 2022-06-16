/*
** EPITECH PROJECT, 2022
** bit_read.c
** File description:
** read the bits and print the coressponding letter
*/

#include <stdio.h>
#include "binary_tree.h"
#include "my.h"

tree_binary_t *create_my_binary_tree(tree_binary_t *tree);

tree_binary_t *print_char(tree_binary_t *tree, int *nb_char)
{
    if (tree->left == NULL && tree->right == NULL) {
        my_printf("%c", tree->letter);
        *nb_char += 1;
        while (tree->up != NULL)
            tree = tree->up;
    }
    return (tree);
}

tree_binary_t *push_left(tree_binary_t *tree)
{
    while (tree->prev != NULL) {
        tree = tree->prev;
    }
    tree = tree->next;
    tree->prev = NULL;
    tree = create_my_binary_tree(tree);
    return (tree);
}

void print_uncompressed(char *file, tree_binary_t *tree, int i, int len_txt)
{
    int bit_len = 0;
    int nb_char = 0;

    tree = push_left(tree);
    while (tree->up != NULL)
        tree = tree->up;
    while (1) {
        tree = print_char(tree, &nb_char);
        if (bit_len == 0 && file[i + 1] != '\0') {
            bit_len = 8;
            i++;
        } else if (nb_char == len_txt)
            return;
        if (file[i] & (1 << bit_len - 1))
            tree = tree->left;
        else
            tree = tree->right;
        bit_len--;
    }
}