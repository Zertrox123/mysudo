/*
** EPITECH PROJECT, 2025
** B-PSU-100-LYN-1-1-mysudo-alexis.drago-beltran
** File description:
** do_the_g
*/

#include <stdio.h>
#include <unistd.h>

int do_the_g(void)
{
    gid_t gid = getgid();

    printf("Current Group ID: %d\n", gid);
    return 0;
}
