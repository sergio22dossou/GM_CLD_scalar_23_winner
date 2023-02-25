/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** my functions
*/
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
//#include "window.h"
#include "player.h"
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include<SFML/Audio/Music.h>
#include<SFML/Audio/SoundBuffer.h>
#include<SFML/Audio/Sound.h>
#include<SFML/System.h>
#include "window.h"
#ifndef MY_H_
    #define MY_H_
void close_event(window *ptr);
int verif(char c);
int count_line(char *str);
int *count_cols(char *str);
char** maker(char *file);
void init_content(backgrd *run, backgrd *run2);
void init_ground(platform *grd, int x);
void init_player(player *alex);
void game_event(window *ptr);
#endif
