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
from math import pow, exp, factorial, sqrt, ceil, pi
from time import time
import csv

lishelp = "USAGE\n\
    /208dowels O0 O1 O2 O3 O4 O5 O6 O7 O8\n\n\
DESCRIPTION\n\
    Oi size of the observed class"


if len(argv) == 2 and argv[1] == "-h":
    print(lishelp)
    exit(0)

if len(argv) < 10 or len(argv) > 10:
    exit(84);

try:
    O0 = int(argv[1])
    O1 = int(argv[2])
    O2 = int(argv[3])
    O3 = int(argv[4])
    O4 = int(argv[5])
    O5 = int(argv[6])
    O6 = int(argv[7])
    O7 = int(argv[8])
    O8 = int(argv[9])
except:
    exit(84)