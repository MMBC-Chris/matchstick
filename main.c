/*
** EPITECH PROJECT, 2019
** ms
** File description:
** main
*/

#include "my.h"
#include "matchstick.h"

int main(int ac, char **av)
{
    if (ac != 3)
        return 84;
    if (!my_str_isnum(av[1]) || !my_str_isnum(av[2]))
        return 84;
    return matchstick(my_getnbr(av[1]), my_getnbr(av[2]));
}
