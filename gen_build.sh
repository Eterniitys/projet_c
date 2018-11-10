#!/bin/bash
directories=("list" "word" "parseur" "rhyme" "arbre_syll")
for dir in "${directories[@]}"; do
	echo -e "\e[32;1mNettoyage du dossier build pour $dir\e[0m"
	rm -rf "$dir"/build
	mkdir "$dir"/build
	echo -e "\e[36mGénération fichiers build pour \e[33;1m$dir\e[0m"
	cd "$dir"/build/
	cmake -DCMAKE_INSTALL_PREFIX=/tmp ../src
	echo -e "\e[36mGénération de la \e[33;1;4mlib$dir.so\e[0m"
	make
	echo -e "\e[35mExportation de \e[33;1;4mlib$dir.so\e[0m dans /tmp"
	make install
	cmake -DCMAKE_BUILD_TYPE=Debug ../src
	cd ../..
done

