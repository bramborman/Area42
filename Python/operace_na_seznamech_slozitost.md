# Složitost operací

Všechny funkce (`union`, `intersection` a `relative_complement`) jsou postaveny na velmi podobném principu, proto jejich složitost shrnu na jednom místě.

Funkce používají jediný cyklus (`while`), což je v nich také jediná část kódu s jinou, než konstatní složitostí (konkrétně lineární). Jelikož v daném cyklu není zanořen další cyklus, rekurze a ani operace s lineární nebo horší složitostí, složitost všech funkcí je lineární.

V nejhorším případě je složitost všech funkcí `O(a + b)` kde `a` a `b` jsou délky jednotlivých listů.
