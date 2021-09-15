##
## EPITECH PROJECT, 2020
## B-FUN-300-MPL-3-1-funPoolDay2-corentin.petrau
## File description:
## Makefile
##


RM	=	rm -f
CC	=	ghc

SRC	=	check.hs	\

TEST_SRC	=	tests/Unit_tests.hs	\


OBJ	=	$(SRC:.hs=.o)

NAME	=	wolfram

all:	$(NAME)

$(NAME):
	stack build 
	cp `stack path --local-install-root`/bin/Wolfram-exe ./
	mv Wolfram-exe $(NAME)

clean:
	rm	-f	$(OBJ)
	rm	-f	app/*.hi
	rm	-f	app/*.o
	rm -f tests/*.o
	rm -f tests/*.hi

fclean:	clean
	rm	-f	$(NAME)
	rm -f unit_tests

tests_run:
	$(CC) -o unit_tests $(TEST_SRC)
	./unit_tests

re:	fclean all