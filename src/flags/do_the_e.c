/*
** EPITECH PROJECT, 2025
** B-PSU-100-LYN-1-1-mysudo-alexis.drago-beltran
** File description:
** do_the_e
*/

#include <stdio.h>
#include "my.h"

int do_the_e(void)
{
    extern char **environ;

    for (char **env = environ; *env != 0; env++) {
        printf("%s\n", *env);
    }
    return 0;
}
