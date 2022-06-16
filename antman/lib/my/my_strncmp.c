/*
** EPITECH PROJECT, 2021
** my_strncmp.c
** File description:
** my_strncmp.c
*/

int my_strncmp(char const *s1 , char const *s2, int n)
{
    int count1 = 0;

    while (s1[count1] == s2[count1] && count1 < n - 1) {
        count1++;
    }
    if (s1[count1] == s2[count1]) {
        return (0);
    } else {
        return (s1[count1] - s2[count1]);
    }
}
