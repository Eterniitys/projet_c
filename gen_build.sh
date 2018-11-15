#!/bin/bash
message_erreur() {
	if [[ $1 != 0 ]]; then
		tput setaf 9
		echo ""
		echo "##############"
		echo "# = ERREUR = #"
		echo "##############"
		echo ""
		tput sgr0
	fi
}

directories=("list" "word" "parseur" "rhyme" "tree")
for dir in "${directories[@]}"; do
	echo -e "\e[32;1mNettoyage du dossier build pour $dir\e[0m"
	rm -rf "$dir"/build
	mkdir "$dir"/build
	echo -e "\e[36mGénération fichiers build pour \e[33;1m$dir\e[0m"
	cd "$dir"/build/
	cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=/tmp ../src
	message_erreur $?
	echo -e "\e[36mGénération de la \e[33;1;4mlib$dir.so\e[0m"
	make
	message_erreur $?
	echo -e "\e[36mExecution des tests de \e[33;1;4m$dir\e[0m"
	make test
	message_erreur $?
	echo -e "\e[35mExportation de \e[33;1;4mlib$dir.so\e[0m dans /tmp"
	make install
	message_erreur $?
	cd ../..
done

