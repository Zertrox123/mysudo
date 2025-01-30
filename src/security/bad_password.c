/*
** EPITECH PROJECT, 2025
** B-PSU-100-LYN-1-1-mysudo-alexis.drago-beltran
** File description:
** bad_password
*/

#include <shadow.h>
#include <crypt.h>
#include <stdio.h>

int incorrect_pswd(void)
{
    int i = 0;

    while (i < 3) {
        printf("Incorrect password.\n");
        i++;
    }
    if (i == 3) {
        printf("Incorrect password, too many attempts.\n");
        return 84;
    }
    return 0;
}
