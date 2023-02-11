/*
** EPITECH PROJECT, 2022
** array
** File description:
** array
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "window.h"
#include "player.h"
#include "my.h"

int my_strlen(const char *str);
char **array_maker(int rows, char *str)
{
    int i; int cols = 0; int x = 0;
    char **tab;
    tab = (char **)malloc(sizeof(char *) * (rows + 1));
    for (i = 0; i < rows; i++) {
        tab[i] = (char *)malloc(sizeof(char) * (my_strlen(str)));
        x++;
    }
    tab[rows] = NULL;
    return (tab);
}

char **transcript(char *str)
{
    int i = 0; int k = 0; int j = 0;
    int cols = 1; int rows = 1; char **tab;
    for (int i = 0; str[i] != '\n'; i++) {
        if ((str[i] == ' ') && (str[i + 1] != ' '))
            rows++;
    }
    tab = array_maker(rows, str);
    for (k = 0; str[k] != '\0'; k++) {
        if ((str[k] != ' ')) {
            tab[i][j] = str[k];
            j++;
        } if ((str[k] == ' ') && (str[k + 1] != ' ')) {
            tab[i][j] = '\0';
            i++; j = 0;
        } if (str[k + 1] == '\0') {
            tab[i][j] = '\0';
            i++; j = 0;
        }
    }
    return (tab);
}
