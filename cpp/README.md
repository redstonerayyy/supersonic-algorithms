# sortv1.cpp
Wie in Python wird auch hier die Standard suche verwendet, also std::sort.
In C++ ist std::sort laut (https://www.geeksforgeeks.org/internal-details-of-stdsort-in-c/)
eine Introsort und nutzt also Quicksort, Heapsort und Insertion sort. Die Laufzeit ist O(n * log(n)).

Compilierung mit `clang++ sortv1.cpp -O3 -march=native -o sortv1` da clang++ gute optimierung hat, O3 beste optimierung verspricht und march=native für CPU extension Features.

Die 1. C++ version braucht ca 105 Ms zur Zahlengenerierung, 907 Ms zum Sortieren und nur 
41MB RAM.

# sortv2.0.cpp
In meiner 2. Implementation nutze ich anstatt einer Quicksort oder Mergesort mit O(n * log(n)) eine Radixsort mit O(n * w), wo w die Anzahl der Stellen der zahlen ist.
Diese erste Implementatin der Radixsort braucht 2.2 Sekunden zum Sortieren und 0.1 Sekunden zum Generieren der Zahlen. Somit ist sie im sortieren langsamer als die Python version und auch langsamer als std::sort.

# sortv2.1.cpp
In this version i want to optimize the radixsort.