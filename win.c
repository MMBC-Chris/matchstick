/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** check who won
*/

#include "matchstick.h"

int check_win(int *board, int turn)
{
    int lost = 1;

    for (int i = 0; i < *board; i++)
        if (board[i + 2])
            lost = 0;
    if (lost)
        return turn ? 2 : 1;
    return 0;
}
