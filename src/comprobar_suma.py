#!/usr/bin/python

import sys

with open(sys.argv[1], "r") as f:
    suma = sum([int(x) for x in f.readline()[:-2].split()])

    print(f"{suma == int(f.readline()[:-1])} {f.readline()[:-1]}")

