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
import csv

lishelp = "USAGE\n\
    ./109titration file\
\n\
DESCRIPTION\n\
    file       a csv file containing \"vol;ph\" lines"

def file_in_tab(path):
    try:
        fd = open(path)
        tab = fd.readlines()
        try:
            for i in range(len(tab)):
                tab[i] = tab[i].strip('\n').split(';')
                tab[i][0] = float(tab[i][0])
                tab[i][1] = float(tab[i][1])
                if (len(tab[i]) != 2):
                    raise IndexError
        except (ValueError, IndexError):
            exit(84)
    except :
        exit(84)
    else:
        return (tab)

def print_list(tab):
        print(tab)

if (len(argv) != 2):
    exit(84)
if (argv[1] == "-h"):
    print(lishelp)
    exit(0)
path  = argv[1]
tab = file_in_tab(path)
if len(tab) <= 1:
    exit(84)