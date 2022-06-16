/*
** EPITECH PROJECT, 2022
** rev_bit_tool.c
** File description:
** tool for rev bit
*/
#include "binary_tree.h"
#include "my.h"
#include "antman.h"
#include <stddef.h>

int set_nb_char(bit_tool_t *tool, int bits_nbr)
{
    if (bits_nbr % 8 == 0)
        tool->nb_char -= 1;
    return (tool->nb_char);
}

int set_bits_nbr(int run, int bits_nbr)
{
    if (run == 1) {
        bits_nbr -= 1;
    }
    return (bits_nbr);
}

char *add_last_char(bit_tool_t *tool)
{
    for (int i = 0; i != tool->nb_char + 1; i++) {
        tool->rev_oct[i] = '\0';
    }
    return (tool->rev_oct);
}

int next_byte(bit_tool_t *tool)
{
    if (tool->b == 8) {
        tool->rev_nb += 1;
        tool->b = 0;
    }
    return (tool->b);
}

int is_byte_over(bit_tool_t *tool, int bits_nbr)
{
    if (tool->a == 0) {
        tool->a = 8;
        bits_nbr -= 1;
    }
    return (bits_nbr);
}