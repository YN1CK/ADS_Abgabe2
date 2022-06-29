# Backtracking Algorithmus
---
## Zustände
Die Zustände des Rucksackproblems umfassen alle möglichen Kombinationen von Gegenständen (kartesisches Produkt). Beispiel:
((15, 23), (13, 7), (8, 14), (4, 16), (18, 15))

## Mögliche Zustände
Möglich sind all die Zustände, bei welchen die Summe der Gewichte unter 30 liegt. Alle anderen Zustände sind nicht valide. Der Algorithmus sollte also immer abbrechen, sobald diese Grenze überschritten ist. 

## Bestmöglicher Zustand
Der bestmögliche Zustand ist der Zustand mit dem höchsten Wert. Hier ergibt sich eine weitere Abbruchbedingung: Diese greift, sobald ein Zustand unter dem aktuellen Höchstwert liegt.

Da logischerweise Gegenstände enthalten sein müssen um einen Wert zu besitzen, kann der Fall Null ausgelassen werden.

## Zustandsveränderung / Zählweise
Die Indices werden hochgezählt. Es muss einen Weg geben um sowohl die Reihenfolge, als auch die Menge an Objekten definiert sein.

Jeder Gegenstand ist entweder da, oder nicht da -> binär

Für 2 Objete würden dann 4 Optionen in Frage kommen:

00 kein Objekt (Ausschlusskriterium)

01 Objekt 2 allein

10 Objekt 1 allein

11 Beide Objekte

=> Es ergeben sich zwei optionale Fälle:

- Fall Objekt im Rucksack:

    Das Objekt wird in den Rucksack gepackt. Der neue Zustand wird evaluiert.

- Fall Objekt nicht im Rucksack:

    Das Objekt wird ausgelassen und der neue Zustand evaluiert. Anschließend werden rekursiv beide Möglichkeiten für alle Folgegegenstände geprüft.

Jeder Zustand wird nur untersucht, solange er sowohl valide, als auch rentabel ist.

## Abbruchbedingungen
### 1. Abbruch nach Gewicht
Der Algorithmus soll abbrechen, wenn   $ \sum Gewichte > 30 \quad OR \quad Gewicht = 0$.

### 2. Abbruch nach Wert
Wenn der Wert eines Zustands unter dem aktuellen Bestwert liegt und keine Möglichkeit mehr besteht _(Frage: Wie ermitteln?)_ den Bestwert zu übertreffen, dann kann der Algorithmus den nächsten Zustand prüfen.

Ggf: Wenn möglich, könnte der Algorithmus sogar vollständig terminieren, wenn ein Wert erzielt wurde, der als Bestwert angesehen werden kann (bsp: $ \sum Werte = Zustandswert $).

---

# Reverse String Algorithm
## Schnellste Umsetzung
Um möglichst schnell den String umzukehren, sollten möglichst wenige Felder angesprochen werden und in jeder Iteration möglichst viele Elemente zu sortieren.

### Rotieren von Zeichen
Die einzelnen Zeichen werden an ihre neue Position _geschoben_. Die Komplexität hierbei beträgt $ n \in O(n^2) $.

### Tauschen zweier Elemente
Die schnellere Alternative ist die Vertauschung von gegenüberliegenden Elementen im String. Dabei wird über $ \frac{n}{2} $ Felder von vorne und hinten Iteriert.

## Komplexität nach Elementen
Die Komplexität nach Elementen beträgt $ O(n) $. Die Komplexität könnte jedoch auch mit $ O(\frac{n}{2}) $ beschrieben werden.

