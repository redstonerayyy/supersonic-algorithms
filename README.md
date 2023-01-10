# Supersonic Algorithms

TL;DR:
This repository shows with examples how to make your code faster with optimizations.

# Ausführen der Programme

Häufig finden sich Makefiles oder zumindest commands in diesen, die ausgeführt werden können.
Es wird empfohlen, Linux zum ausführen zu nutzen.
Bei den Beschrieben Schritten wird davon ausgegangen, dass das Aktualle Arbeitsverzeichnis (cwd) das des Pfades
im Sectionsabschnitt ist.
Zum Äusführen dieses Projektes wird eine aktuelle Version von Python 3.x, z. B. 3.10, benötigt.
Außerdem muss ein C/C++ Compiler an der Commandline verfügbar sein.

## python/src/numbanumpy

Als externes Package muss `numba` mit dem Befehl `pip install numba` installiert werden.
Entweder kann dies in den globalen site-packages geschehen, oder eine Virtuelle Python Umgebung kann erstellt werden.
Anschließend kann man mit `python ../main.py` die Benchmarks starten.

## python/src/cython

Anschließend muss in diesem Ordner eine Virtuelle Python Umgebung erstellt werden.
Als externes Package muss `cython` mit dem Befehl `pip install cython` installiert werden.
Außerdem muss noch `numpy` installiert werden, da sich zum Kompilieren der Python Dateien die NumPy header
`./lib/python3.10/site-packages/numpy/core/include` Befinden müssen, also im lib Ordner der Virtuellen Umgebung in diesem Ordner.
Anschließend müssen die Cython Dateien (Endung .pyx) mit dem Befehl `python setup.py build_ext --inplace` kompiliert werden. Danach muss man nur noch `python main.py` die Tests starten.

## python/src/ctypes

Zuerst müssen die Dateien `fib.cpp` und `quicksort.cpp` in eine Shared Library mit dem Namen `libquick.so` kompiliert werden. Im Makefile findet sich Beispielhaft, wie ich diese kompilierte.
Anschließend, wenn die Libary im gleichen Ordner wie `main.py` vorhanden ist, so lassen sich die Benchmarks
mit `python main.py` starten.

## cpp

Alle Dateien im Ordner `cpp` werden mit CMake kompiliert. Dazu wird ein passender Compiler benötigt sowie CMake.
Beispielhafte Befehle für linux befinden sich im Makefile.
Auf Windows ist es zu empfehlen, Visual Studio zu nutzen, was Unterstützung für CMake bietet,
oder von der Commandline mit `cmake -B ./build -S .` und `cmake --build ./build` die 3 Executables zu bauen.
Dabei ist zu beachten, dass für die Datei `cpp/src/hellofradixsort/terdimann_simple_extension.cpp` eine CPU
mit AVX2 vonnöten ist. Sonst wird es Fatale Fehler bei der Ausführung geben und dass Program wird abbrechen.
Die Ausführebaren Dateien befinden sich an diesen Orten (Pfade je nach Betriebssystem anpassen)

-   cpp/build/main
-   cpp/build/src/datastructures/datastructures
-   cpp/build/src/hellofradixsort/radixhell

# comparison/go

Es wird Go benötigt, um die Datei auszuführen. Evtl. muss man die Go Version in `go.mod` verringern auf die Installierte Version.
Anschließend lässt sich mit `go build .` die Datei bauen. Anschließend muss die Executable `quicksort` ausgeführt werden.

# comparison/java

Es wird eine Version von Java Benötigt (Ich nutze Java 19).
Mit den Befehlen aus der Makefile lässt sich die Java Datei kompilieren und ausführen.
`javac Quicksort.java` und `java Quicksort` sind die Befehle.

# comparison/javascript

Es wird eine Version von NodeJS benötigt. Anschließend muss nur noch `node quicksort.js` in der Commandline eingegeben werden.

# comparison/julia

Es wird Julia benötigt. Anschließend muss nur noch `julia quicksort.jl` in der Commandline eingegeben werden.

# comparison/lua

Es wird Lua benötigt. Anschließend lässt sich mit `lua quicksort.lua` die Datei ausführen.
