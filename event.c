/*
** EPITECH PROJECT, 2023
** event
** File description:
** event management
*/
#include "window.h"

void close_event(window *ptr)
{
    if (ptr->event.type == sfEvtClosed)
        sfRenderWindow_close(ptr->window);
}

void game_event(window *ptr)
{
    while (sfRenderWindow_pollEvent(ptr->window,&ptr->event)) {
        close_event(ptr);
    }
}