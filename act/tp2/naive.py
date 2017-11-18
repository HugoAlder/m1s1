# Origine en haut à gauche
# m : largeur
# n : hauteur
# i : position du carré de la mort (largeur)
# j : position du carré de la mort (hauteur)

def naive(m, n, i, j):

    values, pos, neg = [], [], []

    if (m == 1 and n == 1):
        return 0
    
    # En divisant dans le sens de la hauteur
    if (m > 1):
        for x in range(1, m):
            if (x <= i):
                values.append(naive(m - x, n, i - x, j))
            elif (x > i):
                values.append(naive(x, n, i, j))

    # En divisant dans le sens de la largeur
    if (n > 1):
        for y in range(1, n):
            if (y <= j):
                values.append(naive(m, n - y, i, j - y))
            elif (y > j):
                values.append(naive(m, y, i, j))

    # Nombres négatifs
    for k in values:
        if (k <= 0):
            neg.append(k)
        else:
            pos.append(k)

    # Valeur de retour
    if (len(neg) == 0):
        return -(max(pos) + 1) 
    else:
        return abs(max(neg)) + 1 
