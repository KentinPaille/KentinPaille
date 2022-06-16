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
stock_data_t *push_data(stock_data_t *data);
stock_data_t *init_data(void);
tree_binary_t *create_my_binary_tree(tree_binary_t *tree);

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
    my_printf("%i ", size_buff);
    return (0);
}

stock_data_t *find_my_path(stock_data_t *data, tree_binary_t *tree)
{
    tree_binary_t *tmp = init_binary_tree();
    int str_len = 0;

    while (1) {
        data->letter = tree->letter;
        tmp = tree;
        data->path[str_len] = '\0';
        set_bit(&str_len, tree, data);
        data->path = rev_bit(data->path, data->len_path);
        tree = tmp;
        if (tree->next == NULL)
            break;
        tree = tree->next;
        data = push_data(data);
    }
    return (data);
}

int antman(char *file)
{
    tree_binary_t *tree = init_binary_tree();
    stock_data_t *data = init_data();
    int nb_node = 0;

    tree = push_back(tree, file[0]);
    nb_node += 1;
    for (int i = 1; file[i] != '\0'; i++) {
        if (found_char(&tree, file[i], &nb_node) != 1) {
            tree = push_back(tree, file[i]);
            nb_node += 1;
        }
    }
    tree = bubulsort(tree);
    print_my_tree(tree);
    tree = create_my_binary_tree(tree);
    data = find_my_path(data, tree);
    print_compressed(data, file, tree);
}

int main(int ac, char **av)
{
    char *file;
    int nb_oc = 0;

    if (error_gestion(av, ac) == 84)
        return (84);
    if (open_file(av[1], &file) == 84)
        return (84);
    antman(file);
    return (0);
}