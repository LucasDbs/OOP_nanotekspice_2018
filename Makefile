##
## EPITECH PROJECT, 2019
## NanoTekSpice
## File description:
## Makefile
##

NAME	=	nanotekspice

SRC	=	main.cpp		\

OBJ	=	$(SRC:.cpp=.o)

CFLAGS	=	-g -W -Wall -Wextra

all:		$(NAME)

$(NAME):
		g++ -o $(NAME) $(SRC) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all