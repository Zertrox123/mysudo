/*
** EPITECH PROJECT, 2025
** B-PSU-100-LYN-1-1-mysudo-alexis.drago-beltran
** File description:
** print_ask_pswd
*/

#include "my.h"
#include "my_sudo.h"

void ask_psswd(void)
{
    char *username = "";

    if (!username) {
        return;
    }
    mini_printf("[my_sudo] password for %s: ", username);
    return;
}
