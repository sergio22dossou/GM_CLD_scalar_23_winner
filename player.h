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
    sfClock *set;
    sfTime jump;
    float se;
    int state;
} player;

typedef struct backgrd {
    sfSprite *bgrd_spr;
    sfTexture *bgrd;
    sfVector2f mv;
} backgrd;

typedef struct pm {
    sfSprite *plt_frm_spr;
    sfTexture *plt_frm;
    sfVector2f mv;
} pm;

typedef struct platform {
    pm ground[10];
} platform;

typedef struct timer {
    sfClock *clk;
    sfTime time;
    float seconds;
} timer;

typedef struct obs_tkl {
    sfTexture *obs;
    sfSprite *obs_spr;
    sfVector2f mv;
} obs_tkl;

#endif
