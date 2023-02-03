/*
** EPITECH PROJECT, 2023
** window
** File description:
** window header
*/
#include<SFML/Graphics/RenderWindow.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#ifndef WINDOW_H_
    #define WINDOW_H_

typedef struct window window;
struct window {
    sfRenderWindow *window;
    sfVideoMode mode;
    char *name;
    sfEvent event;
};

#endif
