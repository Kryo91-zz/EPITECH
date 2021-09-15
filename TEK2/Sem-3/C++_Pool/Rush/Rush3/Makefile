##
## EPITECH PROJECT, 2020
## B-CPP-300-MPL-3-1-CPPD03-alec.ferrari
## File description:
## Makefile
##

RM			=	rm -f
CC			=	g++
CPPFLAGS	=	-W -Wall -Wextra -Iinclude
LDFLAGS		=	-lcurses -lncurses -lsfml-window -lsfml-system -lsfml-graphics

SRC	=	src/main.cpp					\
		src/ncurses/main_ncurses.cpp	\
		src/SFML/init.cpp				\
		src/SFML/Line.cpp				\

LIB_SRC	=	lib/data/DiskData.cpp	\
			lib/data/ProcData.cpp	\
			lib/data/SysData.cpp	\
			lib/data/CPUData.cpp	\
			lib/data/MemoryData.cpp	\
			lib/data/NetData.cpp	\
			lib/one_sec_loop.cpp	\
			lib/string_exec.cpp		\

OBJ			=	$(SRC:.cpp=.o)

LIB_OBJ		=	$(LIB_SRC:.cpp=.o)

NAME	=	MyGKrellm

all:	$(NAME)

$(NAME):	$(OBJ)	$(LIB_OBJ)
		$(CC) $(CPPFLAGS) -o $(NAME) $(OBJ) $(LIB_OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)
	rm -f $(LIB_OBJ)
	find -type f -name "*.gcno" -delete
	find -type f -name "*.gcda" -delete

fclean:	clean
	rm -f $(NAME)

re:	fclean all