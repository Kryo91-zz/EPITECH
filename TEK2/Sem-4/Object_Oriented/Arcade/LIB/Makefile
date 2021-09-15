##
## EPITECH PROJECT, 2021
## B-OOP-400-MPL-4-1-arcade-corentin.petrau
## File description:
## Makefile
##

all:
	-mkdir ../lib
	make -C ./ncurse
	make -C ./SDL2
	make -C ./sfml
	make -C ./Menu

clean:
	make clean -C ./ncurse
	make clean -C ./SDL2
	make clean -C ./sfml
	make clean -C ./Menu

fclean: clean
	make fclean -C ./ncurse
	make fclean -C ./SDL2
	make fclean -C ./sfml
	make fclean -C ./Menu

re: fclean all