/*
** EPITECH PROJECT, 2025
** B-PSU-100-LYN-1-1-mysudo-alexis.drago-beltran
** File description:
** my_sudo
*/

#include "include/my.h"
#include "my_sudo.h"

int main(int argc, char *argv[], char **ev)
{
    for (int i = 1; i < argc; i++) {
        if (my_strcmp(argv[i], "-h") == 0) {
            return do_the_h();
        }
        if (my_strcmp(argv[i], "-u") == 0) {
            return do_the_u();
        }
        if (my_strcmp(argv[i], "-g") == 0) {
            return do_the_g(argv[i + 1]);
        }
        if (my_strcmp(argv[i], "-E") == 0) {
            return do_the_e();
        }
        if (my_strcmp(argv[i], "-s") == 0) {
            return do_the_s();
        }
    }
    return basic_sudo(argc, argv, ev);
}
