##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME = my_hunter

SRC = bird.c \
		display_windows_start_end.c \
		display2.c \
		error_draw_lvl.c \
		error_score_speed.c \
		event.c \
		game.c \
		hunter.c \
		load_draw_event.c \
		load_texture_etc.c \
		lvl1.c \
		lvl2.c \
		lvl3.c \
		manage.c \
		run_sprite_windows.c \
		used_func.c \

CFLAGS = -Wall -Wextra -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc $(SRC) $(CFLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
