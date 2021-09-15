##
## EPITECH PROJECT, 2021
## B-OOP-400-MPL-4-1-arcade-corentin.petrau
## File description:
## Makefile
##

CC 		= 	g++
RM 		= 	rm -f
NAME 	= 	arcade_sdl2.so

SRCS		= sdl2.cpp \
			../../inc/GameObject.cpp

OBJS 		= 	$(SRCS:.cpp=.o)

CXXFLAGS 	+= 	-W -Wall -Wextra -fPIC -rdynamic -std=c++11 -I../../inc
LDFLAGS      	=	-shared -lSDL2 -lGL -lSDL2_image

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o ../../lib/$(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) ../../lib/$(NAME)

re: fclean all
