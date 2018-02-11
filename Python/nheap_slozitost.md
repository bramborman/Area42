# Složitost operací

## Metoda `__init__`

Metoda je naimplementovaná stejným způsobem, jak v binary heap, tudíž je ze stejného důvodu i stejně časově náročná (lineárně).

## Metoda `extract_max`

Metoda má stejnou složitost jako metoda `__heapify`, protože je to jediná operace s jinou, než konstantní složitostí volaná v této metodě.

## Metoda `insert`

Metoda má složitost `O(log n)`, jelikož funguje na stejném principu, jako ta v binary heap.

## Metoda `__heapify`

Metoda má složitost `O(log n)`, jelikož funguje na stejném principu, jako ta v binary heap.

## Metody `get_n`,  `get_max`, `size`, `_children`, `_parent`

Všechny tyto metody jsou provedeny v konstantním čase `O(1)`, jelikož neobsahují žádný cyklus, ale prostě jen vrací (někdy vypočítanou) hodnotu.

Metoda `get_max` sice přistupuje k poli, ale přímo pomocí indexu, což je operace provedená v konstantním čase.
