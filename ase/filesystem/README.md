# Système de fichiers

* Auteur : Hugo Alder

* Description : réalisation d'un système de fichiers au dessus d'un disque magnétique organisé en pistes et secteurs. Il est composé de différentes couches successives.

* Utilisation : se positionner à la racine du projet et lancer la commande `make`. Pour remettre le disque à zéro, lancer la commande `make realclean`.

* Tous les exécutables produits se trouvent dans le dossier ./bin.

## Couche 1 : accès au matériel
* `./bin/dmps <vol> <cyl>` : afficher le contenu d'un secteur octet par octet sous forme hexadécimale.

* `./bin/frmt (-r)` : formater la totalité du disque. L'option -r permet de réaliser la même opération en commençant le formatage du disque dans le sens inverse (en parcourant le disque en partant de la fin).

## Couche 2 : gestion de volumes

* `/bin/mkvol <cyl> <sec> <size> <type> <name>` : créer un volume à partir du cylindre `<cyl>` et du secteur `<sec>`, de taille `<size>`, de type type et de nom `<name>`.

* `/bin/dvol` : afficher les informations relatives aux volumes présents sur le disque.

* `/bin/rmvol <vol>` : supprimer un volume.

## Couche 3 : structure d'un volume et d'un fichier

* `/bin/test_vol` : manipulations simples de blocks grâce aux fonctions new_block() et free_block(). Nécessite la création d'un volume au préalable.

## Couche 4 : manipulations de fichiers

* `/bin/if_nfile` : créer un fichier. Le contenu du fichier est lu sur l'entrée standard. Le inombre du fichier est retourné sur la sortie standard.

* `/bin/if_pfile <inumber>` : afficher le contenu d'un fichier dont le inombre est passé en paramètre sur la sortie standard.

* `/bin/if_dfile <inumber>` : supprimer le fichier dont le inombre est passé en paramètre.

* `/bin/if_cfile <inumber>` : copier le contenu du fichier dont le inombre est passé en paramètre dans un second fichier. Ce second fichier est donc créé; son inombre est affiché sur la sortie standard.
