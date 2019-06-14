/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** ai move
*/

#include <stdlib.h>
#include "matchstick.h"

void get_ai_inputs(int *board, int *line, int *matches)
{
    int max;

    do {
        *line = random() % *board;
    } while (!board[*line + 2]);
    max = board[1] > board[*line + 2] ? board[*line + 2] : board[1];
    *matches = random() % max + 1;
    *line += 1;
}
