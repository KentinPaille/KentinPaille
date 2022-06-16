/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my.h
*/

#pragma once

struct tree_binary {
    char letter;
    int nb_rec;
    int index;
    int bool_pos;
    struct tree_binary *up;
    struct tree_binary *next;
    struct tree_binary *prev;
    struct tree_binary *left;
    struct tree_binary *right;
};

typedef struct tree_binary tree_binary_t;

struct stock_data {
    char letter;
    int len_path;
    char *path;
    struct stock_data *next;
    struct stock_data *prev;
};

typedef struct stock_data stock_data_t;