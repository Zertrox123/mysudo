/*
** EPITECH PROJECT, 2025
** B-PSU-100-LYN-1-1-mysudo-alexis.drago-beltran
** File description:
** hash_password
*/

#include <shadow.h>
#include <crypt.h>
#include <stdio.h>

static int_incorrect_pswd(void)
{
    int incorrect_counter = 0;

    for (/*on sais que password incorrect, faut juste savoir si timeout*/) {
        if (/*password incorrect*/) {
            printf("Incorrect password.\n");
            incorrect_counter + 1;
            return incorrect_counter;
        }
        if (incorrect_counter >= 3) {
            printf("Fuck off, looser");
            return 84;
        }
    }
    return 0;
}

int hash_password(void)
{
    /*on test le password*/
    /*si bon on continue*/

    if () {
        int_incorrect_pswd(); /*si il est mauvais on lance ce qui gere les mauvais mdp*/
    }
    return 0;
}
