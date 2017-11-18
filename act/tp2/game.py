from sys import argv
import datetime
import numpy

cache = None
res_m, res_n, res_i, res_j = None

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
                
        save = [[[[None for a in range(lij + 1)] for b in range(lij + 1)] for c in range(lmn + 1)] for d in range(lmn + 1)]

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
                tmp = acc(m - x, n, i - x, j)
                values.append(tmp)
                save[m - x][n][i - x][j] = tmp
            elif (x > i):
                tmp = acc(x, n, i, j)
                values.append(tmp)
                save[x][n][i][j] = tmp

    # En divisant dans le sens de la largeur
    if (n > 1):
        for y in range(1, n):
            if (y <= j):
                tmp = acc(m, n - y, i, j - y)
                values.append(tmp)
                save[m][n - y][i][j] = tmp
            elif (y > j):
                tmp = acc(m, y, i, j)
                values.append(tmp)
                save[m][y][i][j] = tmp

    # Nombres négatifs
    for k in values:
        if (k <= 0):
            neg.append(k)
        else:
            pos.append(k)

    # Valeur de retour
    if (len(neg) == 0):
        cache[m][n][i][j] = -(max(pos) + 1)
        numpy.where(save, max(pos))
    else:
        cache[m][n][i][j] = abs(max(neg)) + 1
        numpy.where(save, max(neg))
        
    cache[m][n][i][n - 1 - j] = cache[m][n][i][j]
    cache[m][n][m - 1 - i][j] = cache[m][n][i][j]
    cache[m][n][m - 1 - i][n - 1 - j] = cache[m][n][i][j]
    
    cache[n][m][j][i] = cache[m][n][i][j]
    cache[n][m][j][m - 1 - i] = cache[m][n][i][j]
    cache[n][m][n - 1 - j][i] = cache[m][n][i][j]
    cache[n][m][n - 1 - j][m - 1 - i] = cache[m][n][i][j]
    
    return cache[m][n][i][j]

if __name__ == '__main__':
    
    m = 3
    n = 3
    i = 1
    j = 1

    while True:

        tab = [[0 for x in range(m)] for y in range(n)] 
        tab[j][i] = 1

        for x in range (0, n):
            print(tab[x])
    
        if (m == 1 and n == 1):
            print("Player lost\n")
            break

        while True:

            if (m == 1):
                inp = 1
                break
            elif (n == 1):
                inp = 0
                break
            else:                
                try :
                    inp = int(input("Type 0 to change m, 1 to change n\n"))

                except ValueError:
                    print("Error : value not a number\n")
                    continue

                if (inp != 0 and inp != 1):
                    print("Error : value not 0 nor 1\n")
                    continue

                else:
                    break

        while True:
        
            try :
                # If m2 is positive, it takes the m2 columns starting from the left.
                # If m2 is negative, it takes the abs(m2) columns starting from the right.
                # If n2 is postivive, it takes the n2 rows starting from the top.
                # If n2 is negative, it takes the abs(n2) rows starting from the bottom.
                value = int(input("Your value ?\n"))
                
            except ValueError:
                print("Error : value not a number\n")
                continue

            if (value == 0):
                print("Error : can't be 0\n")
                continue

            if (inp == 0):
                if (value > 0):
                    if (value >= m or value < i + 1):
                        print("Incorrect value\n")
                        continue
                    else:
                        m = value
                else:
                    if (abs(value) >= m or abs(value) < m - i):
                        print("Incorrect value\n")
                        continue
                    else:
                        i = i - (m + value)
                        m = abs(value)
            else:      
                if (value > 0):
                    if (value >= n or value < j + 1):
                        print("Incorrect value\n")
                        continue
                    else:
                        n = value
                else:
                    if (abs(value) >= n or abs(value) < n - j):
                        print("Incorrect value\n")
                        continue
                    else:
                        j = j - (n + value)
                        n = abs(value)

            print("End of turn\n")
            break;
