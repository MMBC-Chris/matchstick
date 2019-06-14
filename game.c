/*
** EPITECH PROJECT, 2019
** ms
** File description:
** game
*/

#include <stdlib.h>
#include <time.h>
#include "my.h"
#include "matchstick.h"

int is_num(char const *s)
{
    for (int i = 0; s[i] && s[i] != '\n'; i++)
        if (s[i] <= '0' || s[i] >= '9')
            return 0;
    return 1;
}

void print_win(int win)
{
    if (win == 1)
        my_printf("I lost... snif... but I'll get you next time!!\n");
    else
        my_printf("You lost, too bad...\n");
}

int make_turn(int *board, int turn)
{
    int line = 0;
    int ms = 0;

    if (turn) {
        my_putstr("AI's turn...\n");
        get_ai_inputs(board, &line, &ms);
        my_printf("AI removed %d match(es) from line %d\n", ms, line);
    } else {
        my_putstr("Your turn:\n");
        if (get_player_inputs(board, &line, &ms))
            return 1;
        my_printf("Player removed %d match(es) from line %d\n", ms, line);
    }
    board[line + 1] -= ms;
    return 0;
}

int game_loop(int *board)
{
    int win = 0;
    int turn = 0;

    while (!win) {
        print_board(board);
        win = check_win(board, turn);
        if (win) {
            print_win(win);
            continue;
        }
        my_putchar('\n');
        if (make_turn(board, turn++))
            return 0;
        turn %= 2;
    }
    return win;
}

int matchstick(int size, int max_ms)
{
    int *board = malloc(sizeof(int) * (size + 2));
    int win = 0;

    if (size < 2 || size > 99 || max_ms < 1)
        return 84;
    srandom(time(0));
    init_board(board, size, max_ms);
    win = game_loop(board);
    free(board);
    return win;
}
