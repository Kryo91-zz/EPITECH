#!/bin/bash

./wolfram --rule 30 --lines 20 | cat -e > Comparaison_Alec/wolfram_rule30_lines20

./wolfram --rule 30 --lines 40 | cat -e > Comparaison_Alec/wolfram_rule30_lines40

./wolfram --rule 30 --lines 100 | cat -e > Comparaison_Alec/wolfram_rule30_lines100

./wolfram --rule 90 --lines 20 | cat -e > Comparaison_Alec/wolfram_rule90_lines20

./wolfram --rule 90 --lines 40 | cat -e > Comparaison_Alec/wolfram_rule90_lines40

./wolfram --rule 90 --lines 100 | cat -e > Comparaison_Alec/wolfram_rule90_lines100

./wolfram --rule 110 --lines 20 | cat -e > Comparaison_Alec/wolfram_rule110_lines20

./wolfram --rule 110 --lines 40 | cat -e > Comparaison_Alec/wolfram_rule110_lines40

./wolfram --rule 110 --lines 100 | cat -e > Comparaison_Alec/wolfram_rule110_lines100

./wolfram --rule 30 --lines 20 --move 20 | cat -e > Comparaison_Alec/wolfram_rule30_lines20_move20

./wolfram --rule 30 --lines 20 --move -20 | cat -e > Comparaison_Alec/wolfram_rule30_lines20_move_20

./wolfram --rule 90 --lines 20 --move 20 | cat -e > Comparaison_Alec/wolfram_rule90_lines20_move20

./wolfram --rule 110 --lines 20 --move 20 | cat -e > Comparaison_Alec/wolfram_rule110_lines20_move20

./wolfram --rule 30 --lines 20 --window 20 | cat -e > Comparaison_Alec/wolfram_rule30_lines20_window20

./wolfram --rule 90 --lines 20 --window 200 | cat -e > Comparaison_Alec/wolfram_rule90_lines20_window200

./wolfram --rule 110 --lines 20 --window 12 | cat -e > Comparaison_Alec/wolfram_rule110_lines20_window12

./wolfram --rule 90 --lines 45 --window 100 --move 25 | cat -e > Comparaison_Alec/wolfram_rule90_lines45_window100_move_25

./wolfram --rule 90 --lines 20 --start 25 | cat -e > Comparaison_Alec/wolfram_rule90_lines20_start25

./wolfram --rule 30 --lines 20 --start 25 | cat -e > Comparaison_Alec/wolfram_rule30_lines20_start25

./wolfram --rule 110 --lines 20 --start 25 | cat -e > Comparaison_Alec/wolfram_rule110_lines20_start25