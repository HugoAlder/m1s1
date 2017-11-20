#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# Utiliser le fichier donnee5

import sys

class Data:
    def __init__(self, n, t):
        self.n = n
        self.t = t

# Génére un objet Data à partir des données du fichier filename
def get_data(filename):
    t = []
    with open(filename) as f:
        i = 0
        n = int(f.read(1))
        for line in f:
            i = i + 1
            for word in line.split():
                t.append(int(word))
            if (i > n):
                break
        data = Data(n ,t)
    return data

def reduce(d):
    return False

if __name__ == '__main__':
    if (len(sys.argv) != 2):
        print("Usage : part2.py <file>")
        sys.exit()
    data = get_data(sys.argv[1])
