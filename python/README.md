# sortv1.py
Einfach Sortierung mit list.sort(), der standard Implementation von Python,
welche Timsort benutzt, eine hybride Stable Sort basierend auf Mergesort und Insertion sort. Die Laufzeit ist O(n * log(n)).
Die Liste mit Zahlen wird mit dem modul random, also mit pseudorandom Zahlen gefüllt.

Selbst dass sortieren von 100 Millionen Integern geht in Python sehr schnell.
Der großteil der Laufzeit des Programs verfällt sogar auf die Generierung der Zahlen zum sortieren.
Insgesamt braucht der Code ca 16s, davon 9.4 Generierung und 5.6 Sortierung bei einem Verbraucht von ca. 511MB RAM.
Wie zu erwarten ist die Implementation der sort() Funktion in Python schon sehr gut. 
