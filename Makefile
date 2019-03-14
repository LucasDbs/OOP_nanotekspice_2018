##
## EPITECH PROJECT, 2019
## NanoTekSpice
## File description:
## Makefile
##

NAME	=	nanotekspice

SRC	=	main.cpp			\
		factory/componentFactory.cpp	\
		components/src/4081.cpp		\
		components/src/Input.cpp	\
		components/src/Output.cpp	\
		shell/src/ErrorManaging.cpp	\
		shell/src/Parser.cpp		\
		# components/src/4008.cpp	\
		# components/src/4011.cpp	\
		# components/src/4030.cpp	\
		# components/src/4071.cpp	\
		# components/src/4081.cpp	\

OBJ	=	$(SRC:.cpp=.o)

CFLAGS	=	-g -W -Wall -Wextra -std=c++11

all:		$(NAME)

$(NAME):
		g++ -o $(NAME) $(SRC) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
