#!/usr/bin/env python3

##
## EPITECH PROJECT, 2019
## 106bombyx_2019
## File description:
## 106bombyx
##

from __future__ import print_function
from fractions import Fraction
from sys import argv, exit, stderr
from math import pow

lishelp = "USAGE\n\
    ./106bombyx n [k | i0 i1]\n\
\n\
DESCRIPTION\n\
    n       number of first generation individuals\n\
    k       growth rate from 1 to 4\n\
    i0      initial generation (included)\n\
    i1      final generation (included)                 "

errors = "Please enter 2 to 4 arguments\n\
a number of butterflies in the initial generation\n\
a growth rate ranging from 1 to 4\n\
and a number for the initial and or final generation\n\
Use -h for Usage."

def isnumber(s):
    try:
        int(s)
        return True
    except ValueError:
        try: 
            Fraction(s)
            return True
        except ValueError: 
            return False

if len(argv) == 1:
    exit(84)

if len(argv) == 4:
    try:
        n = float(argv[1])
        i0 = int(argv[2])
        i1 = int(argv[3])
    except:
        exit(84)
    if i1 <= i0:
        exit(84)
    if i1 <0 or i0 <0 or n < 0:
        exit(84)

if argv[1] == "-h":
    print(lishelp)
    exit(0)
if len (argv)!= 3 and len (argv) != 4:
    print(errors)
    exit(84)

for temp in range (1, len(argv)):
    if isnumber(argv[temp]) == False :
        print(errors)
        exit(84)

if len(argv) == 3:
    i0 = 1
    i1 = 100
    try:
        n = float(argv[1])
        k = float(argv[2])
    except:
        exit(84)

    if k > 4 or k < 1:
        exit(84)
    if n < 0:
        exit(84)