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

lishelp = "USAGE\n\
    ./205IQ u s [IQ1] [IQ2]\n\n\
DESCRIPTION\n\
    u    mean\n\
    s    standard deviation\n\
    IQ1    minimum IQ\n\
    IQ2    maximum IQ"

def isnumber(s):
    try:
        int(s)
    except ValueError:
        try:
            float(s)
        except ValueError:
            return False

def check_list(die):
    z = 0
    for i in die:
        if isnumber(die[i]) is False:
            exit(84)

if len(argv) == 1:
    exit(84)

if len(argv) == 2 and argv[1] == "-h":
    print(lishelp)
    exit(0)

if len(argv) < 3 or len(argv) > 5:
    exit(84)

if int(argv[1]) < 0:
    exit(84)

if int(argv[2]) < 0:
    exit(84)

if len(argv) == 4:
    if int(argv[3]) < 0 or int(argv[3]) > 200:
        exit(84)

if len(argv) == 5:
    if not int(argv[3]) < int(argv[4]):
        exit(84)
    if int(argv[3]) < 0:
        exit(84)
    if int(argv[3]) < 0 or int(argv[3]) > 200:
        exit(84)
    if int(argv[4]) < 0 or int(argv[4]) > 200:
        exit(84)
    if (int(argv[3]) > int(argv[4])):
        exit(84)