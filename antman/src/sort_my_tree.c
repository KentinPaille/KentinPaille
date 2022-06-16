/*
** EPITECH PROJECT, 2021
** sort_my_tree.c
** File description:
** The principal file
*/

#include "my.h"
#include "binary_tree.h"
#include "antman.h"
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>

int print_char_to_bin(char c)
{
    int a = 0;

    for (int i = 7; i != -1; i--) {
        a = (c & (1 << i)) >> i;
        my_printf("%i ", a);
    }
}

tree_binary_t *tri_me_tree(tree_binary_t *tree, int *run)
{
    char letter_save;
    int nb_save = 0;

    while (tree->next) {
        if (tree->nb_rec > (tree->next)->nb_rec) {
            letter_save = tree->next->letter;
            nb_save = tree->next->nb_rec;
            tree->next->letter = tree->letter;
            tree->next->nb_rec = tree->nb_rec;
            tree->letter = letter_save;
            tree->nb_rec = nb_save;
            *run = 1;
        }
        tree = tree->next;
    }
    return (tree);
}

tree_binary_t *bubulsort(tree_binary_t *tree)
{
    tree = move_node(tree, 1);
    int run = 1;

    while (run != 0) {
        run = 0;
        tree = tri_me_tree(tree, &run);
        tree = move_node(tree, 1);
    }
    return (tree);
}

int my_node_len(tree_binary_t *tree)
{
    int len = 0;

    tree = move_node(tree, 1);
    while (tree->next) {
        len += 1;
        tree = tree->next;
    }
    return (len);
}

tree_binary_t *push_up_node(tree_binary_t *node_1, tree_binary_t *node_2)
{
    tree_binary_t *head = init_binary_tree();

    node_1->up = head;
    node_2->up = head;
    head->left = node_1;
    node_1->bool_pos = 1;
    head->right = node_2;
    node_2->bool_pos = 0;
    head->nb_rec = node_1->nb_rec + node_2->nb_rec;
    return (head);
}