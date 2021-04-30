#!/usr/bin/env python3

##
## EPITECH PROJECT, 2019
## 103cipher_2019
## File description:
## 103cipher
##

from __future__ import print_function
from fractions import Fraction
from sys import argv, exit, stderr
from math import pow
lishelp = "USAGE\n\
    ./105torus opt a0 a1 a2 a3 a4 n\n\
\n\
DESCRIPTION\n\
    opt         method option:\n\
                    1 for the bisection method\n\
                    2 for Newton’s method\n\
                    3 for the secant method\n\
    a[0-4]      coefficients of the equation\n\
    n           precision (the application of the polynomial to the solution should\n\
                be smaller than 10ˆ-n)"


errors = "Please enter 3 to 7 arguments\n\
an option ranging from one to 3\n\
one to 4 coefficients for the equations\n\
and the decimal precision represdented as n\n\
Use -h for Usage."

num = [0, 0, 0, 0, 0, 0, 0]

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

if len (argv)!= 2 and len (argv) != 8 :
    # print(errors)
    exit(84)
if argv[1] == "-h" :
    print(lishelp)
    exit(0)

y = len(argv) - 1
numb = y - 1

for temp in range (1, len(argv)) :
    if isnumber(argv[temp]) == False :
        # print(errors)
        exit(84)

while y >= 1:
  num[numb] = argv[y]
  if argv[1] != "-h" :
    num[numb] = int(num[numb])
    numb -= 1
  y -= 1

if num[0] > 3 or num[0] < 1 :
    # print(errors)
    exit(84)

if num[6] <= 0:
    # print(errors)
    exit(84)

opt = num[0]
a0 = num[1]
a1 = num[2]
a2 = num[3]
a3 = num[4]
a4 = num[5]
n = num[6]
