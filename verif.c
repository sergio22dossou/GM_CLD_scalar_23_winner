/*
** EPITECH PROJECT, 2023
** verif
** File description:
** character check
*/
#include "my.h"

int verif(char c)
{
    if (c != ' ' && c != '\n' && c != '\0')
        return 1;
    else
        return 0;
}
