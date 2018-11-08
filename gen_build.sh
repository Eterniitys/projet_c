#!/bin/bash
directories=("parseur" "rime" "arbre_syll")
for dir in "${directories[@]}"; do
	echo "Nettoyage du dossier build pour $dir"
	rm -rf "$dir"/build
	mkdir "$dir"/build
	echo "Génération fichiers build pour $dir"
	cd "$dir"/build/
	cmake ../src
	cd ../..
done

