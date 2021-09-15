##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile for rush1
##

TESTS	=	tests/criterion_Object_Toy.cpp \
			tests/criterion_box_giftpaper.cpp \
			object/toy/Toy.cpp \
			object/toy/Teddy.cpp \
			object/toy/LittlePony.cpp \
			object/Object.cpp \
			object/wrap/Box.cpp \
			object/wrap/GiftPaper.cpp \
			object/wrap/Wrap.cpp \


OBJ_TESTS_CPP	= 	$(TESTS_CPP:.cpp=.o)

CFLAGS_TESTS	=	--coverage -lcriterion


unit_tests:	$(OBJ)
	g++ -o $@ $^ $(CFLAGS) $(TESTS) -W -Wall -Wextra
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
