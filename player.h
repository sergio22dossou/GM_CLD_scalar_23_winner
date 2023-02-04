/*
** EPITECH PROJECT, 2023
** player
** File description:
** player
*/

#include "window.h"

#ifndef PLAYER_H_
    #define PLAYER_H_

typedef struct player {
    sfSprite *ply_spr;
    sfTexture *ply;
    sfVector2f pos;
    sfIntRect rect;
} player;

typedef struct backgrd {
    sfSprite *bgrd_spr;
    sfTexture *bgrd;
} backgrd;

typedef struct pm {
    sfSprite *plt_frm_spr;
    sfTexture *plt_frm;
    sfVector2f mv;
} pm;

typedef struct platform {
    pm ground[9];
} platform;

typedef struct timer {
    sfClock *clk;
    sfTime time;
    float seconds;
}

#endif
