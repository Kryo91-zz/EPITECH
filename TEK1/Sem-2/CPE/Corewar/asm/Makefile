##
## EPITECH PROJECT, 2020
## Corewar: asm
## File description:
## Compile everything
##

CC			=	gcc
RM			=	rm -f
CFLAGS		=	-W -Wall -Wextra -Iinclude -g3
LDFLAGS		=	-L./ -lmy

SRC		=	src/main.c					\
			src/help.c					\
			src/main_compiler.c			\
			src/check_instruction.c		\
			src/check_labels.c			\
			src/check_params.c			\
			src/check_types.c			\
			src/get_filename.c			\
			src/get_name_and_comment.c	\
			src/op.c					\
			src/write_binary.c			\
			src/write_into_new_file.c	\
			src/write_instruction.c		\
			src/labels_list.c			\

SRC_NO_MAIN =	src/help.c					\
				src/main_compiler.c			\
				src/check_instruction.c		\
				src/check_labels.c			\
				src/check_params.c			\
				src/check_types.c			\
				src/get_filename.c			\
				src/get_name_and_comment.c	\
				src/op.c					\
				src/write_binary.c			\
				src/write_into_new_file.c	\
				src/write_instruction.c		\
				src/labels_list.c			\

SRC_TEST =	tests/check_instruction_test.c		\
			tests/check_labels_test.c			\
			tests/check_params_test.c			\
			tests/check_types_test.c			\
			tests/get_filename_test.c			\
			tests/get_name_and_comment_test.c	\
			tests/help_test.c					\
			tests/labels_list_test.c			\

OBJ		=	$(SRC:.c=.o)

TEST_NAME	=	unit_tests

TEST_FLAG = -lcriterion --coverage

NAME	=	asm

all:	$(NAME)

re:	fclean all

$(NAME): $(OBJ)
	make -C ./lib/my > /dev/null
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	$(RM) $(OBJ)
	$(RM) *~
	$(RM) $(TEST_OBJ)
	$(RM) *.gcno
	$(RM) *.gcda
	$(RM) unit_tests
	$(RM) libmy.a
	$(RM) *.cor

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(TEST_NAME)

tests_run:	$(TEST_NAME)

$(TEST_NAME):	$(SRC_TEST) $(SRC)
				make -C ./lib/my > /dev/null
				gcc -Iinclude $(TEST_FLAG) $(SRC_NO_MAIN) $(SRC_TEST) -o $(TEST_NAME) $(LDFLAGS)
				./unit_tests
				gcovr --exclude tests
				gcovr --exclude tests -b
