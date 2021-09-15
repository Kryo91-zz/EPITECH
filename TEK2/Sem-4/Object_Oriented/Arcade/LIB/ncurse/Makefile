##
## EPITECH PROJECT, 2021
## B-OOP-400-MPL-4-1-arcade-corentin.petrau
## File description:
## Makefile
##

CXX 		= 	g++
RM 		= 	rm -f
NAME 	= 	arcade_ncurses.so

SRCS		= ncurse.cpp \
			../../inc/GameObject.cpp

OBJS 		= 	$(SRCS:.cpp=.o)

CPPFLAGS	+= -Iinc
CXXFLAGS 	+= 	-W -Wall -Wextra -fPIC -rdynamic -std=c++11 -I../../inc
LDFLAGS      	=	-shared -lncurses

all: $(NAME)

$(NAME): $(OBJS)
	 $(CXX) $(OBJS) -o ../../lib/$(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) ../../lib/$(NAME)

re: fclean all