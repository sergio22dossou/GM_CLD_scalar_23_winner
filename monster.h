/*
** EPITECH PROJECT, 2023
** monster
** File description:
** monster header
*/
#include "my.h"
#ifndef MONSTER_H_
    #define MONSTER_H_

typedef struct monst monst;
struct monst {
    sfVector2f pos;
    sfSprite *spr;
    sfTexture *text;
    char c;
    float velocity;
    int charges;
};

typedef struct enemy enemy;
struct enemy {
    sfClock *clk;
    sfTime time;
    float s;
    sfIntRect rec;
    monst *prim;
};
void browse_tab(char *file, enemy *ptr);
void init_monster(enemy *pt);
void draw_monster(enemy *pt, window *ptr);
void move_monster_l(enemy *pt);
void move_monster_r(enemy *pt);
void destroy_monster(enemy *pt);
void windows(window *ptr, char *file, enemy *pt);
void move_simple_rect(enemy *pt, int max);
void init_monst_im(enemy *pt);
#endif
