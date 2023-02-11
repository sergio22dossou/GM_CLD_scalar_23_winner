/*
** EPITECH PROJECT, 2023
** g
** File description:
** g
*/

#include "my.h"
#include "window.h"
#include "player.h"
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include<SFML/Audio/Music.h>
#include<SFML/Audio/SoundBuffer.h>
#include<SFML/Audio/Sound.h>
#include<SFML/System.h>

void init_content(backgrd *run, backgrd *run2)
{
    run->bgrd = sfTexture_createFromFile("ressources/Final/Background_0.png", NULL);
    run->bgrd_spr = sfSprite_create();
    sfSprite_setTexture(run->bgrd_spr, run->bgrd, sfTrue);
    sfSprite_setScale(run->bgrd_spr, (sfVector2f) {2, 2});
    run2->bgrd = sfTexture_createFromFile("ressources/Final/Background_1.png", NULL);
    run2->bgrd_spr = sfSprite_create();
    sfSprite_setTexture(run2->bgrd_spr, run2->bgrd, sfTrue);
    sfSprite_setScale(run2->bgrd_spr, (sfVector2f) {2, 2});
    run2->mv.x = 0;
    run2->mv.y = 0;
}

void init_ground(platform *grd, int x)
{
    grd->ground[x].plt_frm = sfTexture_createFromFile("ressources/Final/plat.png", NULL);
    grd->ground[x].plt_frm_spr = sfSprite_create();
    sfSprite_setTexture(grd->ground[x].plt_frm_spr, grd->ground[x].plt_frm, sfTrue);
    sfSprite_setScale(grd->ground[x].plt_frm_spr, (sfVector2f) {2, 2});
    grd->ground[x].mv.x = 184 * (x - 1);
    grd->ground[x].mv.y = 720;
    sfSprite_setPosition(grd->ground[x].plt_frm_spr, grd->ground[x].mv);
}

void init_player(player *alex)
{
    alex->set = sfClock_create();
    alex->ply = sfTexture_createFromFile("ressources/alexio.png", NULL);
    alex->ply_spr = sfSprite_create();
    sfSprite_setTexture(alex->ply_spr, alex->ply, sfTrue);
    alex->pos.x = 400;alex->pos.y = 590;
    sfSprite_setPosition(alex->ply_spr, alex->pos);
    sfSprite_setScale(alex->ply_spr, (sfVector2f) {2, 2});
    alex->rect.top = 0;
    alex->rect.left = 0;
    alex->rect.width = 45;
    alex->rect.height = 110;
    sfSprite_setTextureRect(alex->ply_spr, alex->rect);
}
