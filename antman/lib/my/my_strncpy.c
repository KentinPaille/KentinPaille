/*
** EPITECH PROJECT, 2021
** my_strncpy
** File description:
** my_strncpy
*/

char *my_strncpy(char *dest , char const *src, int n)
{
    int i = 0;

    for (; i != n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}
