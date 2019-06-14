##
## EPITECH PROJECT, 2019
## matchstick
## File description:
## makefile
##

SRC	=	ai.c \
		win.c \
		main.c \
		game.c \
		board.c \
		player.c
OBJ	=	$(SRC:.c=.o)
LIB	=	lib/libmy.a
NAME	=	matchstick
CFLAGS	=	-Iinclude -W -Wall -Wextra -std=c11 -D _DEFAULT_SOURCE
LDFLAGS	=	-Llib -lmy

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	gcc -o $@ $(OBJ) $(LDFLAGS)

$(LIB):
	make -C lib/my

clean:
	rm -f $(OBJ)
	make -C lib/my clean

fclean: clean
	rm -f $(NAME)
	make -C lib/my fclean

re: fclean all
