/*
** EPITECH PROJECT, 2023
** window
** File description:
** window opening
*/
#include "window.h"
#include "my.h"
#include "player.h"
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include<SFML/Audio/Music.h>
#include<SFML/Audio/SoundBuffer.h>
#include<SFML/Audio/Sound.h>
#include<SFML/System.h>

void init_windata(window *ptr)
{
    ptr->mode.width = 1400;
    ptr->mode.height = 800;
    ptr->mode.bitsPerPixel = 32;
    ptr->name = "Athene adventure";
    ptr->window = sfRenderWindow_create(ptr->mode,ptr->name,sfDefaultStyle,NULL);
}

void destroy_windata(window *ptr)
{
    sfRenderWindow_destroy(ptr->window);
}

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
    alex->pos.x = 80;alex->pos.y = 590;
    sfSprite_setPosition(alex->ply_spr, alex->pos);
    sfSprite_setScale(alex->ply_spr, (sfVector2f) {2, 2});
    alex->rect.top = 0;
    alex->rect.left = 0;
    alex->rect.width = 45;
    alex->rect.height = 110;
    sfSprite_setTextureRect(alex->ply_spr, alex->rect);
}

void draw_grd_r(window *ptr, platform *grd, backgrd *run2)
{
    sfVector2f location;
    for (int i = 0; i < 10; i++) {
        location = sfSprite_getPosition(grd->ground[i].plt_frm_spr);
        if (location.x < -184) {
            grd->ground[i].mv.x = 1400;
            sfSprite_setPosition(grd->ground[i].plt_frm_spr, grd->ground[i].mv);
        } else {
            grd->ground[i].mv.x -= 1;
            sfSprite_setPosition(grd->ground[i].plt_frm_spr, grd->ground[i].mv);
        }
    }
    run2->mv.x -= 1;
    sfSprite_setPosition(run2->bgrd_spr, run2->mv);
    if (run2->mv.x < -1694)
        run2->mv.x = 1400;
}

void draw_grd_l(window *ptr, platform *grd, backgrd *run2)
{
    sfVector2f location;
    for (int i = 0; i < 10; i++) {
        location = sfSprite_getPosition(grd->ground[i].plt_frm_spr);
        if (location.x > 1400) {
            grd->ground[i].mv.x = -184;
            sfSprite_setPosition(grd->ground[i].plt_frm_spr, grd->ground[i].mv);
        } else {
            grd->ground[i].mv.x += 10;
            sfSprite_setPosition(grd->ground[i].plt_frm_spr, grd->ground[i].mv);
        }
    }
    run2->mv.x += 10;
    sfSprite_setPosition(run2->bgrd_spr, run2->mv);
    if (run2->mv.x > 1800)
        run2->mv.x = -1694;
}

void move_rect(sfIntRect *rect, int max_value)
{
    if (rect->left == max_value)
        rect->left = 0;
    else
        rect->left = rect->left + 45;
}

void my_free(backgrd *run, backgrd *run2, platform *grd, player *alex)
{
    sfTexture_destroy(run->bgrd);
    sfTexture_destroy(alex->ply);
    sfTexture_destroy(run2->bgrd);
    for (int i = 0; i < 10; i++)
        sfTexture_destroy(grd->ground[i].plt_frm);
    sfSprite_destroy(run->bgrd_spr);
    sfSprite_destroy(alex->ply_spr);
    sfSprite_destroy(run2->bgrd_spr);
    sfClock_destroy(alex->set);
    for (int i = 0; i < 10; i++)
        sfSprite_destroy(grd->ground[i].plt_frm_spr);
    free(run2);
    free(run);
    free(alex);
    free(grd);
}

void draw_backgrd(backgrd *run, backgrd *run2, player *alex, window *ptr)
{
    sfRenderWindow_display(ptr->window);
    sfRenderWindow_drawSprite(ptr->window, run->bgrd_spr, NULL);
    sfRenderWindow_drawSprite(ptr->window, run2->bgrd_spr, NULL);
    sfRenderWindow_drawSprite(ptr->window, alex->ply_spr, NULL);
}

void jump_mode(player *alex)
{
     if (alex->state == 1) {
         alex->jump = sfClock_getElapsedTime(alex->set);
         alex->se = alex->jump.microseconds / 100000;
         if (alex->se > 0.8) {
             sfSprite_move(alex->ply_spr,(sfVector2f) {0,-50});
             alex->pos = sfSprite_getPosition(alex->ply_spr);
             sfClock_restart(alex->set);
         }
     }
     if (alex->pos.y < 500)
         alex->state = 2;
     if (alex->state == 2) {
         alex->jump = sfClock_getElapsedTime(alex->set);
         alex->se = alex->jump.microseconds / 100000;
         if (alex->se > 0.8) {
             sfSprite_move(alex->ply_spr,(sfVector2f) {0,50});
             alex->pos = sfSprite_getPosition(alex->ply_spr);
             sfClock_restart(alex->set);
         }
     }
     if (alex->pos.y > 580)
         alex->state = 0;
}

void game_event(window *ptr, platform *grd, player *alex, backgrd *run2, timer *chrono)
{
    while (sfRenderWindow_pollEvent(ptr->window,&ptr->event)) {
        /*if (ptr->event.type == sfEvtKeyPressed) {
            if (chrono->seconds > 0.1) {
                move_rect(&alex->rect, 135);
                sfSprite_setTextureRect(alex->ply_spr, alex->rect);
                sfClock_restart(chrono->clk);
            }
           // if (ptr->event.key.code == sfKeyRight)
                //draw_grd_r(ptr, grd, run2);
            else if (ptr->event.key.code == sfKeyLeft)
                draw_grd_l(ptr, grd, run2);
           // else if (ptr->event.key.code == sfKeyUp && alex->state == 0)
             //   alex->state++;
            else if (ptr->event.key.code == sfKeyDown) {
                alex->rect.left = 225;
                sfSprite_setTextureRect(alex->ply_spr, alex->rect);
                sfRenderWindow_drawSprite(ptr->window, alex->ply_spr, NULL);
                alex->rect.left = 0;
            }
        }
        else {
            if (alex->pos.y == 590) {
                alex->rect.left = 180;
                sfSprite_setTextureRect(alex->ply_spr, alex->rect);
                sfRenderWindow_drawSprite(ptr->window, alex->ply_spr, NULL);
                alex->rect.left = 0;
            }
        }*/
        close_event(ptr);
    }
}

void windows(window *ptr)
{
    init_windata(ptr);
    backgrd *run = (backgrd *)malloc(sizeof(backgrd));
    backgrd *run2 = (backgrd *)malloc(sizeof(backgrd));
    platform *grd = (platform *)malloc(sizeof(platform));
    player *alex = (player *)malloc(sizeof(player));
    timer *chrono = (timer *)malloc(sizeof(timer));
    sfMusic *music = sfMusic_createFromFile("Shadow.ogg");
    sfMusic_play(music);
    chrono->clk = sfClock_create();
    init_player(alex);
    alex->state = 0;
    init_content(run, run2);
    for (int i = 0; i < 10; i++)
        init_ground(grd, i);
    while (sfRenderWindow_isOpen(ptr->window)) {
        chrono->time = sfClock_getElapsedTime(chrono->clk);
        chrono->seconds = chrono->time.microseconds / 100000;
        draw_backgrd(run, run2, alex, ptr);
        if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) {
            if (chrono->seconds > 0.1) {
                move_rect(&alex->rect, 135);
                sfSprite_setTextureRect(alex->ply_spr, alex->rect);
                sfClock_restart(chrono->clk);
            }
            draw_grd_r(ptr, grd, run2);
        }
        if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue && alex->state == 0) {
            if (chrono->seconds > 0.1) {
                move_rect(&alex->rect, 135);
                sfSprite_setTextureRect(alex->ply_spr, alex->rect);
                sfClock_restart(chrono->clk);
            }
            alex->state++;
        }
        if (sfKeyboard_isKeyPressed(sfKeyDown) == sfFalse && sfKeyboard_isKeyPressed(sfKeyRight) == sfFalse
        && sfKeyboard_isKeyPressed(sfKeyUp) == sfFalse) {
            if (alex->pos.y == 590) {
                alex->rect.left = 180;
                sfSprite_setTextureRect(alex->ply_spr, alex->rect);
                sfRenderWindow_drawSprite(ptr->window, alex->ply_spr, NULL);
                alex->rect.left = 0;
            }
        }
        if (sfKeyboard_isKeyPressed(sfKeyDown)) {
            alex->rect.left = 225;
                sfSprite_setTextureRect(alex->ply_spr, alex->rect);
                sfRenderWindow_drawSprite(ptr->window, alex->ply_spr, NULL);
                alex->rect.left = 0;
        }
        jump_mode(alex);
        for (int i = 0; i < 10; i++)
            sfRenderWindow_drawSprite(ptr->window, grd->ground[i].plt_frm_spr, NULL);
        game_event(ptr, grd, alex, run2, chrono);
    }
    sfMusic_destroy(music);
    my_free(run, run2, grd, alex);
    destroy_windata(ptr);
}
