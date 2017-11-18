from sys import argv
import datetime

cache = None

# Origine en haut à gauche
# m : largeur
# n : hauteur
# i : position du carré de la mort (largeur)
# j : position du carré de la mort (hauteur)

def dyn(m, n, i, j):
    
    global cache
    values, pos, neg = [], [], []

    # Initialisation du cache
    if (cache is None):
        cache = [[[[None for a in range(j + 1)] for b in range(i + 1)] for c in range(n + 1)] for d in range(m + 1)]
        cache[1][1][0][0] = 0

    # Verification de l'existence de la valeur
    if (cache[m][n][i][j] is not None):
        return cache[m][n][i][j]
    
    if (m == 1 and n == 1):
        return 0

    # En divisant dans le sens de la hauteur
    if (m > 1):
        for x in range(1, m):
            if (x <= i):
                values.append(dyn(m - x, n, i - x, j))
            elif (x > i):
                values.append(dyn(x, n, i, j))

    # En divisant dans le sens de la largeur
    if (n > 1):
        for y in range(1, n):
            if (y <= j):
                values.append(dyn(m, n - y, i, j - y))
            elif (y > j):
                values.append(dyn(m, y, i, j))

    # Nombres négatifs
    for k in values:
        if (k <= 0):
            neg.append(k)
        else:
            pos.append(k)

    # Valeur de retour
    if (len(neg) == 0):
        cache[m][n][i][j] = -(max(pos) + 1) 
    else:
        cache[m][n][i][j] = abs(max(neg)) + 1 
    return cache[m][n][i][j]

if __name__ == '__main__':
    t1 = datetime.datetime.now()
    print('(100,100,50,50) : {}'.format(dyn(100,100,48,52)))
    print('Time : {}'.format(datetime.datetime.now() - t1))
