/*
** EPITECH PROJECT, 2025
** B-PSU-100-LYN-1-1-mysudo-alexis.drago-beltran
** File description:
** read_security
*/

#include "../../include/my.h"
#include <sys/stat.h>
#include "my_sudo.h"
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <crypt.h>

char *fill(char *things)
{
    char *final = malloc(my_strlen(things));
    int i = 0;

    for (; things[i] != '\0'; i++) {
        final[i] = things[i];
    }
    return final;
}

char *second_info(char *tab)
{
    char *st = malloc(sizeof(char) * 1000);
    int i = 0;
    int a = 0;

    for (; tab[i] != ':'; i++);
    i++;
    for (; tab[i] != ':'; i++) {
        st[a] = tab[i];
        a++;
    }
    st[a] = '\0';
    return st;
}

char *getpasss(int argc, char **argv)
{
    char *str = NULL;
    char *real;
    int i = 0;
    size_t reading;
    ssize_t input;

    input = getline(&str, &reading, stdin);
    if (input == -1)
        return "";
    real = malloc(sizeof(char) * my_strlen(str));
    for (; i != my_strlen(str) - 1; i++)
        real[i] = str[i];
    real[i] = '\0';
    return real;
}

int read_security(int argc, char **argv, char **ev)
{
    static int essai = 0;
    char *passwd_typing = getpasss(argc, argv);
    struct stat s;
    char **tab;
    char *hash;

    stat("/etc/shadow", &s);
    tab = shadow(s.st_size);
    hash = crypt(passwd_typing, second_info(tab[last_line(tab)]));
    if (my_strcmp(hash, second_info(tab[last_line(tab)])) == 0)
        return 0;
    else if (essai != 2) {
        essai++;
        my_putstr("\nSorry, try again.\n");
        basic_sudo(argc, argv, ev);
    } else {
        my_putstr("sudo: 3 incorrect password attempts\n");
        return 1;
    }
}
