##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile for lib
##

NAME_HEADER	=	my.h

NAME_LIB	=	libmy.a

SRC	=	my_compute_power_rec.c  		\
		my_compute_square_root.c    		\
		my_find_prime_sup.c 			\
		my_getnbr.c 				\
		my_isneg.c  				\
		my_is_prime.c   			\
		my_putchar.c    			\
		my_put_nbr.c    			\
		my_putstr.c 				\
		my_revstr.c 				\
		my_showmem.c    			\
		my_showstr.c    			\
		my_sort_int_array.c 			\
		my_strcapitalize.c  			\
		my_strcat.c 				\
		my_strcmp.c 				\
		my_strcpy.c 				\
		my_str_isalpha.c    			\
		my_str_islower.c    			\
		my_str_isnum.c  			\
		my_str_isprintable.c    		\
		my_str_isupper.c    			\
		my_strlen.c 				\
		my_strlowcase.c 			\
		my_strncat.c    			\
		my_strncmp.c    			\
		my_strncpy.c    			\
		my_strstr.c 				\
		my_str_to_word_array.c  		\
		my_strupcase.c  			\
		my_swap.c

TESTS	=	../../Tests/test_all/test_all.c

OBJ_TESTS	=	$(SRC.c=.o) $(TESTS:.c=.o)

CFLAGS	=	-I../../include

CFLAGS_TESTS	=	--coverage -lcriterion

OBJ	=	$(SRC:.c=.o)

all:	header_copy compile lib_compile lib_copy

compile:	$(OBJ)

header_copy:
	cp $(NAME_HEADER) ../../include/

lib_compile:
	ar rc $(NAME_LIB) $(OBJ)

lib_copy:
	cp $(NAME_LIB) ../

unit_tests:	$(OBJ) $(OBJ_TESTS)
	$(CC) -o $@ $^ $(CFLAGS) -lcriterion
	./$@

tests_run:	CFLAGS += $(CFLAGS_TESTS)

tests_run:	unit_tests

clean:
	rm -f $(OBJ)
	rm -f libmy.a
	rm -f ../libmy.a
	rm -f *.gcno
	rm -f *.gcda
	rm -f ../../tests/*.o
	rm -f ../../tests/*.gcno
	rm -f ../../tests/*.gcda
	rm -f unit_tests

fclean:	clean
	$(RM) -f $(NAME)

re:	fclean all
