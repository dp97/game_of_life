# Compile gol (game of life).

NAME	= gol

CC		= -gcc
CFAGS	= -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: gol.c
	$(CC) $(CFLAGS) gol.c -o $(NAME)

clean:
	@rm -f gol.o

fclean: clean
	@rm -f gol

re: fclean all
