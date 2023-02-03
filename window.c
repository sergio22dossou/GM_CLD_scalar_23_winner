/*
** EPITECH PROJECT, 2023
** window
** File description:
** window opening
*/
#include "window.h"
#include "my.h"

void init_windata(window *ptr)
{
    ptr->mode.width = 1600;
    ptr->mode.height = 1000;
    ptr->mode.bitsPerPixel = 32;
    ptr->name = "Athene adventure";
    ptr->window = sfRenderWindow_create(ptr->mode,ptr->name,sfDefaultStyle,NULL);
}

void destroy_windata(window *ptr)
{
    sfRenderWindow_destroy(ptr->window);
}

void windows(window *ptr)
{
    init_windata(ptr);
    while (sfRenderWindow_isOpen(ptr->window)) {
        sfRenderWindow_display(ptr->window);
        while (sfRenderWindow_pollEvent(ptr->window,&ptr->event)) {
            close_event(ptr);
        }
    }
    destroy_windata(ptr);
}