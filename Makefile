##
## EPITECH PROJECT, 2019
## NanoTekSpice
## File description:
## Makefile
##

CC	=	g++

SRC	=

OBJ	=	$(SRC:.c=.o)

CPPFLAGS	=	-Wall -Wextra

RM	=	rm -rf

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS)

clean:
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(OBJ)

re:		fclean all

.PHONY:	all re clean fclean
