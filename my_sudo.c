/*
** EPITECH PROJECT, 2025
** B-PSU-100-LYN-1-1-mysudo-alexis.drago-beltran
** File description:
** my_sudo
*/

#include "my.h"
#include "my_sudo.h"

int main(int argc, char *argv[], int ac, char **av)
{
    for (int i = 1; i < argc; i++) {
        if (my_strcmp(argv[i], "-h") == 0) {
            do_the_h();
        }
        if (my_strcmp(argv[i], "-u") == 0) {
            do_the_u();
        }
        if (my_strcmp(argv[i], "-g") == 0) {
            do_the_g();
        }
        if (my_strcmp(argv[i], "-E") == 0) {
            do_the_e();
        }
        if (my_strcmp(argv[i], "-s") == 0) {
            do_the_s();
        } else {
            basic_sudo(ac, av);
        }
    }
    return 0;
}
