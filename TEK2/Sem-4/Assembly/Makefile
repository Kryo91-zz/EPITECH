##
## EPITECH PROJECT, 2020
## B-ASM-400-MPL-4-1-asmminilibc-corentin.petrau
## File description:
## Makefile
##

ASM = nasm

CC = gcc

RM = rm -f

ASFLAGS = -f elf64

CRFLAG = -lcriterion --coverage -ldl

NAME = libasm.so

NAME_TEST = tests_run

SRCS =	src/strlen.asm \
		src/strchr.asm \
		src/memset.asm \
		src/memcpy.asm \
		src/strcmp.asm \
		src/strncmp.asm \
		src/memmove.asm \
		src/strcasecmp.asm \
		src/rindex.asm \
		src/strstr.asm \
		src/strpbrk.asm \
		src/strcspn.asm \

SRC_TEST = tests/criterion_strlen_asm.c \
			tests/criterion_strchr_asm.c \
			tests/criterion_memset_asm.c \

OBJS =	$(SRCS:.asm=.o)

OBJS_TESTS = $(SRC_TEST:.c=.o)

T_OBJS =	$(T_SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
		$(CC) -nostdlib -shared -fPIC $(OBJS) -o $(NAME)

%.o : %.asm
	$(ASM) $(ASFLAGS) -o $@ $<

tests_run : re
	$(CC) -o $(NAME_TEST) tests/*.c $(CRFLAG)
	./$(NAME_TEST)


clean:
	$(RM) src/*.o

fclean:	clean
	$(RM) src/*.o
	$(RM) libasm.so
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) tests_run

re:	fclean all