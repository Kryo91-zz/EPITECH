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
    /209poll pSize sSize p\n\n\
DESCRIPTION\n\
    pSize\tsize of the population\n\
    sSize\tsize of the sample (supposed to be representative)\n\
    p\tpercentage of voting intentions for a specific candidate"

if len(argv) == 1:
    exit(84)

if len(argv) == 2 and argv[1] == "-h":
    print(lishelp)
    exit(0)

if len(argv) < 4:
    exit(84)

if len(argv) > 4:
    exit(84)

try:
    pSize = int(argv[1])
    sSize = int(argv[2])
    p = float(argv[3])
except:
    exit(84)

if pSize < 0 or sSize < 0:
    exit(84)

if p > 100.0 or p < 0.0:
    exit(84)
