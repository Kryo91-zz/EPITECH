##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile for rush1
##

TESTS	=	tests/criterion_ex00.c \
			tests/criterion_ex01.cpp \
			tests/criterion_ex02.cpp \
			tests/criterion_ex03.cpp \
			tests/criterion_ex04.cpp \
			tests/criterion_ex05.cpp \
			ex00.c \
			Character.cpp \
			Warrior.cpp \
			Mage.cpp \
			Priest.cpp \
			Paladin.cpp \
			Hunter.cpp \



OBJ_TESTS	= $(TESTS:.c=.o)

OBJ_TESTS_CPP	= 	$(TESTS_CPP:.cpp=.o)

CFLAGS_TESTS	=	--coverage -lcriterion


unit_tests:	$(OBJ) $(OBJ_TESTS)
	g++ -o $@ $^ $(CFLAGS) $(TESTS_CPP) -lcriterion --coverage -W -Wall -Wextra
	./$@

tests_run:	CFLAGS += $(CFLAGS_TESTS)

tests_run:	unit_tests

clean:
	rm -f *.o
	rm -f tests/*.o
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
