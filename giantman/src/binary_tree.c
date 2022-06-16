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

tree_binary_t *push_back(tree_binary_t *n, char letter);
tree_binary_t *move_node(tree_binary_t *n, int pos);
tree_binary_t *init_binary_tree(void);
void print_uncompressed(char *file, tree_binary_t *tree, int i, int a);

int error_gestion(char **av, int ac)
{
    int type_fill;

    if (ac != 3) {
        return (84);
    }
    type_fill = my_getnbr(av[2]);
    if (type_fill == 0 || type_fill > 3) {
        return (84);
    }
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

void move_left(tree_binary_t **tree, tree_binary_t **tmp)
{
    while ((*tree)->right != NULL) {
        (*tree) = (*tree)->right;
    }
    while ((*tree)->prev->prev != NULL) {
        (*tree) = (*tree)->prev;
    }
    (*tmp) = (*tree);
    while ((*tmp)->up != NULL) {
        (*tmp) = (*tmp)->up;
    }
    for (; (*tmp)->right != NULL; (*tmp) = (*tmp)->right);
}

tree_binary_t *go_to_up(tree_binary_t **tree,
tree_binary_t **tmp, tree_binary_t **tmp2)
{
    while ((*tree)->up != NULL) {
        (*tree) = (*tree)->up;
    }
    if ((*tmp)->nb_rec <= (*tree)->nb_rec) {
        (*tree) = push_up_node((*tmp), (*tree));
    } else {
        (*tmp) = (*tree);
        while ((*tree)->right != NULL) {
            (*tree) = (*tree)->right;
        }
        if ((*tree)->next != NULL) {
            (*tree) = (*tree)->next;
            (*tree) = push_up_node((*tmp), (*tree));
        } else {
            (*tree) = push_up_node((*tmp2), (*tmp));
        }
    }
    move_left(tree, tmp);
}