#!/bin/sh

#compilation avec gcc du fichier
# Pour les outputs en couleurs
GREEN='\033[0;32m'
RED='\033[0;31m'

# Compilation avec gcc du fichier
gcc -Wall ./src/compileBST.c ./src/racine_optimal.c 
cp a.out ./bin/a.out
rm a.out

for i in ./benchmarks/benchmark*.in
do
    nom_fichier="${i##\.\/}"
    echo "Fichier testé = $nom_fichier"
    nb_element="$(grep -o [-]*[0-9]* $i | wc -l)"
    # Récupération de la sortie de notre programme
    sortie="$(time ./bin/a.out $nb_element $nom_fichier)"

    # A commenter dans la version finale
    echo "$sortie"
    
    nom_fichier_sortie="${nom_fichier%\.in}"
    nom_fichier_sortie="$nom_fichier_sortie".out
    # Recuperation des bonnes lignes dans le fichier
    #sortie_theorique="$(tail -n +2 $mon_fichier_sortie)"

    # On compare les deux sorties
    #if [ "$sortie_theorique" = "$sortie" ]
    #then
	#echo -e "${GREEN}Passed${NC}"
    #else
	#echo -e "${RED}Failed${NC}"
    #fi

done
