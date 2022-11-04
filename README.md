# Projekt Sortieren
In diesem Projekt beschäftige ich mich damit, wie man in verschiedenen Sprachen möglichst schnell eine Liste mit
1/10/100 Million positiven 32bit Integern (0 - 4,294,967,295) sortieren kann. Dabei ist das Ziel, den schnellsmöglichen Code in diesen Sprachen zu
schreiben und zu dokumentieren, wie man immer weiter optimieren kann und welche Ansätze die Geschwindigkeit erhöhen.
Da der Speicher eines Computers begrenzt ist, lässt sich die Anzahl der Integer allerdings nicht unbegrenzt erhöhen, weshalb
je nach genauer Implementation die Anzahl varieren muss.
Betrachtet werden kann dabei immer der Speicherbedarf und es lässt sich auch überlegen, wie viele Threads bzw. Kerne der CPU genutzt werden.
Auch die Kontrolle der Variablen bei der Laufzeit sind wichtig, so zum Beispiel last beim ausführen und die Hardware.