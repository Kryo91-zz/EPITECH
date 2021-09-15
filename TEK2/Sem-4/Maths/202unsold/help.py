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
    ./202unsold a b\n\n\
DESCRIPTION\n\
    a    constant computed from past results\n\
    b    constant computed from past results"

def isnumber(s):
    try:
        int(s)
    except ValueError:
        return False

if len(argv) == 1:
    exit(84)

if len(argv) == 2 and argv[1] == "-h":
    print(lishelp)
    exit(0)

if len(argv) < 3 or len(argv) > 3:
    exit(84)

if isnumber(argv[1]) is False or isnumber(argv[2]) is False:
    exit(84)
else:
    if int(argv[1]) < 50 or int(argv[2]) < 50 :
        exit(84)