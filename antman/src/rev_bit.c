/*
** EPITECH PROJECT, 2022
** rev_bit.c
** File description:
** reverse bits
*/
#include "binary_tree.h"
#include "my.h"
#include "antman.h"
#include <stddef.h>

char fill_bits(stock_data_t *data, int len_char, char letter, int spot_remain)
{
    if (data->path[len_char / 8] & (1 << 7 - len_char % 8))
        letter |= 1 << spot_remain;
    return (letter);
}

bit_tool_t *innit_bit_tool(int bits_nbr)
{
    bit_tool_t *tool = malloc(sizeof(bit_tool_t));

    tool->nb_char = bits_nbr / 8;
    tool->rev_nb = 0;
    tool->rev_oct = malloc(sizeof(char) * (tool->nb_char + 1));
    tool->a = 0;
    tool->b = 0;
    tool->run = 0;
}

int write_bit(bit_tool_t *tool, int bits_nbr, char *oct)
{
    if (oct[tool->nb_char] & (1 << 8 - tool->a))
        tool->rev_oct[tool->rev_nb] |= 1 << 8 - tool->b - 1;
    bits_nbr -= 1;
    return (bits_nbr);
}

char *rev_bit(char *oct, int bits_nbr)
{
    bit_tool_t *tool = innit_bit_tool(bits_nbr);

    tool->rev_oct = add_last_char(tool);
    tool->nb_char = set_nb_char(tool, bits_nbr);
    while (tool->nb_char != -1) {
        bits_nbr = set_bits_nbr(tool->run, bits_nbr);
        bits_nbr += 1 * (tool->nb_char);
        tool->a = (bits_nbr) % 9;
        bits_nbr = is_byte_over(tool, bits_nbr);
        while (tool->a != 0) {
            bits_nbr = write_bit(tool, bits_nbr, oct);
            tool->a = (bits_nbr) % 9;
            tool->b += 1;
            tool->b = next_byte(tool);
        }
        tool->run = 1;
        tool->b = next_byte(tool);
        tool->nb_char -= 1;
    }
    return (tool->rev_oct);
}