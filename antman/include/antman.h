/*
** EPITECH PROJECT, 2022
** antman.h
** File description:
** include antman functions
*/
#include "binary_tree.h"

#pragma once

int print_char_to_bin(char c);
tree_binary_t *push_back(tree_binary_t *n, char letter);
tree_binary_t *move_node(tree_binary_t *n, int pos);
tree_binary_t *init_binary_tree(void);
int found_char(tree_binary_t **tree, char let, int *nb_node);
void print_my_tree(tree_binary_t *tree);
char *rev_bit(char *oct, int bits_nbr);
void print_compressed(stock_data_t *data, char *file, tree_binary_t *tree);
char *rev_bit(char *oct, int bits_nbr);
int set_nb_char(bit_tool_t *tool, int bits_nbr);
int set_bits_nbr(int run, int bits_nbr);
char *add_last_char(bit_tool_t *tool);
int next_byte(bit_tool_t *tool);
int is_byte_over(bit_tool_t *tool, int bits_nbr);
char fill_bits(stock_data_t *data, int len_char, char letter, int spot_remain);