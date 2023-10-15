#!/usr/bin/python

import sys

with open(sys.argv[1], "r") as f:
    valores = [int(x) for x in f.readline()[:-2].split()]

    mini, maxi = f.readline()[:-1].split()

    print(f"{int(mini) == min(valores)} {int(maxi) == max(valores)} {f.readline()[:-1]}")

