##
## EPITECH PROJECT, 2019
## MUL_my_rpg_2019
## File description:
## Makefile
##

SRC =	create_button/retour_defeat.c \
		all_menu/menu_defeat.c \
		mob/pnj_talk.c \
		mob/pnj.c \
		mob/mob1.c \
		collider_button/collider_btn_option.c \
		draw_else/draw_title_option.c \
		draw_else/draw_btn_moins.c \
		draw_else/draw_btn_plus.c \
		essential_condition/loop_and_tools3.c \
		essential_condition/loop_and_tools2.c \
		HUD/draw_obj.c \
		HUD/draw_inventory2.c \
		HUD/draw_inventory.c \
		essential_condition/music_menu.c \
		mob/draw_demon.c \
		HUD/hud_sort_feu.c \
		HUD/hud_sort_foudre.c \
		HUD/hud_sort_epee.c \
		collider_button/collider_btn_sort.c \
		HUD/functional_inventory.c \
		create_button/btn_retour_menu_option.c \
		create_button/btn_sauvegarder_in_menu_pause.c \
		create_button/btn_option_in_menu_pause.c \
		create_button/btn_menu_prin_in_menu_pause.c \
		create_button/btn_quitter_in_menu_pause.c \
		collider_button/collider_btn_in_menu_pause.c \
		create_button/btn_reprendre_in_menu_pause.c \
		all_menu/menu_pause.c \
		create_button/draw_btn_pause.c \
		all_menu/menu_option.c \
		create_button/button_retour_menu_htp.c \
		collider_button/collider_btn_htp_option.c \
		all_menu/menu_comment_jouer.c \
		all_menu/main_menu.c \
		map/map1.c \
		essential_condition/loop_for_all_menu.c \
		collider_button/collider_btn_main_menu.c \
		create_button/button_charger_main_menu.c \
		create_button/button_aide_main_menu.c \
		create_button/button_option_main_menu.c \
		create_button/button_quit_main_menu.c \
		create_button/button_play_main_menu.c \
		draw_else/create_the_title.c \
		parralax/draw_tableau_parallax.c \
		parralax/move_parallax3.c \
		parralax/move_parallax2.c \
		parralax/move_parallax.c \
		parralax/draw_font_parallax2.c \
		parralax/draw_font_parallax.c \
		draw_else/draw_cursor.c \
		essential_condition/draw_all.c \
		essential_condition/destroy_all.c \
		essential_condition/open_window.c \
		essential_condition/loop_and_tools.c \
		essential_condition/doc_use.c \
		essential_condition/main.c \
		essential_condition/loop_xp_and_mana.c \
		mob/t.c \
		lib/usefull_func.c \
		mob/anim.c \
		mob/get_attack_pos.c \
		collision_map/get_coll.c \
		lib/my_str_to_word_array.c \
		lib/my_strlen.c \
		lib/my_getnbr.c \
		lib/get_distance.c \
		lib/my_put_nbr.c \
		particule/func.c \
		particule/func2.c \
		particule/func3.c \
		save/save.c \
		mob/demon_talk.c \
		mob/demon_talk2.c \

NAME =	my_rpg

OBJ = $(SRC:.c=.o)

CFLAGS  = -g3 -W -Wall -Wextra -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system -lm

all:	$(NAME)

$(NAME):	$(OBJ)
			gcc -o $(NAME) $(SRC) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: 	fclean all

.PHONY: all bin clean fclean re
