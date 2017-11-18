from sys import argv
import datetime

cache = None

# Origine en haut à gauche
# m : largeur
# n : hauteur
# i : position du carré de la mort (largeur)
# j : position du carré de la mort (hauteur)

def acc(m, n, i, j):
    
    global cache
    values, pos, neg = [], [], []

    # Initialisation du cache
    if (cache is None):
        lmn = max(m, n)
        lij = max(i, j)
        cache = [[[[None for a in range(lij + 1)] for b in range(lij + 1)] for c in range(lmn + 1)] for d in range(lmn + 1)]
        cache[1][1][0][0] = 0

    # Verification de l'existence de la valeur pour toutes les symétries
    if (cache[m][n][i][j] is not None):
        return cache[m][n][i][j]
    
    elif (cache[m][n][i][n - 1 - j] is not None):
        return cache[m][n][i][n - 1 - j]
    
    elif (cache[m][n][m - 1 - i][j] is not None):
        return cache[m][n][m - 1 - i][j]
    
    elif (cache[m][n][m - 1 - i][n - 1 - j] is not None):
        return cache[m][n][m - 1 - i][n - 1 - j]

    elif (cache[n][m][j][i] is not None):
        return cache[n][m][j][i]
    
    elif (cache[n][m][j][m - 1 - i] is not None):
        return cache[n][m][j][m - 1 - i]
    
    elif (cache[n][m][n - 1 - j][i] is not None):
        return cache[n][m][n - 1 - j][i]
    
    elif (cache[n][m][n - 1 - j][m - 1 - i] is not None):
        return cache[n][m][n - 1 - j][m - 1 - i]
    
    if (m == 1 and n == 1):
        return 0

    # En divisant dans le sens de la hauteur
    if (m > 1):
        for x in range(1, m):
            if (x <= i):
                values.append(acc(m - x, n, i - x, j))
            elif (x > i):
                values.append(acc(x, n, i, j))

    # En divisant dans le sens de la largeur
    if (n > 1):
        for y in range(1, n):
            if (y <= j):
                values.append(acc(m, n - y, i, j - y))
            elif (y > j):
                values.append(acc(m, y, i, j))

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
        
    cache[m][n][i][n - 1 - j] = cache[m][n][i][j]
    cache[m][n][m - 1 - i][j] = cache[m][n][i][j]
    cache[m][n][m - 1 - i][n - 1 - j] = cache[m][n][i][j]
    
    cache[n][m][j][i] = cache[m][n][i][j]
    cache[n][m][j][m - 1 - i] = cache[m][n][i][j]
    cache[n][m][n - 1 - j][i] = cache[m][n][i][j]
    cache[n][m][n - 1 - j][m - 1 - i] = cache[m][n][i][j]
    
    return cache[m][n][i][j]

if __name__ == '__main__':
    t1 = datetime.datetime.now()
    print('(100,100,50,50) : {}'.format(acc(100,100,48,52)))
    print('Time : {}'.format(datetime.datetime.now() - t1))

