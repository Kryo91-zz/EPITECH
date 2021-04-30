#!/bin/bash

blih.py -u  corentin.petrau@epitech.eu repository create $1 
blih.py -u  corentin.petrau@epitech.eu repository setacl $1 ramassage-tek r
blih.py -u  corentin.petrau@epitech.eu repository getacl $1
