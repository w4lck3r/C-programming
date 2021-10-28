 TP BPC
=======

==========================================

Semaine 5: Les types composés (1/2) 
====================================

Semaine5 on va travail sur le fichier mcu:
 -fichier src : pour le fichier sources 
 -fichier build : pour les excutables

Exercice 1
===========

création du fichier exo1.c
compilation : gcc exo1.c -o exo1
execution : ./exo1

Exercice 2
===========

création du fichier exo2.c
compilation : gcc exo2.c -o exo2
execution : ./exo2

Exercice 3
===========

création du fichier exo.c
compilation : gcc exo.c -o exo3
execution : ./exo3

Exercice 4
===========
Création des fichier mcu_readl.c et mcu_fatal.c
compilation : gcc mcu_test.c mcu_fatal.c mcu_readl.c mcu_macros.c -o mcu_test
éxecution : ./mcu_test

Exercice 5
===========

création d'un fichier mcu_wc.c  dans le dossier build
compilation : gcc -o mcu_wc mcu_wc.c
éxécution : ./mcu_wc
création d'un fichier mcu_wl.c dans le dossier build
compilation : gcc -o mcu_wl mcu_wl.c
éxécution : ./mcu_wl


Exercice 6
===========
Création d'un fichier mcu_rev.c
compilation : gcc ../src/mcu_readl.c ../src/mcu_macros.c mcu_rev.c -o mcu_rev
(en se plaçant dans le dossier build)
éxécution : ./mcu_rev < essai

Exercice 7
===========
 Creation des fichiers mcu_uniq.c et mcu_uniq.h
compilation : gcc ../src/mcu_readl.c ../src/mcu_macros.c ../src/mcu_fatal.c mcu_uniq.c -o mcu_uniq  (en se plaçant dans le dossier build)
éxécution : ./mcu_uniq < essai
