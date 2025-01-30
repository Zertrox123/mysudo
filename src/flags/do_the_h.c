/*
** EPITECH PROJECT, 2025
** B-PSU-100-LYN-1-1-mysudo-alexis.drago-beltran
** File description:
** do_the_h
*/

#include <unistd.h>
#include "my.h"

int do_the_h(void)
{
    my_putstr("Usage : ./my_sudo");
    my_putstr(" -h\n");
    my_putstr("Usage : ./my_sudo");
    my_putstr(" [-ugEs]");
    my_putstr("[Command [args ...]]\n");
    return 0;
}
