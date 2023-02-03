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
