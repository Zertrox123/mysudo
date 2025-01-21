/*
** EPITECH PROJECT, 2025
** B-PSU-100-LYN-1-1-mysudo-alexis.drago-beltran
** File description:
** read_security
*/

#include <dirent.h>

#include <stdio.h>
#include <stdlib.h>

int read_security(void)
{
    FILE *file = fopen("/etc/sudoers", "r");

    if (file == NULL) {
        return 84;
    }
    fclose(file);
    return 0;
}
