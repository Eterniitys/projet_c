#!/bin/bash
directories=("list" "parseur" "rhyme" "arbre_syll")
for dir in "${directories[@]}"; do
	echo "Nettoyage du dossier build pour $dir"
	rm -rf "$dir"/build
	mkdir "$dir"/build
	echo "Génération fichiers build pour $dir"
	cd "$dir"/build/
	cmake -DCMAKE_INSTALL_PREFIX=/tmp ../src
	echo "Génération de la librairie $dir.so"
	make
	echo "Exportation de $dir.so dans /tmp"
	make install
	cmake -DCMAKE_BUILD_TYPE=Debug ../src
	cd ../..
done

