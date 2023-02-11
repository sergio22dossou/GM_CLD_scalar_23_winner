/*
** EPITECH PROJECT, 2023
** main
** File description:
** main function
*/
#include "window.h"
#include "my.h"

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    window ptr;
    windows(&ptr, av[1]);
    return (0);
}
