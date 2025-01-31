/*
** EPITECH PROJECT, 2024
** omar
** File description:
** my_str_to_word_array.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int count_word(char const *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ')
            count++;
    }
    return count + 1;
}

int actual_word(char const *str, int i)
{
    int a = 0;

    while (str[i] != '\0' && str[i] != '\t' && str[i] != ' ') {
        a++;
        i++;
    }
    return a;
}

char **my_str_to_word_array(char const *str)
{
    char **tab = malloc(sizeof(char *) * count_word(str));
    int a = 0;
    int j = 0;
    int actual_w;

    for (int i = 0; i != count_word(str); i++) {
        actual_w = actual_word(str, a);
        tab[i] = malloc(sizeof(char) * actual_w);
        for (; j < actual_w; j++) {
            tab[i][j] = str[a];
            a++;
        }
        a++;
        tab[i][j] = '\0';
        j = 0;
    }
    tab[count_word(str)] = NULL;
    return tab;
}
