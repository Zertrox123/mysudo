/*
** EPITECH PROJECT, 2025
** B-PSU-100-LYN-1-1-mysudo-alexis.drago-beltran
** File description:
** my_sudo
*/

#include "my.h"
#include "my_sudo.h"

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++) {
        if (my_strcmp(argv[i], "-h") == 0) {
            do_the_h();
            return 0;
        }
    }
    return 0;
}
