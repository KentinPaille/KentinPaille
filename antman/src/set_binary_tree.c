/*
** EPITECH PROJECT, 2021
** main.c
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

tree_binary_t *push_up_node(tree_binary_t *node_1, tree_binary_t *node_2);
tree_binary_t *bubulsort(tree_binary_t *tree);

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

tree_binary_t *create_my_binary_tree(tree_binary_t *tree)
{
    tree_binary_t *tmp = init_binary_tree();
    tree_binary_t *tmp2 = init_binary_tree();

    tree = push_up_node(tree, tree->next);
    tree = tree->left;
    while (1) {
        for (; tree->up != NULL; tree = tree->up);
        tmp = tree;
        tmp2 = tree;
        while (tree->right != NULL)
            tree = tree->right;
        if (tree->next != NULL)
            tree = tree->next;
        else
            break;
        go_to_up(&tree, &tmp, &tmp2);
        if (tmp->next == NULL)
            break;
    }
    return (tree);
}

stock_data_t *init_data(void)
{
    stock_data_t *data = malloc(sizeof(stock_data_t));

    data->letter = '\0';
    data->len_path = 0;
    data->path = malloc(sizeof(char) * 4);
    data->next = NULL;
    data->prev = NULL;
}

stock_data_t *push_data(stock_data_t *data)
{
    stock_data_t *head = malloc(sizeof(stock_data_t));

    head->letter = '\0';
    head->len_path = 0;
    head->path = malloc(sizeof(char) * 4);
    head->next = NULL;
    head->prev = data;
    data->next = head;
    return (head);
}