##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile for CPP-D07A
##

TESTS	=	tests/criterion.c \
			ex00/Skat.cpp \

OBJ_TESTS	= $(TESTS:.c=.o)

CFLAGS_TESTS	=	--coverage -lcriterion


unit_tests:	$(OBJ) $(OBJ_TESTS)
	$(CC) -o $@ $^ $(CFLAGS) -lcriterion --coverage -W -Wall -Wextra
	./$@

tests_run:	CFLAGS += $(CFLAGS_TESTS)

tests_run:	unit_tests

clean:
	rm -f $(OBJ_TESTS)
	rm -f *.gcno
	rm -f *.gcda
	rm -f ex/00*.gcno
	rm -f ex/00*.gcda
	rm -f *.o
	rm -f ex00/*.o
	rm -f tests/*.gcno
	rm -f tests/*.gcda

fclean:	clean
	rm -f unit_tests
	rm -f *.gcno
	rm -f *.gcda
	rm -f *.o
	rm -f tests/*.gcno
	rm -f tests/*.gcda
	rm -f tests/*.o
	rm -f ex00*.gcno
	rm -f ex00*.gcda
	rm -f ex00*.o

re:	fclean all
