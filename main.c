/*
** EPITECH PROJECT, 2023
** main
** File description:
** main function
*/
#include "window.h"
#include "my.h"
#include "monster.h"

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    window ptr;enemy pt;
    windows(&ptr, av[1],&pt);
    return (0);
}
