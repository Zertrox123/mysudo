/*
** EPITECH PROJECT, 2025
** B-PSU-100-LYN-1-1-mysudo-alexis.drago-beltran
** File description:
** my_sudo
*/

#ifndef B_PSU_100_LYN_1_1_MYSUDO_ALEXIS_DRAGO_BELTRAN_MY_SUDO_H
    #define B_PSU_100_LYN_1_1_MYSUDO_ALEXIS_DRAGO_BELTRAN_MY_SUDO_H

int do_the_h(void);
int do_the_e(void);
int do_the_g(char *argv);
int do_the_s(void);
int do_the_u(void);
int basic_sudo(int ac, char **argv, char **ev);
int read_pswd(void);
int read_security(int argc, char **argv, char **ev);
void ask_psswd(void);

#endif //B_PSU_100_LYN_1_1_MYSUDO_ALEXIS_DRAGO_BELTRAN_MY_SUDO_H
