#!/usr/bin/env python3

from sys import argv
import datetime

tab = None
def dynamique(m, n, i, j):
    global tab

    # Init tab
    if tab is None:
        tab = [[[[None for d in range(j + 1)] for c in range(i + 1)] for b in range(n + 1)] for a in range(m + 1)]
        tab[1][1][0][0] = 0

    if tab[m][n][i][j] is not None:
        return tab[m][n][i][j]

    s = []

    # Left part
    for a in range(1, i + 1):
        s.append((m - a, n, i - a, j))

    # Right part
    for a in range(i + 1, m):
        s.append((a, n, i, j))

    # Up part
    for a in range(1, j + 1):
        s.append((m, n - a, i, j - a))

    # Down part
    for a in range(j + 1, n):
        s.append((m, a, i, j))

    pos, neg = [], []
    for c in s:
        res = dynamique(*c)
        if res > 0:
            pos.append(res)
        else:
            neg.append(abs(res))

    # Result
    tab[m][n][i][j] = (-max(pos) - 1) if len(neg) == 0 else (max(neg)) + 1

    maxm, maxn, maxi, maxj = len(tab), len(tab[m]), len(tab[m][n]), len(tab[m][n][i])
    # Symetries
    if maxj > (n - j - 1):
        tab[m][n][i][n - j - 1] = tab[m][n][i][j]
    if maxi > (m - i - 1):
        tab[m][n][m - i - 1][j] = tab[m][n][i][j]
        if maxj > (n - j - 1):
            tab[m][n][m - i - 1][n - j - 1] = tab[m][n][i][j]
    
    if maxm > n and maxn > m:
        if maxi > (n - j - 1) and maxj > i:
            tab[n][m][n - j - 1][i] = tab[m][n][i][j]
        if maxi > j and maxj > (m - i - 1):
            tab[n][m][j][m - i - 1] = tab[m][n][i][j]
        if maxi > (n - j - 1) and maxj > (m - i - 1):
            tab[n][m][n - j - 1][m - i - 1] = tab[m][n][i][j]
        if maxi > j and maxj > i:
            tab[n][m][j][i] = tab[m][n][i][j]

    
    return tab[m][n][i][j]

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
