#!/bin/sh

#compilation avec gcc du fichier
gcc ./src/compileBST.c

for i in ./benchmarks/benchmark*.in
do
    nom_fichier="${i##\.\/}"
    echo $nom_fichier
    nb_element="$(grep -o [-]*[0-9]* $i | wc -l)"
    ./src/a.out $nb_element $nom_fichier

done
