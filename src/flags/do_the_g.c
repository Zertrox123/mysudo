/*
** EPITECH PROJECT, 2025
** B-PSU-100-LYN-1-1-mysudo-alexis.drago-beltran
** File description:
** do_the_g
*/

#include "my.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>

int do_the_g(char *argv)
{
    int llp = open("/etc/group", O_RDONLY);
    char *buffinou = malloc(sizeof(char)*1024);
    char **tab;
    struct stat s;

    stat("/etc/group", &s);
    read(llp, buffinou, s.st_size);
    tab = my_str_to_word_array(buffinou);
    for (int i = 0; tab[i] != NULL; i++) {
        if (my_strncmp(argv, tab[i], my_strlen(argv)) == 1) {
            return 0;
        } else {
            printf("Sudo: unknown group");
            return 84;
        }
    }
    return 0;
}
