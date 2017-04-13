#!/bin/sh

#compilation avec gcc du fichier
gcc -Wall ./src/compileBST.c ./src/racine_optimal.c 
cp a.out ./bin/a.out
rm a.out

for i in ./benchmarks/benchmark*.in
do
    nom_fichier="${i##\.\/}"
    echo "Fichier testé = $nom_fichier"
    nb_element="$(grep -o [-]*[0-9]* $i | wc -l)"
    sortie="$(./bin/a.out $nb_element $nom_fichier)"
    echo "$sortie"
    
    nom_fichier_sortie="${nom_fichier%\.in}"
    nom_fichier_sortie="$nom_fichier_sortie".out
    #tail -n +2 $mon_fichier_sortie


done
