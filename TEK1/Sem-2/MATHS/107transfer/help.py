#!/usr/bin/env python3

##
## EPITECH PROJECT, 2019
## 107TRANSFER_2019
## File description:
## 107transfer
##

from __future__ import print_function
from fractions import Fraction
from sys import argv, exit, stderr
from math import pow

lishelp = "USAGE\n\
    ./107transfer [num dem]*\
\n\
DESCRIPTION\n\
    num       polynomial numerator defined by its coefficients\n\
    dem       polynomial denominator defined by its coefficients"

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

def empty_str(n):
    a = n
    if (a == "") :
        print("Floating exception")
        exit(84)

def Floatexcept(n):
    try:
        a = int(n)
        if (a == 0) :
            print("Floating exception")
            exit(84)
    except ValueError:
        if n[0] != '-' :
            a = int(n[0])
            if (a == 0) :
                print("Floating exception")
                exit(84)
        else :
            if (len(n) == 2) :
                a = int(n[1])
                if (a == 0) :
                    print("Floating exception")
                    exit(84)

if len(argv) == 1:
    exit(84)

if len(argv) == 2 and argv[1] == "-h":
    print(lishelp)
    exit(0)

if len(argv) < 3:
    exit(84)

if ((len(argv) - 1) % 2 != 0) :
    print(lishelp)
    exit(84)

for i in range (1, len(argv)) :
    for j in range(0, len(argv[i])) :
        if isnumber(argv[i][j]) is False and argv[i][j] != '*' and argv[i][j] != '-' :
            print(lishelp)
            exit(84)
        if argv[i][len(argv[i]) - 1] == '*' :
            print(lishelp)
            exit(84)
        if argv[i][0] == '*' :
            print(lishelp)
            exit(84)
        if argv[i][j] == '*' :
            if argv[i][j - 1] == '*' or argv[i][j + 1] == '*' :
                print(lishelp)
                exit(84)
    empty_str(argv[i])
    if i % 2 == 0 :
        Floatexcept(argv[i])