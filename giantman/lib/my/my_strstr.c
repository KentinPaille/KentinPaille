/*
** EPITECH PROJECT, 2021
** my_strstr
** File description:
** my_strstr
*/

int check(char *str, char const *to_find, int count1)
{
    int count2 = 0;

    while ((to_find[count2] != '\0') && (str[count1] == to_find[count2])) {
        count1++;
        count2++;
    }
    if (to_find[count2] == '\0') {
        return (1);
    } else {
        return (0);
    }
}

char *my_strstr(char *str , char const *to_find)
{
    int compter = 0;

    while (str[compter] != '\0') {
        if (check(str, to_find, compter) == 1) {
            return (&str[compter]);
        }
        compter++;
    }
    return (0);
}
