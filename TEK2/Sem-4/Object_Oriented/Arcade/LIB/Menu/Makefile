##
## EPITECH PROJECT, 2021
## B-OOP-400-MPL-4-1-arcade-corentin.petrau
## File description:
## Makefile
##

CC 		= 	g++
RM 		= 	rm -f
NAME 	= 	arcade_menu.so

SRCS		= Menu.cpp

OBJS 		= 	$(SRCS:.cpp=.o)

CXXFLAGS 	+= 	-W -Wall -Wextra -fPIC -rdynamic -std=c++11 -I../../inc
LDFLAGS      	=	-shared -lncurses

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o ../../$(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) ../../$(NAME)

re: fclean all