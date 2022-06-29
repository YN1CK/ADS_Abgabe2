# Allgemeine Build-Anweisungen
Die Programme Rucksack (Aufgabe 1/2) und Reverse (Aufgabe 3) haben je ein eigenes Verzeichnis.
Die Programme können mit make und dem gcc gebaut werden. Jedes Programm hat eine eigene Makefile im zugehörigen Unterverzeichnis.


## Beschreibung der beiden Makefiles
### ./Rucksack/Makefile
|Regel|Beschreibung|
|---|---|
|Rucksack| baut das Programm Rucksack aus den Quell- und Headerdateien|
|run|baut ggf. das Programm, führt das Programm und bei Erfolg anschließend _make clean_ aus|
|check|baut das Programm und räumt anschließend auf => dient zur Prüfung des Codes auf Fehler und Warnungen|
|archive|erstellt ein Archiv aus dem aktuellen Verzeichnis|
|clean|löscht alle Objektdateien und das Programm|

### ./Reverse/Makefile
|Regel|Beschreibung|
|---|---|
|Reverse| baut das Programm Reverse aus den Quell- und Headerdateien|
|run|baut ggf. das Programm, führt das Programm und bei Erfolg anschließend _make clean_ aus|
|check|baut das Programm und räumt anschließend auf => dient zur Prüfung des Codes auf Fehler und Warnungen|
|archive|erstellt ein Archiv aus dem aktuellen Verzeichnis|
|clean|löscht alle Objektdateien und das Programm|

## Beschreibung der Algorithmen
### backPacking: Rucksack wird mittels Backtracking gepackt
Der Algorithmus iteriert rekursiv über alle möglichen Optionen.
Dabei wird für jedes Objekt in einer Reihe sowohl die Option _ist enthalten_, als auch die Option _ist nicht enthalten_ und alle resultierenden Zustände einmal geprüft. Immer, wenn ein Zustand besser als der aktuell beste Zustand ist, wird dieser der beste Zustand.

Wenn alle Optionen getestet wurden, wird der beste Zustand zurückgegeben.

### greedyPacker: Rucksack wird einfach schnell bepackt
Der Algorithmus iteriert über die Objekte. Das jeweils erste Objekt, dass von der Kapazität passt, wird eingefügt. Nun wird solange weiter rekursiv das jeweils erste Objekt eingefügt, bis keines mehr passt. Anschließend werden diese Objekte zurückgegeben.

### String-Umkehrer
Der Algorithmus tauscht den Character am gegebenen Index mit dem Charakter im gleichen Index von rechts aus. Anschließend wird rekursiv der nächsthöhere Index getauscht, bis der Index höher als der rechtsseitige _Gegenindex_ ist.