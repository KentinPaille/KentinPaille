/*
** EPITECH PROJECT, 2021
** my_strcmp.c
** File description:
** my_strcmp.c
*/

int my_strcmp(char const *s1 , char const *s2)
{
    int count1 = 0;

    while (s1[count1] == s2[count1] && s1[count1] != '\0') {
        count1++;
    }
    return (s1[count1] - s2[count1]);
}
