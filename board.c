/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** board management
*/

#include "my.h"
#include "matchstick.h"

void init_board(int *board, int size, int max_ms)
{
    *board = size;
    board[1] = max_ms;
    for (int i = 0; i < size; i++)
        board[i + 2] = 2 * i + 1;
}

void print_board(int *board)
{
    for (int i = 0; i < 2 * *board + 1; i++)
        my_putchar('*');
    for (int i = 0; i < *board; i++) {
        my_putstr("\n*");
        for (int j = 0; j < *board - i - 1; j++)
            my_putchar(' ');
        for (int j = 0; j < 2 * i + 1; j++)
            my_putchar(j < board[i + 2] ? '|' : ' ');
        for (int j = 0; j < *board - i - 1; j++)
            my_putchar(' ');
        my_putchar('*');
    }
    my_putchar('\n');
    for (int i = 0; i < 2 * *board + 1; i++)
        my_putchar('*');
    my_putchar('\n');
}
