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
from math import pow, exp, factorial
from time import time

lishelp = "USAGE\n\
    ./203hotline [n k | d]\n\n\
DESCRIPTION\n\
    n    n value for the computation of C(n, k)\n\
    k    k value for the computation of C(n, k)\n\
    d    average duration of calls (in seconds)"

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

if len(argv) < 2 or len(argv) > 3:
    exit(84)

if(len(argv) == 2):
    if isnumber(argv[1]) is False:
        exit(84)
elif(len(argv) == 3):
    if isnumber(argv[1]) is False:
        exit(84)
    if isnumber(argv[2]) is False:
        exit(84)
    if int(argv[1]) < int(argv[2]):
        exit(84)
