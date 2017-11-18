#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
from random import randint

class Certificat:
    def __init__(self, c):
        self.c = c

    def __str__(self):
        return "({})".format(self.c)

class Data:
    def __init__(self, m, n, t, d):
        self.m = m
        self.n = n
        self.t = t
        self.d = d

    def __str__(self):
        return "({}, {}, {}, {})".format(self.m, self.n, self.t, self.d)

# Génére un objet Data à partir des données du fichier filename
def get_data(filename):
    f = open(filename)
    m = int(f.read(1))
    f.read(1)
    n = int(f.read(1))
    t = [[0 for x in range(2)] for y in range(n)]
    for x in range (0, n):
        for y in range (0, 2):
            f.read(1)
            t[x][y] = int(f.read(1))
    f.read(1)
    d = int(f.read(1))
    data = Data(m, n, t, d)
    return data

# Génére un Certificat aléatoire à partir des données de data
def alea(data):
    c = [[0 for x in range(2)] for y in range(data.n)]
    for x in range (0, data.n):
        c[x][0] = randint(0, data.m)
        c[x][1] = randint(data.t[x][0], data.t[x][0] + data.d)
    return Certificat(c)

# Vérifie si le Certificat est correct d'aprés les données disponibles
def check_certificat(data, certificat):
    for x in range (0, data.n):
        mch = certificat.c[x][0]
        dep = certificat.c[x][1]
        dur = data.t[x][1]
        for x2 in range(0, data.n):
            if (x =! x2):
                if ()


if __name__ == '__main__':
    data = get_data(sys.argv[1])
    print alea(data)
