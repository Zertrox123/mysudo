/*
** EPITECH PROJECT, 2025
** B-PSU-100-LYN-1-1-mysudo-alexis.drago-beltran
** File description:
** basic_sudo
*/

#include "../include/my.h"
#include "my_sudo.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>

static int get_long(char *buffer, int i)
{
    int p = i;
    int acc = 0;

    for (; buffer[p] != '\n' && buffer[p] != '\0'; p++)
        acc++;
    return acc;
}

static char **setup_tab(char *buffer, char **tab, long int sizer)
{
    int x = 0;
    int y = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        tab[x] = malloc(sizeof(char) * (get_long(buffer, i) + 1));
        for (; buffer[i] != '\n' && buffer[i] != '\0'; i++) {
            tab[x][y] = buffer[i];
            y++;
        }
        tab[x][y] = '\0';
        x++;
        y = 0;
    }
    tab[x] = NULL;
    return tab;
}

char **shadow(long size)
{
    int fd = open("/etc/shadow", O_RDONLY);
    char *buffer = malloc(sizeof(char) * (size + 1));
    struct stat s;
    char **tab;

    stat("/etc/shadow", &s);
    read(fd, buffer, size);
    tab = malloc(sizeof(char *) * (size + 1));
    tab = setup_tab(buffer, tab, size);
    close(fd);
    return tab;
}

int last_line(char **tab)
{
    int i = 0;

    for (; tab[i] != NULL; i++);
    return i - 1;
}

static char *first_info(char *tab)
{
    char *st = malloc(sizeof(char) * 100);
    int i = 0;

    for (; tab[i] != ':'; i++)
        st[i] = tab[i];
    st[i] = '\0';
    return st;
}

static char **returning_argument(int argc, char **argv)
{
    char **argument = malloc(sizeof(char *) * (argc + 1));
    int a = 0;
    int b = 0;

    for (int i = 1; argv[i] != NULL; i++) {
        argument[a] = malloc(sizeof(char) * (my_strlen(argv[i]) + 1));
        for (int j = 0; argv[i][j] != '\0'; j++) {
            argument[a][b] = argv[i][j];
            b++;
        }
        argument[a][b] = '\0';
        a++;
        b = 0;
    }
    argument[a] = NULL;
    return argument;
}

int basic_sudo(int ac, char **argv, char **ev)
{
    struct stat s;
    char **tab;
    char **argument = returning_argument(ac, argv);
    int boole = 0;

    stat("/etc/shadow", &s);
    tab = shadow(s.st_size);
    my_putstr("[sudo] password for ");
    my_putstr(first_info(tab[last_line(tab)]));
    my_putstr(": ");
    boole = read_security(ac, argv, ev);
    if (boole == 0) {
        execve(my_strcat(fill("/usr/bin/"), argument[0]), argument, NULL);
        return 0;
    } else
        return 84;
}
