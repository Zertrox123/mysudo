/*
** EPITECH PROJECT, 2025
** B-PSU-100-LYN-1-1-mysudo-alexis.drago-beltran
** File description:
** read_security
*/

#include <dirent.h>

int read_security(void)
{
    readdir(/etc/sudoers);
    opendir(/etc/sudoers);

}
