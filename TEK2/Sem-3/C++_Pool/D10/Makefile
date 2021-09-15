##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile for rush1
##

TESTS	=	tests/criterion_ex00.cpp \
			ex00/Sorcerer.cpp \
			ex00/Peon.cpp \
			ex00/Victim.cpp \
			ex01/*.cpp \



OBJ_TESTS_CPP	= 	$(TESTS_CPP:.cpp=.o)

CFLAGS_TESTS	=	--coverage -lcriterion


unit_tests:	$(OBJ) $(TESTS)
	g++ -o $@ $^ $(CFLAGS) $(TESTS_CPP) -W -Wall -Wextra
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
