/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my.h
*/

#pragma once

#include <stdbool.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>

int my_printf(const char *str, ...);
unsigned int my_put_unsigned_nbr(unsigned int nb);
int my_put_unsigned_long_nbr(unsigned long int nb);
int my_put_long_nbr(long int nb);
void my_putchar(char c);
char *my_strstr(char *str, char const *to_find);
int my_isneg(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_put_nbr(int nb);
int my_strncmp(char const *s1, char const *s2, int n);
void my_swap(int *a, int *b);
char *my_strupcase(char *str);
int my_putstr(char const *str);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
char *my_strcapitalize(char *str);
int my_getnbr(char const *str);
int my_str_isalpha(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isnum(char const *str);
int my_compute_power_rec(int nb, int power);
int my_str_islower(char const *str);
int my_compute_square_root(int nb);
int my_str_isupper(char const *str);
int my_is_prime(int nb);
int my_str_isprintable(char const *str);
int my_find_prime_sup(int nb);
int my_showstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_showmem(char const *str, int size);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int is_alpha(char c);
int is_num(char c);
int check_alphanum(int *i, char const *str_cpy);
void learn_word(int *i, char **array , int *p_of_str, char *str_cpy);
char **my_str_to_word_array(char const *str);
int check_alphanum(int *i, char const *str_cpy);
int check_2(char *str, int i);
int check(char *str, char const *to_find, int count1);
long size_number(long number);
int strlen_to_end(char const *str, int count);
int check_sign(char const *str, int *count);
int bad_nb(char const *str, int sign, int *count, int *nb);
void my_show_word_array(char *const *tab);
int is_alphanum(char letter);
int get_wcount(char const *str);
char *my_strdup(char const *src);
