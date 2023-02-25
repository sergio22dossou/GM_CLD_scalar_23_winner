/*
** EPITECH PROJECT, 2023
** monster
** File description:
** monster read info
*/
#include "my.h"

char* read_file(char *filepath)
{
    struct stat b;
    char *str;
    stat(filepath, &b);
    int fd = open(filepath, O_RDONLY);
    str = (char*)malloc(sizeof(char) * b.st_size);
    read(fd, str, b.st_size);
    close(fd);
    return str;
}

char** alloc_tab(char *str)
{
    int y = count_line(str);int *tab = count_cols(str);
    char **arr = (char**)malloc(sizeof(char*) * (y + 1));
    for (int i = 0;i < y;i++)
        arr[i] = (char*)malloc(sizeof(char) * tab[i]);
    free(tab);
    return arr;
}

char** init_tab(char *str, char **arr)
{
    int a = 0,b = 0;
    for (int i = 0;str[i] != '\0';i++) {
        if (verif(str[i]) == 1) {
            arr[b][a] = str[i];
            a++;
        } else {
            b++;a = 0;
        }
    }
    return arr;
}

char** maker(char *file)
{
    char *str = read_file(file);
    char **arr = alloc_tab(str);
    arr = init_tab(str,arr);
    free(str);
    return arr;
}

/* int main(int ac, char **av) */
/* { */
/* /\*     char *str = read_file(av[1]); *\/ */
/* /\*     int y = count_line(str); *\/ */
/* /\*     int *tab = count_cols(str); *\/ */
/* /\*     for (int i = 0;i < y;i++) *\/ */
/* /\*         printf("%d\n",tab[i]); *\/ */
/* /\*     free(str);free(tab); *\/ */
/*     char **arr = maker(av[1]); */
/*     for (int i = 0;arr[i] != NULL;i++) { */
/*         printf("%s\n",arr[i]); */
/*         free(arr[i]); */
/*     } */
/*     free(arr); */
/*     return 0; */
/* } */
