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
    sfSprite_setTexture(run->bgrd_spr, run->bgrd, true);
    sfSprite_setScale(run->bgrd_spr, (sfVector2f) {2, 2});
    run2->bgrd = sfTexture_createFromFile("ressources/Final/Background_1.png", NULL);
    run2->bgrd_spr = sfSprite_create();
    sfSprite_setTexture(run2->bgrd_spr, run2->bgrd, true);
    sfSprite_setScale(run2->bgrd_spr, (sfVector2f) {2, 2});
    run2->mv.x = 0;
    run2->mv.y = 0;
}

void init_ground(platform *grd, int x)
{
    grd->ground[x].plt_frm = sfTexture_createFromFile("ressources/Final/plat.png", NULL);
    grd->ground[x].plt_frm_spr = sfSprite_create();
    sfSprite_setTexture(grd->ground[x].plt_frm_spr, grd->ground[x].plt_frm, true);
    sfSprite_setScale(grd->ground[x].plt_frm_spr, (sfVector2f) {2, 2});
    grd->ground[x].mv.x = 184 * (x - 1);
    grd->ground[x].mv.y = 720;
    sfSprite_setPosition(grd->ground[x].plt_frm_spr, grd->ground[x].mv);  
}

void init_player(player *alex)
{
    alex->ply = sfTexture_createFromFile("ressources/alexio.png", NULL);
    alex->ply_spr = sfSprite_create();
    sfSprite_setTexture(alex->ply_spr, alex->ply, true);
    sfSprite_setPosition(alex->ply_spr, (sfVector2f) {0, 590});
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
        if (location.x < -249) {
            grd->ground[i].mv.x = 1400;
            sfSprite_setPosition(grd->ground[i].plt_frm_spr, grd->ground[i].mv);
        } else {
            grd->ground[i].mv.x -= 8;
            sfSprite_setPosition(grd->ground[i].plt_frm_spr, grd->ground[i].mv);
        }
    }
    run2->mv.x -= 8;
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
            grd->ground[i].mv.x += 8;
            sfSprite_setPosition(grd->ground[i].plt_frm_spr, grd->ground[i].mv);
        }
    }
    run2->mv.x += 8;
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

void game_event(window *ptr, platform *grd, player *alex, backgrd *run2, timer *chrono)
{
    while (sfRenderWindow_pollEvent(ptr->window,&ptr->event)) {
        if (ptr->event.type == sfEvtKeyPressed) {
            if (chrono->seconds > 0.1) {
                move_rect(&alex->rect, 135);
                sfSprite_setTextureRect(alex->ply_spr, alex->rect);
                sfClock_restart(chrono->clk);
            }
            if (ptr->event.key.code == sfKeyRight)
                draw_grd_r(ptr, grd, run2);
            if (ptr->event.key.code == sfKeyLeft)
                draw_grd_l(ptr, grd, run2);
        }
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
    chrono->clk = sfClock_create();
    init_player(alex);
    init_content(run, run2);
    for (int i = 0; i < 10; i++)
        init_ground(grd, i);
    while (sfRenderWindow_isOpen(ptr->window)) {
        chrono->time = sfClock_getElapsedTime(chrono->clk);
        chrono->seconds = chrono->time.microseconds / 100000;
        draw_backgrd(run, run2, alex, ptr);
        for (int i = 0; i < 10; i++)
            sfRenderWindow_drawSprite(ptr->window, grd->ground[i].plt_frm_spr, NULL);
        game_event(ptr, grd, alex, run2, chrono);
    }
    my_free(run, run2, grd, alex);
    destroy_windata(ptr);
}
