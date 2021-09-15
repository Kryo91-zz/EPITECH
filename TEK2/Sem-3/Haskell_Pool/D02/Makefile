##
## EPITECH PROJECT, 2020
## B-FUN-300-MPL-3-1-funPoolDay2-corentin.petrau
## File description:
## Makefile
##


RM	=	rm -f
CC	=	ghc

SRC	=	DoOp.hs	\


OBJ	=	$(SRC:.hs=.o)

NAME	=	doop

all:	$(NAME)

$(NAME):
	$(CC) -o $(NAME) $(SRC)

clean:
	rm	-f	$(OBJ)
	rm	-f	*.hi

fclean:	clean
	rm	-f	$(NAME)

re:	fclean all