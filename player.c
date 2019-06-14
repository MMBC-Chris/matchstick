/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** player move
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "matchstick.h"

int check_line(char *buf, int inp, int *board)
{
    int wrong = 0;

    if (!is_num(buf) || inp < 1) {
        wrong = 1;
        my_printf("Error: invalid input (positive number expected)\n");
    } else if (inp > *board) {
        wrong = 1;
        my_printf("Error: this line is out of range\n");
    }
    return wrong;
}

int ask_line(int *board)
{
    int wrong = 0;
    char *buf = NULL;
    long unsigned int n = 0;
    int inp = 0;

    do {
        wrong = 0;
        my_printf("Line: ");
        if (getline(&buf, &n, stdin) == -1)
            return 0;
        if (n == 0)
            return 0;
        inp = my_getnbr(buf);
        wrong = check_line(buf, inp, board);
    } while (wrong);
    free(buf);
    return inp;
}

int check_matches(int inp, int *board, int line)
{
    if (inp > board[line + 1]) {
        my_printf("Error: not enough matches on this line\n");
        return -1;
    }
    if (inp > board[1]) {
        my_printf("Error: you cannot remove more ");
        my_printf("than %d matches per turn\n", board[1]);
        return -1;
    }
    return inp;
}

int ask_matches(int *board, int line)
{
    char *buf = NULL;
    long unsigned int n = 0;
    int inp = 0;

    my_printf("Matches: ");
    if (getline(&buf, &n, stdin) == -1)
        return 0;
    if (n == 0)
        return 0;
    inp = my_getnbr(buf);
    if (!is_num(buf) || inp < 1) {
        my_printf("Error: invalid input (positive number expected)\n");
        return -1;
    }
    if (!inp) {
        my_printf("Error: you have to remove at least one match\n");
        return -1;
    }
    return check_matches(inp, board, line);
}

int get_player_inputs(int *board, int *line, int *matches)
{
    int wrong = 0;

    do {
        wrong = 0;
        *line = ask_line(board);
        if (*line == 0)
            return 1;
        *matches = ask_matches(board, *line);
        if (*matches < 0)
            wrong = 1;
        else if (*matches == 0)
            return 1;
    } while (wrong);
    return 0;
}
