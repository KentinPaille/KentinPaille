/*
** EPITECH PROJECT, 2021
** my_strlen.c
** File description:
** my_strlen.c
*/

int my_strlen(char const *str)
{
    int count = 0;

    while (str[count] != '\0') {
        count += 1;
    }
    return (count);
}
