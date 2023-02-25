/*
** EPITECH PROJECT, 2023
** window
** File description:
** window opening
*/
#include "window.h"
#include "my.h"
#include "monster.h"

void init_windata(window *ptr)
{
    ptr->mode.width = 1400;
    ptr->mode.height = 800;
    ptr->mode.bitsPerPixel = 32;
    ptr->name = "Journey in hell";
    ptr->window = sfRenderWindow_create(ptr->mode,ptr->name,sfDefaultStyle,NULL);
}

void destroy_windata(window *ptr)
{
    sfRenderWindow_destroy(ptr->window);
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
            grd->ground[i].mv.x -= 0.4;
            sfSprite_setPosition(grd->ground[i].plt_frm_spr, grd->ground[i].mv);
        }
    }
    run2->mv.x -= 0.4;
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
            grd->ground[i].mv.x = -186;
            sfSprite_setPosition(grd->ground[i].plt_frm_spr, grd->ground[i].mv);
        } else {
            grd->ground[i].mv.x += 0.4;
            sfSprite_setPosition(grd->ground[i].plt_frm_spr, grd->ground[i].mv);
        }
    }
    run2->mv.x += 0.4;
    sfSprite_setPosition(run2->bgrd_spr, run2->mv);
    if (run2->mv.x > 1800)
        run2->mv.x = -1694;
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left == max_value)
        rect->left = offset;
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
         if (alex->se > 0.7) {
             sfSprite_move(alex->ply_spr,(sfVector2f) {0,-50});
             alex->pos = sfSprite_getPosition(alex->ply_spr);
             sfClock_restart(alex->set);
         }
     }
     if (alex->pos.y < 400)
         alex->state = 2;
     if (alex->state == 2) {
         alex->jump = sfClock_getElapsedTime(alex->set);
         alex->se = alex->jump.microseconds / 100000;
         if (alex->se > 0.1) {
             sfSprite_move(alex->ply_spr,(sfVector2f) {0,50});
             alex->pos = sfSprite_getPosition(alex->ply_spr);
             sfClock_restart(alex->set);
         }
     }
     if (alex->pos.y > 580)
         alex->state = 0;
}

void player_move(window *ptr, platform *grd, player *alex, backgrd *run2, timer *chrono, enemy *pt)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue) {
        if (alex->pos.x > 300 && alex->pos.x < 810) {
            alex->pos.x -= 0.4;
            sfSprite_setPosition(alex->ply_spr, alex->pos);
        } else {
            draw_grd_l(ptr, grd, run2);
            move_monster_r(pt);
        } if (chrono->seconds > 0.1) {
            move_rect(&alex->rect, 0, 135);
            sfSprite_setTextureRect(alex->ply_spr, alex->rect);
            sfClock_restart(chrono->clk);
        }
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) {
        alex->pos = sfSprite_getPosition(alex->ply_spr);
        if (alex->pos.x > 290 && alex->pos.x < 800) {
            alex->pos.x += 0.4;
            sfSprite_setPosition(alex->ply_spr, alex->pos);
        } else {
            draw_grd_r(ptr, grd, run2);
            move_monster_l(pt);
        } if (chrono->seconds > 0.1) {
            move_rect(&alex->rect, 0, 135);
            sfSprite_setTextureRect(alex->ply_spr, alex->rect);
            sfClock_restart(chrono->clk);
        }
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue && alex->state == 0) {
        if (chrono->seconds > 0.1) {
            move_rect(&alex->rect, 0, 135);
            sfSprite_setTextureRect(alex->ply_spr, alex->rect);
            sfClock_restart(chrono->clk);
        }
        alex->state++;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown) == sfFalse && sfKeyboard_isKeyPressed(sfKeyRight) == sfFalse
        && sfKeyboard_isKeyPressed(sfKeyUp) == sfFalse && sfKeyboard_isKeyPressed(sfKeyLeft) == sfFalse) {
        if (alex->pos.y == 590) {
            alex->rect.left = 180;
            sfSprite_setTextureRect(alex->ply_spr, alex->rect);
                sfRenderWindow_drawSprite(ptr->window, alex->ply_spr, NULL);
                alex->rect.left = 0;
        }
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown) && sfKeyboard_isKeyPressed(sfKeyUp) == sfFalse && sfKeyboard_isKeyPressed(sfKeyRight) == sfFalse
        && sfKeyboard_isKeyPressed(sfKeyLeft) == sfFalse) {
        alex->rect.left = 225;
        sfSprite_setTextureRect(alex->ply_spr, alex->rect);
        sfRenderWindow_drawSprite(ptr->window, alex->ply_spr, NULL);
        alex->rect.left = 0;
    }
}

void windows(window *ptr, char *file, enemy *pt)
{
    init_windata(ptr);int count = 0;
    backgrd *run = (backgrd *)malloc(sizeof(backgrd));
    backgrd *run2 = (backgrd *)malloc(sizeof(backgrd));
    platform *grd = (platform *)malloc(sizeof(platform));
    player *alex = (player *)malloc(sizeof(player));
    timer *chrono = (timer *)malloc(sizeof(timer));
    timer *score = (timer *)malloc(sizeof(timer));
    pt->prim = (monst*)malloc(sizeof(monst) * 3);
    sfMusic *music = sfMusic_createFromFile("Shadow.ogg");
    sfMusic_play(music);
    chrono->clk = sfClock_create();
    score->clk = sfClock_create();
    init_player(alex);
    alex->state = 0;
    init_content(run, run2);
    browse_tab("level1", pt);
    init_monst_im(pt);
    for (int i = 0; i < 10; i++)
        init_ground(grd, i);
    while (sfRenderWindow_isOpen(ptr->window)) {
        chrono->time = sfClock_getElapsedTime(chrono->clk);
        score->time = sfClock_getElapsedTime(chrono->clk);
        chrono->seconds = chrono->time.microseconds / 100000;
        score->seconds = chrono->time.microseconds;
        if (score->seconds > 1000000) {
            count++; sfClock_restart(score->clk);
        }
        draw_monster(pt,ptr);
        draw_backgrd(run, run2, alex, ptr);
        game_event(ptr);
        jump_mode(alex);
        player_move(ptr,grd,alex,run2,chrono,pt);
        for (int i = 0;i < 3;i++) {
            sfRenderWindow_drawSprite(ptr->window,pt->prim[i].spr,NULL);
        }
        for (int i = 0; i < 10; i++)
            sfRenderWindow_drawSprite(ptr->window, grd->ground[i].plt_frm_spr, NULL);
    }
    destroy_monster(pt);
    free(pt->prim);
    sfMusic_destroy(music);
    my_free(run, run2, grd, alex);
    destroy_windata(ptr);
}
