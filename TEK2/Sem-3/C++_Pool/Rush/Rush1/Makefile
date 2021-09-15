##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile for rush1
##

TESTS	=	tests/criterion_int.c \
			tests/criterion_char.c \
			tests/criterion_float.c \
			tests/criterion_point.c \
			tests/criterion_vertex.c \
			int.c \
			new.c \
			char.c \
			float.c \
			point.c \
			vertex.c \

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

re:	fclean all
