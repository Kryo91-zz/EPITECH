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

listcountries = []
listcodes = []
listvalues = []

lishelp = "USAGE\n\
    /207demography code [...]\n\n\
DESCRIPTION\n\
    code\tcountry code"

if len(argv) == 1:
    exit(84)

if len(argv) == 2 and argv[1] == "-h":
    print(lishelp)
    exit(0)

try:
    with open('207demography_data.csv', newline='') as csvfile:
        spamreader = csv.reader(csvfile, delimiter=';')
        try:
            for row in spamreader:
                listcountries.append(row[0])
                listcodes.append(row[1])
                listvalues.append(row[2:])
        except csv.Error as e:
            exit(84)
except:
    exit(84)

i = 0
for item in listcodes:
    for arg in argv:
        if (arg == item):
            i += 1

if (i != len(argv) - 1):
    exit(84)