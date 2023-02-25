/*
** EPITECH PROJECT, 2023
** set object
** File description:
** set object and display it
*/
#include "my.h"
#include "window.h"
#include "monster.h"

/*Monster data initialisation*/
void init_monster(enemy *pt)
{
    for (int i = 0;i < 3;i++) {
        pt->prim[i].text = sfTexture_createFromFile("ressources/arbre.png",NULL);
        pt->prim[i].spr = sfSprite_create();
        sfSprite_setTexture(pt->prim[i].spr, pt->prim[i].text, sfTrue);
        sfSprite_setPosition(pt->prim[i].spr,pt->prim[i].pos);
    }
}

/*Draw monster sprite*/
void draw_monster(enemy *pt, window *ptr)
{
    pt->time = sfClock_getElapsedTime(pt->clk);
    pt->s = pt->time.microseconds / 100000;
    if (pt->s > 4.6) {
        move_simple_rect(pt,744);
        for (int i = 0;i < 3;i++) {
            sfSprite_setTextureRect(pt->prim[i].spr,pt->rec);
        }
        sfClock_restart(pt->clk);
    }
}

/*move enemy sprite  in the left direction*/
void move_monster_l(enemy *pt)
{
    for (int i = 0;i < 3;i++) {
        pt->prim[i].pos.x -= 0.4;
        sfSprite_setPosition(pt->prim[i].spr,pt->prim[i].pos);
    }
}

/*move enemy sprite in the right direction*/
void move_monster_r(enemy *pt)
{
    for (int i = 0;i < 3;i++) {
        pt->prim[i].pos.x += 0.4;
        sfSprite_setPosition(pt->prim[i].spr,pt->prim[i].pos);
    }
}

/* Destroy enemy data*/
void destroy_monster(enemy *pt)
{
    sfClock_destroy(pt->clk);
    for (int i = 0;i < 3;i++) {
        sfTexture_destroy(pt->prim[i].text);
        sfSprite_destroy(pt->prim[i].spr);
    }
}
