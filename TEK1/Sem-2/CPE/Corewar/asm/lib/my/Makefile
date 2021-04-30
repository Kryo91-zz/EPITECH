##
## EPITECH PROJECT, 2019
## makefile #1
## File description:
## compile lib etc
##

SRC	=	*.c

OBJ	=	$(patsubst %.c, %.o, $(wildcard *.c))

NAME	=	test

TEST_SRC	=	../tests/test_factorial.c	\
				my_compute_factorial_rec.c	\
				../tests/test_power.c		\
				my_compute_power_rec.c		\
				../tests/test_sqrt.c		\
				my_compute_square_root.c	\
				../tests/test_prime.c		\
				my_is_prime.c				\
				my_find_prime_sup.c

TEST_NAME = unit-tests

TEST_FLAGS = --coverage -lcriterion

all:	$(NAME)

$(NAME):	$(OBJ)
		ar rc libmy.a $(OBJ)
		rm -f $(OBJ)
		rm -f $(NAME)
		mv libmy.a ../../
clean:
	rm -f $(OBJ)
	rm -f ../../libmy.a
	find -type f -name "*.gcno" -delete
	find -type f -name "*.gcda" -delete
	find -type f -name "unit-tests" -delete
fclean:	clean
	rm -f $(NAME)
re:	fclean all
test_run:
	gcc $(TEST_SRC) $(TEST_FLAGS) -o $(TEST_NAME)
	./unit-tests