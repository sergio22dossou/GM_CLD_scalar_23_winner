/*
** EPITECH PROJECT, 2023
** init monst
** File description:
** init monster
*/
#include "monster.h"

void init_struct(enemy *ptr, int x, int a, char **arr)
{
    ptr->prim[a].c = arr[x][0];x++;
    ptr->prim[a].pos.x = atoi(arr[x]);x++;
    ptr->prim[a].pos.y = atoi(arr[x]);x++;
    ptr->prim[a].velocity = (float)atoi(arr[x]);x++;
    ptr->prim[a].charges = atoi(arr[x]);x++;
}

void browse_tab(char *file, enemy *ptr)
{
   int a = 0;
    char **arr = maker(file);
   for (int i = 0;arr[i + 1] != NULL;i++) {
       if (arr[i][0] == 'M') {
           init_struct(ptr,i,a,arr);
           a++;
       }
   }
    for (int i = 0;arr[i + 1] != NULL;i++)
        free(arr[i]);
    free(arr);
}
