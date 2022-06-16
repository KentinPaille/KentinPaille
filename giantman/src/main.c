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

tree_binary_t *push_up_node(tree_binary_t *node_1, tree_binary_t *node_2);
int error_gestion(char **av, int ac);
tree_binary_t *go_to_up(tree_binary_t **tree,
tree_binary_t **tmp, tree_binary_t **tmp2);
tree_binary_t *push_back(tree_binary_t *n, char letter);
tree_binary_t *move_node(tree_binary_t *n, int pos);
tree_binary_t *init_binary_tree(void);
void print_uncompressed(char *file, tree_binary_t *tree, int i, int a);
void set_bit(int *str_len, tree_binary_t *tree, stock_data_t *data);

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

int open_file(char *path, char **buff)
{
    int n;
    int m;
    int i = 0;
    int size_buff;
    struct stat st;

    stat(path, &st);
    size_buff = st.st_size;
    *buff = malloc(sizeof(char) * (size_buff + 1));
    n = open(path, O_RDONLY);
    read(n, *buff, size_buff);
    (*buff)[size_buff] = '\0';
    close(n);
    return (0);
}

int len_nb(int nb)
{
    int count = 0;

    if (nb != 0)
        count += 1;
    while (nb / 10 != 0) {
        count += 1;
        nb /= 10;
    }
    return (count);
}

void giantman(char *file)
{
    char *str = my_strdup(file);
    int pos = len_nb(my_getnbr(&file[0])) + 1;
    int nb_char = my_getnbr(&file[0]);
    int nb = 0;
    char letter = '\0';
    tree_binary_t *tree = init_binary_tree();

    while (1) {
        letter = file[pos];
        pos += 1;
        nb = my_getnbr(&file[pos]);
        pos += len_nb(nb);
        if (file[pos] != 32) {
            break;
        } else {
            tree = push_back(tree, letter);
            tree->nb_rec = nb;
            pos += 1;
        }
    }
    print_uncompressed(file, tree, (pos - 1), nb_char);
}

int main(int ac, char **av)
{
    char *file;

    if (error_gestion(av, ac) == 84)
        return (84);
    if (open_file(av[1], &file) == 84)
        return (84);
    giantman(file);
    return (0);
}