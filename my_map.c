/*
** EPITECH PROJECT, 2022
** step
** File description:
** step
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <ncurses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "player.h"
#include "window.h"

int my_cat(char *file)
{
    FILE *stream;
    char *line = NULL;
    size_t len = 0; ssize_t nread;  int x = 0;
    stream = fopen(file, "r");
    while ((nread = getline(&line, &len, stream)) != -1) {
        x++;
    }
    fclose(stream);
    free(line);
    return (x);
}
