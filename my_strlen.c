/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** my_strlen
*/
#include<unistd.h>
#include<string.h>
#include<stdio.h>

int my_strlen(const char *str)
{
    int a;
    for (a = 0; str[a] != '\0'; a++);
    return (a + 1);
}
