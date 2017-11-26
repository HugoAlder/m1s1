#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys
from random import randint

class Data:
    def __init__(self, m, n, t, d):
        self.m = m
        self.n = n
        self.t = t
        self.d = d

    def __str__(self):
        return "({}, {}, {}, {})".format(self.m, self.n, self.t, self.d)

# Genere un objet Data à partir des données du fichier filename
def get_data(filename):
    with open(filename) as f:
        m = int(f.read(1))
        f.read(1)
        n = int(f.read(1))
        t = [[0 for x in range(2)] for y in range(n)]
        for x in range (0, n):
            for y in range (0, 2):
                f.read(1)
                t[x][y] = int(f.read(1))
        data = Data(m, n, t, 0)
    return data

# Génére un Certificat aléatoire à partir des données de data
def alea(data):
    c = [[0 for x in range(2)] for y in range(data.n)]
    for x in range (0, data.n):
        c[x][0] = randint(0, data.m - 1)
        # Garantie ai <= di <= ai + D
        c[x][1] = randint(data.t[x][0], data.t[x][0] + data.d)
    return c

# Vérifie si les départs dep et les durées dur des tâches assignées à une machine sont cohérents
def check_dispo(dep, fin):
    if (len(dep) != len(fin)):
        return False
    l = len(dep)
    for x in range (0, l):
        for x2 in range(0, l):
            if (x != x2):
                if (dep[x] >= dep[x2] and dep[x] < fin[x2]):
                    return False
                if (fin[x] > dep[x2] and fin[x] <= fin[x2]):
                    return False
    return True

# Vérifie si le certificat c est correct d'aprés les données d disponibles
def check_certificat(d, c):
    # Pour chaque machine
    for m in range(0, d.m):
        tDep = []
        tFin = []
        # Pour chaque tache de la machine m
        for n in range(0, d.n):
            if (c[n][0] == m):
                dep = c[n][1]
                fin = dep + d.t[n][1] - 1
                tDep.append(dep)
                tFin.append(fin)
        # On verifie si les valeurs sont correctes
        # print("tDep : {}".format(tDep))
        # print("tFin : {}".format(tFin))
        dispo = check_dispo(tDep, tFin)
        if (dispo == False):
            print("Erreur : ordonnancement machine {}".format(m))
            return False
    return True

# Genere et test toutes les combinaisons de certificat possibles pour les données d
def british_museum(d):
    c = [[0 for x in range(2)] for y in range(d.n)]
    while check_certificat(c) == False:
        for x in (0, d.n):
            for y in (0, d.m):
                for z in (0, d.d):
                    c[x][0] = y
                    c[x][1] = d.t[x][0] + z

if __name__ == '__main__':
    if (len(sys.argv) != 4):
        print("Usage : part1.py <file> <mode> <attenteMax>")
        sys.exit()
    data = get_data(sys.argv[1])
    data.d = int(sys.argv[3])

    if (sys.argv[2] == "-verif"):
        certificat = [[0 for a in range(2)] for b in range(data.n)]
        for x in range (0, data.n):
            print("Task", x)
            m = input("Machine: ")
            certificat[x][0] = int(m)
            dep = input("Depart: ")
            certificat[x][1] = int(dep)

    elif (sys.argv[2] == "-nondet"):
        certificat = alea(data)
        while(check_certificat(data, certificat) == False):
            print(certificat)
            certificat = alea(data)

    elif (sys.argv[2] == "-exhaust"):
        certificat = british_museum(data)

    print("Certificat:", certificat)
    print("Resultat: ", check_certificat(data, certificat))
