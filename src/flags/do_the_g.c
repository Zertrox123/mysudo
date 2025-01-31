/*
** EPITECH PROJECT, 2025
** B-PSU-100-LYN-1-1-mysudo-alexis.drago-beltran
** File description:
** do_the_g
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int do_the_g(void)
{
    int llp = open("/etc/group", O_RONDLY);
    char *buffinou = malloc(sizeof(char)*1024);
    char **tab;
    struct stat s;

    stat("/etc/group", s);
    read(llp, buffinou, s.st_size);
    return 0;
}
