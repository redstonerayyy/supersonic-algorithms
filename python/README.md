# sortv1.py
Einfach Sortierung mit list.sort(), der standard Implementation von Python,
welche Timsort benutzt, eine hybride Stable Sort basierend auf Mergesort und Insertion sort. Die Laufzeit ist O(n * log(n)).
Die Liste mit Zahlen wird mit dem modul random, also mit pseudorandom Zahlen gefüllt.

Selbst dass sortieren von 100 Millionen Integern geht in Python sehr schnell.
Der großteil der Laufzeit des Programs verfällt sogar auf die Generierung der Zahlen zum sortieren.
Insgesamt braucht der Code ca 16s, davon 9.4 Generierung und 5.6 Sortierung bei einem Verbraucht von ca. 511MB RAM.
Wie zu erwarten ist die Implementation der sort() Funktion in Python schon sehr gut. 

# sortv2.x.py
Eine eigene Implementation von Quicksort in Python schreiben. 
Erster Versuch, Generation time wie zu erwarten gleich, Sortierzeit
allerdings 44.6 Sekunden, also deutlich langsamer.
Nun wird der Code mit numba und numpy verbessert mit numba und numpy.
Ein numpy aray zu verwenden und numpy.random.randint zur generierung der
zufälligen Liste verringert die Generierungszeit auf 0.05 Sekunden
und die Sortiertzeit auf 1.8 Sekunden, somit deutlich schneller als der naive Python
sort approach ohne die Optimierungen.
Nun optimiere ich den Code noch weiter.
Das ändern der Swap funktion und der Pivot element berechnung mach keinen unterschied,
wahrscheinlich wird das in der Compilierung zu etwas ähnlichem.

python -m compileall <file> sorgt nicht für schnellere laufzeit

Nun teste ich auch nochaml compileall mit der v1. Diese wird daruch auch nicht
schneller, wahrscheinlich

Im vergleich ist somit diese Version bei der Generierung 5x so langsam wie
wie die v1 bei cpp und nur halb so langsam beim sortieren.

