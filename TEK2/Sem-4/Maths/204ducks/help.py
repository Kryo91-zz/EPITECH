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
from math import pow, exp, factorial, ceil, sqrt
from time import time

lishelp = "USAGE\n\
    ./204ducks a\n\n\
DESCRIPTION\n\
    a    constant"

def isnumber(s):
    try:
        int(s)
    except ValueError:
        try:
            float(s)
        except ValueError:
            return False

if len(argv) == 1:
    exit(84)

if len(argv) == 2 and argv[1] == "-h":
    print(lishelp)
    exit(0)

if len(argv) < 2 or len(argv) > 2:
    exit(84)

if isnumber(argv[1]) is False:
    exit(84)
if(float(argv[1]) < 0 or float(argv[1]) > 2.5 ):
    exit(84)
