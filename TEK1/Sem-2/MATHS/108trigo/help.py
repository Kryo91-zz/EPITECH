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
from math import pow, sin, cos, exp, cosh, sinh, sqrt, trunc
from string import ascii_uppercase

lishelp = "USAGE\n\
    ./108trigo fun a0 a1 a2 ...\
\n\
DESCRIPTION\n\
    fun       function to be applied, among at least \"EXP\", \"COS\", \"SIN\", \"COSH\"\n\
              and \"SIHN\"\n\
    ai        coeficients of the matrix"

def make_matrix(argv) :
    length = 0
    temp = 2
    for i in range (0, len(argv)) :
        if (i * i) >= (len(argv) - 2) :
            length = i
            break
        i += 1
    matrice = [[0 for j in range(length)] for j in range(length)]
    for i in range (0, length) :
        for j in range (0, length) :
            matrice[i][j] = float(argv[temp])
            temp += 1
            if temp > len(argv) - 1:
                break
        if temp > len(argv) - 1:
            break
    return (matrice)

def print_matrix(matrix) :
    for temp in range(len(matrix)) :
        for temp2 in range(len(matrix[temp])) :
            print("%.2f"%matrix[temp][temp2], end = '\t')
        print('')

def is_all_uppercase(a_str):
    for c in a_str:
        if c not in ascii_uppercase:
            return False
    return True

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
    print(lishelp)
    exit(84)

if len(argv) == 2 and argv[1] == "-h":
    print(lishelp)
    exit(0)

if len(argv) < 3:
    exit(84)

if is_all_uppercase(argv[1]) is False :
    exit (84)

for i in range (2, len(argv)) :
        if isnumber(argv[i]) is False :
            print(lishelp)
            exit(84)

i = len(argv) - 2
sqi = trunc(sqrt(i))
if trunc(sqrt(i)) ** 2 != i:
    print("Not enough parameters to create a matrix")
    exit(84)

if argv[1] != "SIN" and argv[1] != "EXP" and argv[1] != "COS" and argv[1] != "COSH" and argv[1] != "SINH":
    exit(84)

print_matrix(make_matrix(argv))