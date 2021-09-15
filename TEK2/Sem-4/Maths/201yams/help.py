#!/usr/bin/env python3

##
## EPITECH PROJECT, 2019
## 107TRANSFER_2019
## File description:
## 107transfer
##

from __future__ import print_function
from fractions import Fraction
from sys import argv, exit
from math import pow

lishelp = "USAGE\n\
    ./201yams d1 d2 d3 d4 d5 c\n\n\
DESCRIPTION\n\
    d1    value of the first die (0 if not thrown)\n\
    d2    value of the second die (0 if not thrown)\n\
    d3    value of the third die (0 if not thrown)\n\
    d4    value of the fourth die (0 if not thrown)\n\
    d5    value of the fifth die (0 if not thrown)\n\
    c     expected combination"


def is_a_dice_face(s):
    if int(s) < 0 or int(s) > 6:
        return False
    return True

def isnumber(s):
    try:
        int(s)
    except ValueError:
        return False

def check_list(die):
    z = 0
    x = 0
    for i in die:
        if isnumber(die[z]) is False:
            exit(84)
        if is_a_dice_face(die[z]) is False:
            exit(84)
        if(die[z] == "0"):
            x+=1
        z += 1
    if(x != 0 and x != 5):
        exit(84)

def check_full(arg):
    if (arg[0:4] == "full"):
        if (len(arg) != 8):
            exit(84)
        if (isnumber(arg[5]) is False):
            exit(84)
        if (is_a_dice_face(arg[5]) is True):
            if(arg[5] == "0"):
                exit(84)
        else:
            exit(84)
        if (isnumber(arg[7]) is False):
            exit(84)
        if (is_a_dice_face(arg[7]) is True):
            if(arg[7] == "0"):
                exit(84)
        else:
            exit(84)
        return(True)
    else:
        return(False)

def check_combi(combi):
    if (len(argv[6])!= 6 and len(argv[6]) != 7 and len(argv[6]) != 10):
        exit(84)
    if (isnumber(combi[1]) is False):
        exit(84)
    if (is_a_dice_face(combi[1]) is True):
        if(combi[1] == "0"):
            exit(84)
    else:
        exit(84)
    if (len(combi) > 2):
        exit(84)

if len(argv) == 1:
    exit(84)

if len(argv) == 2 and argv[1] == "-h":
    print(lishelp)
    exit(0)

if len(argv) < 7 or len(argv) > 7:
    exit(84)

die = list()
die.append(argv[1])
die.append(argv[2])
die.append(argv[3])
die.append(argv[4])
die.append(argv[5])
check_list(die)
combi = argv[6].split('_')
if (check_full(argv[6]) is False):
    check_combi(combi)