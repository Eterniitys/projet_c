# Symphonie

Requirements:
```bash
# Archlinux
pacman -S valgrind flawfinder
pip install --user -r docs/requirements.txt
```

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

Generate documentation:
```bash
make docs
xdg-open docs/html/index.html
```

Run flawfinder:
```bash
make flawfinder
```
