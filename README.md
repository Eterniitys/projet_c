# Symphonie

How to compile:
```bash
mkdir build
cd build
cmake -DCMAKE_MODULE_PATH="$(pwd)/../cmake/" -DUSE_VALGRIND=1 ..
make
```

How to run:
```bash
./symphonie
```

Le but du projet est de produire un logiciel capable de :
— donner les mots rimant avec un mot (en les classant par ordre de richesse de rimes) ; — produire un système de phonétisation d’un nouveau mot.


Le fichier Lexique382.csv (issu du projet http://www.lexique.org/telLexique.php) donne pour chaque mot fourni :

   — sa syllabisation

   — sa phonétisation

   — la syllabisation de sa phonétisation


Les quatre champs sont séparés par une tabulation. Attention, il est possible que le fichier comporte quelques erreurs (que vous devrez détecter).
