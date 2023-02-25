/*
** EPITECH PROJECT, 2023
** count
** File description:
** count elem
*/
#include "my.h"

int count_line(char *str)
{
    int y = 0;
    for (int i = 0;str[i] != '\0';i++) {
        if (verif(str[i]) == 0)
            y++;
    }
    return y + 1;
}

int *count_cols(char *str)
{
    int a = 0;
    int x = 0;int y = count_line(str);
    int *tab = (int*)malloc(sizeof(int) * y);
    for (int i = 0;str[i] != '\0';i++) {
        if (verif(str[i]) == 1)
            x++;
        else {
            tab[a] = x;
            a++;x = 0;
        }
    }
    tab[a] = x;
    return tab;
}
