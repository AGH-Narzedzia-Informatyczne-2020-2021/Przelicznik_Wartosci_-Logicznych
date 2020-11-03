# Projekt_kalkulator_wartosci_logicznych 


### O projekcie

Projekt ma w zasadzie proste zadanie. Na podstawie zadanej mu formuły logicznej program wygeneruje tabele prawdy z wyliczonymi
wartościami logicznymi (0,1). Program ten ma zadanie ułatwić sprawdzanie spełnialności formuł z dużą ilością zmiennych, gdyż rysuje całą tabelke
za użytkownika. Dodatkowo na samym końcu będzie można zobaczyć ilość 0 i 1 ostatecznego rozwiązania formuły żeby nie musieć przeglądać całej masy przypadków
Cały program działa w klimacie lat 80/90 gdyż wszystko wykonuję się w konsoli, aby użytkownik mógł 
poczuć się jakby przeniosł się w czasie (back to good old days :+1: )

### Technologie

Za zadanie nasz team pzyjął sobie napisanie programu w C++ ( między innymi dlatego że narazie jest u nas przeważający )

<details><summary>Docelowy sposób użycia</summary>
<p> 

1. Użytkownik korzystający z programu określa nazwę swoich zmiennych logicznych dodając wybrane przez siebie litery
2. Następnie wprowadza daną formułę logiczną oznaczając każdą "podformułę" w **oddzielnych(!)** nawiasach
3. Wynik działania ukaże się użytkownikowi za pomocą tabeli prawdy, która uwzględni wszystkie możliwe kombinacje.

</p>
</details>
***

### Znaki wykorzystywane w programie przy wprowadzaniu formuł

Operator logiczny | Odpowiednik w programie
------------------|------------------------
koniunkcja| /\
alternatywa| \\/
implikacja| =>
równoważność| <=>
negacja|~


### Sposób wprowadzania formół logicznych. 

Urzytkownik wprowadza wormułę według następującej instrukcji. 
1. "Otwiera" nawias "okrągły" ( );
2. Zapisuje dwie przesłanki (zmienne logiczne) lub dwie watrości logiczne rozdzielone odpowiednimi znakami symbolizującymi operacje logiczne (patsz tabela powyżej);
3. zamyka nawias;
4. w razie potrzeb wprowadzenia dłuższej formuły logicznej urzytkownik może zagnieżdzać nawiasy, należy jednak pamiętać, że program nie zadzaiła poprawnie jeżeli liczba jeden z nawiasów nie zostanie zamknięty lub jeżeli w nawiasie znajdują się więcej niż dwie przesłanki.

Przykłady poprawnych formół pryjmowanych przez program:
Zapis matematyczny | zapis w programie
-------------------|-------------------
a ∧ b | (a/\b)
a ⟹  (b ∨ c) | (a=>(b\\/c))
(a ⟺ b) ∧ ((c⟹d) ∨ (e ∧ f))  | ((a<=>b)/\((c=>d)\\/(e/\f)))
