##
## EPITECH PROJECT, 2019
## NanoTekSpice
## File description:
## Makefile
##

CC	=	g++ -std=c++11

SRC	=	main.cpp			\
		shell/src/Shell.cpp		\
		components/src/Gates.cpp			\
		shell/src/Parsing.cpp			\
		components/src/Pins.cpp			\
		components/src/PinComponent.cpp		\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	#-Wall -Wextra 

LDFLAGS	=	-g

INCLUDE	=	-Iinclude

NAME	=	nanotekspice

RM	=	rm -rf

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(INCLUDE) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

fclean:
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all re clean fclean
