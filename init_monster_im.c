/*
** EPITECH PROJECT, 2023
** 
** File description:
** 
*/
#include "monster.h"

void move_simple_rect(enemy *pt,int max)
{
    if (pt->rec.left < max)
        pt->rec.left = pt->rec.left + 193;
    else
        pt->rec.left = 0;
}

void init_monst_im(enemy *pt)
{
    pt->rec.height = 90;pt->rec.left = 93;pt->rec.top = 0;pt->rec.width = 93;
    for (int i = 0;i < 3;i++) {
        pt->prim[i].text = sfTexture_createFromFile("ressources/Bringer-Of-Death/SpriteSheet/mystmonst.png",NULL);
        pt->prim[i].spr = sfSprite_create();
        sfSprite_setTexture(pt->prim[i].spr,pt->prim[i].text,sfTrue);
        sfSprite_setTextureRect(pt->prim[i].spr,pt->rec);
        sfSprite_setPosition(pt->prim[i].spr,pt->prim[i].pos);
        sfSprite_setScale(pt->prim[i].spr, (sfVector2f) {2,2});
    }
    pt->clk = sfClock_create();
}