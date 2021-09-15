##
## EPITECH PROJECT, 2020
## B-OOP-400-MPL-4-1-arcade-corentin.petrau
## File description:
## Makefile
##

SRC		=	src/main.cpp \
			src/core.cpp \

CXXFLAGS	=	-I./ -I./core -I./libs -I./game -W -Wall -Wextra -g -std=c++11 -rdynamic -g3 -Iinc

LIBFLAGS	=	-ldl 

OBJ		=	$(SRC:.cpp=.o)

NAME		=	arcade

all: core
	make -C ./LIB
	make -C ./game

core: $(OBJ)
	g++ -o $(NAME) $(OBJ) $(LIBFLAGS)
	make -C ./LIB/Menu

graphicals:
	make -C ./LIB

games:
	make -C ./game

clean:
	make clean -C ./LIB
	make clean -C ./game
	rm -rf $(OBJ)

fclean: clean
	make fclean -C ./LIB
	make fclean -C ./game
	rm -rf $(NAME)
	rm -rf ./lib

re: fclean all