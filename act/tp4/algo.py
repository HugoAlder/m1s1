#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys

class Data:
    def __init__(self, m, n, t):
        self.m = m
        self.n = n
        self.t = t

    def display(self):
        print(self.m)
        print(self.n)
        for x in self.t:
            print(x)

    def __str__(self):
        return "({}, {}, {})".format(self.m, self.n, better_display(self))

# Genere un objet Data à partir des données du fichier filename
def get_data(filename):
    with open(filename) as f:
        m = int(next(f))
        n = int(next(f))
        t = [[0 for x in range(3)] for y in range(n)]
        for i in range(0, n):
            line = next(f)
            j = 0
            for word in line.split():
                t[i][j] = int(word)
                j += 1
    data = Data(m, n, t)
    return data

if __name__ == '__main__':
    if (len(sys.argv) != 2):
        print("Usage : algo.py <file>")
        sys.exit()
    data = get_data(sys.argv[1])
    data.display()
