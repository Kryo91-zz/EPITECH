#!/usr/bin/env python3

##
## EPITECH PROJECT, 2019
## 107TRANSFER_2019
## File description:
## 107transfer
##

from sys import argv, exit
from math import sin, pi

lishelp = "USAGE\n\
    ./110borwein n\
\n\
DESCRIPTION\n\
    n       constant defining the integral to be computed"

def f(x, k):
    return (sin(x / ((2*k)+1))) / (x / ((2*k)+1))

def integral(x, n):
    k = 0
    res = 1
    while (k <= n):
        res *= f(x, k)
        k += 1
    return res

def sum(x, i):
    result = 1.0
    a = 0
    while (a <= x):
        if (i != 0):
            result *= (sin(i / (2 * a + 1)) / (i / (2 * a + 1)))
        a = a + 1
    return (result)

def printer(result, i, x):
    print_list = ["Midpoint", "Trapezoidal", "Simpson"]

    print("%s:\nI%d = %.10f" % (print_list[i], int(x), result))
    if i == 2:
        if (result - (pi / 2)) < 0:
            print("diff = %.10f" % (-1 * (result - (pi / 2))))
        else:
            print("diff = %.10f" % (result - (pi / 2)))
    else:
        if (result - (pi / 2)) < 0:
            print("diff = %.10f\n" % (-1 * (result - (pi / 2))))
        else:
            print("diff = %.10f\n" % (result - (pi / 2)))

def tester(argv):
    if (len(argv) != 2):
        exit(84)
    if (argv[1] == "-h"):
        print(lishelp)
        exit(0)
    if (argv[1].isdigit() == False):
        exit(84)
    x = float(argv[1])
    return(x)