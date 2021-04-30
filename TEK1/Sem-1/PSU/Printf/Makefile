##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile for lib
##


NAME_HEADER	=	my.h

NAME_LIB	=	libmy.a

SRC	=	lib/my_compute_power_rec.c  		\
		lib/my_compute_square_root.c		\
		lib/my_find_prime_sup.c 			\
		lib/my_getnbr.c 				\
		lib/my_isneg.c  				\
		lib/my_is_prime.c   			\
		lib/my_putchar.c    			\
		lib/my_put_nbr.c    			\
		lib/my_putstr.c 				\
		lib/my_revstr.c 				\
		lib/my_showmem.c    			\
		lib/my_showstr.c    			\
		lib/my_sort_int_array.c 			\
		lib/my_strcapitalize.c  			\
		lib/my_strcat.c 				\
		lib/my_strcmp.c 				\
		lib/my_strcpy.c 				\
		lib/my_str_isalpha.c			\
		lib/my_str_islower.c			\
		lib/my_str_isnum.c			\
		lib/my_str_isprintable.c			\
		lib/my_str_isupper.c				\
		lib/my_strlen.c 				\
		lib/my_strlowcase.c 			\
		lib/my_strncat.c    			\
		lib/my_strncmp.c    			\
		lib/my_strncpy.c    			\
		lib/my_strstr.c 				\
		lib/my_strupcase.c  			\
		lib/my_swap.c					\
		lib/my_str_to_word_array.c		\
		lib/redirec.c					\
		lib/my_printf.c						\
		lib/func_use.c					\
		lib/my_strlen_perc.c			\
		lib/func_use2.c					\
		lib/my_put_nbr_base.c			\
		lib/func_use3.c					\
		lib/my_put_unsi_nbr.c			\

TESTS	=	./tests_crit/test_all/test_all.c	\
			./tests_crit/test_all/1.c	\
			./tests_crit/test_all/2.c	\
			./tests_crit/test_all/3.c	\
			./tests_crit/test_all/4.c	\
			./tests_crit/test_all/5.c	\
			./tests_crit/test_all/6.c	\
			./tests_crit/test_all/8.c	\
			./tests_crit/test_all/9.c	\
			./tests_crit/test_all/10.c	\
			./tests_crit/test_all/11.c	\
			./tests_crit/test_all/12.c	\
			./tests_crit/test_all/13.c	\
			./tests_crit/test_all/14.c	\
			./tests_crit/test_all/15.c	\
			./tests_crit/test_all/16.c	\
			./tests_crit/test_all/17.c	\
			./tests_crit/test_all/18.c	\
			./tests_crit/test_all/19.c	\
			./tests_crit/test_all/20.c	\
			./tests_crit/test_all/21.c	\
			./tests_crit/test_all/22.c	\
			./tests_crit/test_all/23.c	\
			./tests_crit/test_all/24.c	\
			./tests_crit/test_all/25.c	\
			./tests_crit/test_all/26.c	\
			./tests_crit/test_all/27.c	\
			./tests_crit/test_all/28.c	\
			./tests_crit/test_all/29.c	\
			./tests_crit/test_all/30.c	\
			./tests_crit/test_all/31.c	\
			./tests_crit/test_all/32.c	\
			./tests_crit/test_all/33.c	\
			./tests_crit/test_all/34.c	\
			./tests_crit/test_all/35.c	\
			./tests_crit/test_all/36.c	\
			./tests_crit/test_all/37.c	\
			./tests_crit/test_all/38.c	\

OBJ_TESTS	=	$(SRC.c=.o) $(TESTS:.c=.o)

CFLAGS	=

CFLAGS_TESTS	=	--coverage -lcriterion

OBJ	=	$(SRC:.c=.o)

all:	compile lib_compile

compile:	$(OBJ)

lib_compile:
	ar rc $(NAME_LIB) $(OBJ)


unit_tests:	$(OBJ) $(OBJ_TESTS)
	$(CC) -o $@ $^ $(CFLAGS) -lcriterion --coverage -W -Wall -Wextra
	./$@

tests_run:	CFLAGS += $(CFLAGS_TESTS)

tests_run:	unit_tests

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f libmy.a
	$(RM) -f $(NAME)
	rm -f lib/*.gcno
	rm -f lib/*.gcda
	rm -f tests_crit/test_all/*.gcno
	rm -f tests_crit/test_all/*.gcda
	rm -f tests_crit/test_all/*.o
	rm -f unit_tests

re:	fclean all
