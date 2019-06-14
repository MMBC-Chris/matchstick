/*
** EPITECH PROJECT, 2019
** ms
** File description:
** main header
*/

#ifndef _MATCHSTICK_H_
#define _MATCHSTICK_H_

int matchstick(int, int);

int check_win(int *, int);

void init_board(int *, int, int);
void print_board(int *);

int is_num(char const *);

void get_ai_inputs(int *, int *, int *);
int get_player_inputs(int *, int *, int *);

#endif
