#!/usr/bin/python

import sys

with open(sys.argv[1], "r") as f:
    print(f"{f.readline()[:-1]} {f.readline()[:-1]}")

