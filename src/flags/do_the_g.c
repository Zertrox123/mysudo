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

static char **returning_argument_g(int argc, char **argv)
{
    char **argument = malloc(sizeof(char *) * (argc + 1));
    int a = 0;
    int b = 0;

    for (int i = 3; argv[i] != NULL; i++) {
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

int basic_sudo_g(int ac, char **argv, char **ev)
{
    struct stat s;
    char **tab;
    char **argument = returning_argument_g(ac, argv);
    int boole = 0;

    stat("/etc/shadow", &s);
    tab = shadow(s.st_size);
    if (verif_sudoers(first_info(tab[last_line(tab)])) == 1) {
        printf("sudo: unknown user %s", first_info(tab[last_line(tab)]));
        return 84;
    }
    setuid(0);
    setgid(0);
    printf("[sudo] password for %s: ", first_info(tab[last_line(tab)]));
    boole = read_security(ac, argv, ev);
    if (boole == 0) {
        execve(my_strcat(fill("/usr/bin/"), argument[0]), argument, NULL);
        return 0;
    } else
        return 84;
}

int do_the_g(char *arg, int argc, char **argv, char **ev)
{
    int llp = open("/etc/group", O_RDONLY);
    char *buffinou;
    char **tab;
    struct stat s;

    stat("/etc/group", &s);
    buffinou = malloc(sizeof(char) * (s.st_size + 1));
    read(llp, buffinou, s.st_size);
    tab = my_str_to_word_array(buffinou);
    for (int i = 0; tab[i] != NULL; i++) {
        if (my_strncmp(arg, tab[i], my_strlen(arg) - 1) == 0) {
            return basic_sudo_g(argc, argv, ev);
        }
    }
    return 84;
}
