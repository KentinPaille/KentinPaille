/*
** EPITECH PROJECT, 2021
** gestion_node.c
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

tree_binary_t *push_back(tree_binary_t *n, char letter)
{
    tree_binary_t *tmp = n;
    tree_binary_t *new_node = malloc(sizeof(*new_node));

    while (tmp->next)
        tmp = tmp->next;
    new_node->nb_rec = 1;
    new_node->letter = letter;
    new_node->index = tmp->index + 1;
    new_node->prev = tmp;
    new_node->next = NULL;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->up = NULL;
    tmp->next = new_node;
    return (tmp);
}

tree_binary_t *move_node(tree_binary_t *n, int pos)
{
    if (!n)
        return (n);
    while ((int)n->index != pos && n->index != 0) {
        if ((int)n->index < pos) {
            n = n->next;
        } else {
            n = n->prev;
        }
    }
    return (n);
}

tree_binary_t *init_binary_tree(void)
{
    tree_binary_t *tree = malloc(sizeof(tree_binary_t));

    tree->letter = '\0';
    tree->index = 0;
    tree->nb_rec = 0;
    tree->up = NULL;
    tree->next = NULL;
    tree->prev = NULL;
    tree->bool_pos = 2;
    tree->right = NULL;
    tree->left = NULL;
    return (tree);
}

int found_char(tree_binary_t **tree, char let, int *nb_node)
{
    for (int i = 1; i != *nb_node + 1; i++) {
        (*tree) = move_node((*tree), i);
        if ((*tree)->letter == let) {
            (*tree)->nb_rec += 1;
            return (1);
        }
    }
    return (0);
}

void print_my_tree(tree_binary_t *tree)
{
    tree = move_node(tree, 1);
    while (tree) {
        tree = tree->next;
    }
}
