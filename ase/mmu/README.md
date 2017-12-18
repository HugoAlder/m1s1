# Virtualisation de la mémoire du microprocesseur

* Auteur : Hugo Alder

* Description : mise en place d'une MMU (Memory Management Unit). Le principe est de permettre à un logiciel d'intercepter les accès à la mémoire centrale. Il donne au système d'exploitation le moyen de contrôler les accès à la mémoire physique, et permet de remplacer l'adresse demandée par l'application (adresse virtuelle) par une autre adresse (adresse physique) désignant une zone de mémoire réelle.

* Utilisation : se positionner à la racine du projet et lancer la commande `make`.

* Tous les exécutables produits se trouvent dans le dossier ./bin.

## Commandes

* `./bin/test_mmu` : renvoie une tentative d'accès illégal car le programme de dispose pas des droits nécessaires pour accéder à la zone mémoire du pointeur ptr.

* `./bin/static_mmu` : renvoie 2 valeurs différentes car on accède à des zones mémoire différentes selon si on se trouve dans process0 ou process1.

* Pour vérifier le bon fonctionnement des développements, utiliser la commande `bin/mmu_manager | tee /dev/stderr | ./bin/oracle`
