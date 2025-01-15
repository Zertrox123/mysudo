/*
** EPITECH PROJECT, 2025
** B-PSU-100-LYN-1-1-mysudo-alexis.drago-beltran
** File description:
** my_sudo
*/

#include "my.h"
#include "my_sudo.h"

static int do_the_h_flag(void)
{
    do_the_h();
    return 0;
}

static int do_the_u_flag(void)
{
    do_the_u();
    return 0;
}

static int do_the_g_flag(void)
{
    do_the_g();
    return 0;
}

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++) {
        if (my_strcmp(argv[i], "-h") == 0) {
            do_the_h_flag();
        }
        if (my_strcmp(argv[i], "-u") == 0) {
            do_the_u_flag();
        }
        if (my_strcmp(argv[i], "-g") == 0) {
            do_the_g_flag();
        }
        if (my_strcmp(argv[i], "-E") == 0) {
            do_the_e();
            return 0;
        }
        if (my_strcmp(argv[i], "-s") == 0) {
            do_the_s();
            return 0;
        }
    }
    return 0;
}
