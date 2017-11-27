ACT - TP3   
ALDER Hugo  
SEYS Nicolas

# Qu'est ce qu'une propriété NP ?

## Q1

Un certificat sera présenté sous la forme d'un tableau à 2 colonnes et n lignes.
Chaque ligne représente une tâche.
La première colonne de chaque ligne indique la machine utilisée.
La seconde colonne indique la date de début de la tâche.  

La taille d'un certificat est donc 2*n : elle est bien bornée polynomialement par
rapport à la taille de l'entrée.

Algorithme de vérification :

Pour chaque tâche ni  
&nbsp;&nbsp;Vérifier que ai <= départ <= ai + D  
&nbsp;&nbsp;La machine m ne doit pas être utilisée par une autre tâche pendant la
durée d'execution de ni

## Q2.1

Algorithme de génération aléatoire de certificat :  

Initialisation du certificat c[n][2]  
&nbsp;&nbsp;Pour chaque tâche ni  
&nbsp;&nbsp;&nbsp;&nbsp;c[ni][0] = une machine aléatoire entre 0 et m-1  
&nbsp;&nbsp;&nbsp;&nbsp;c[ni][1] = une date de départ aléatoire comprise entre a1 et a1 + D  
Retourner c

## Q2.2

Schéma d'un algorithme non-dédéterministe polynomial pour le problème :  

Génération aléatoire d'un certificat c  
&nbsp;&nbsp;Tant que c n'est pas une certificat correct  
&nbsp;&nbsp;&nbsp;&nbsp;Générer un autre certificat c  
Retourner c

## Q3.1

Pour une instance donnée, le nombre de certificats est de l'ordre de n \* m \* (D + 1)

## Q3.2

On propose comme ordre de d'abord modifier les machines, puis les dates de départ.

## Q3.3

Initialisation du certificat c[n][2]  
&nbsp;&nbsp;On affecte à c les valeurs de départ  
&nbsp;&nbsp;Tant que c n'est pas un certificat correct  
&nbsp;&nbsp;&nbsp;&nbsp;On test une nouvelle combinaison pour c  
Retourner c

Complexité de l'algorithme : n \* m \* (D + 1). On vérifie tous les certificats
possibles dans le pire des cas.

## Implémentation

Voir part1.py, à utiliser avec les fichiers donneeX.

# Réductions polynomiales

## Q5.1

Si on réduit une instance du problème Partition en une instance de JSP, le
problème devient au moins aussi facile que JSP.

## Q5.2

Non, car une instance de JSP est définie par un tableau à 2 dimensions.

## Q5.3

A implémenter dans part2.py.

## Q6.1

Le certificat du problème SUM se présente sous la forme tableau d'entier de
taille inférieur ou égale à n soit θ(2n log n) ce qui est polynomial par
rapport à n.

On peut vérifier en faisant la somme des nombres contenus dans le certificat
et renvoie vrai si le résultat est égal à s.
Etant donné qu'on ne réalise qu'un parcours du certificat, le problème est
polynomial.  

Le problème est NP puisque la vérification et le certificat sont
polynomial.

## Q6.2

Si s vaut la moitié de la somme des xi, on a une instance de Partition.  

## Q6.3

\-

## Q7

A implémenter dans part2.py.

# Optimisation versus Décision

## Q8

\-

## Q9

Opt1 est au moins aussi dur que JSP car si JSP est P, Opt1 peut l’être aussi.
