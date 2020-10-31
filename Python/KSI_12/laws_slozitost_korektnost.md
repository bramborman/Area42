# Složitost algoritmu `sort(list)`
Algoritmus využívá několika cyklů, které ale nikdy nejsou vnořené a ani se v nich nevolají operace s jinou než konstantní složitostí. Složitost algoritmu je tudíž lineární.

# Korektnost algoritmu `sort(list)`

**Vstupní podmínka:** `list` je list, který obsahuje položky typu `tuple`, v nichž je uloženo nezáporné číslo (`int`) - pořadí a text (`string`) - obsah.

**Výstupní podmínka:** list stringů ze vstupního listu obsahující text z tuplů seřazený podle jejich pořadí.

Funkce `sort` určitě skončí, protože obsahuje dva konečné cykly `for`, které jen prochází všechny položky listu a jeden cyklus `while`, který také určitě skončí, protože proměnná `j`, která je porovnávána s nezápornou délkou listu, je postupně zvětšována pokaždé, když je `i` nalezeno jako jeden z klíčů slovníku `counts`, kde jsou klíčem nezáporná čísla.

## Invariant
První cyklus `for` získá počet každého pořadí - počet výskytů každého čísla určujícího pořadí slova.

Druhý cyklus vytvoří slovník obsahující posunutí pro každé nové pořadí.

Třetí cyklus podle pořadí ve slovníku seřadí položky z listu do výsledného listu.