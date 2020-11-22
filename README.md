# Projekt_kalkulator_wartosci_logicznych 


### O projekcie

Projekt ma w zasadzie proste zadanie – na podstawie zadanej mu formuły logicznej program wygeneruje tabelę prawdy z wyliczonymi
wartościami logicznymi (0,1). Program ma ułatwić sprawdzanie spełnialności formuł z dużą ilością zmiennych, gdyż rysuje całą tabelkę
za użytkownika. Dodatkowo na samym końcu będzie można zobaczyć ilość 0 i 1 ostatecznego rozwiązania formuły, żeby nie musieć przeglądać całej masy przypadków.
Cały program działa w klimacie lat 80/90, gdyż wszystko wykonuję się w konsoli. Użytkownik będzie mógł 
poczuć się tak, jakby przeniósł się w czasie (back to good old days :+1: )

### Technologie

Za zadanie nasz team przyjął sobie napisanie programu w C++ (między innymi dlatego, że narazie jest u nas przeważający)

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


### Sposób wprowadzania formuł logicznych. 

Użytkownik wprowadza formułę według następującej instrukcji : 
1. "Otwiera" nawias "okrągły" ( );
2. Zapisuje dwie przesłanki (zmienne logiczne) lub dwie wartości logiczne rozdzielone odpowiednimi znakami symbolizującymi operacje logiczne (patrz tabela powyżej);
3. zamyka nawias;
4. w razie potrzeb wprowadzenia dłuższej formuły logicznej użytkownik może zagnieżdżać nawiasy, należy jednak pamiętać, że program nie zadziała poprawnie jeżeli liczba jeden z nawiasów nie zostanie zamknięty lub jeżeli w nawiasie znajdują się więcej niż dwie przesłanki.

Przykłady poprawnych formuł przyjmowanych przez program:
Zapis matematyczny | zapis w programie
-------------------|-------------------
a ∧ b | (a/\b)
a ⟹  (b ∨ c) | (a=>(b\\/c))
(a ⟺ b) ∧ ((c⟹d) ∨ (e ∧ f))  | ((a<=>b)/\((c=>d)\\/(e/\f)))

### Przykładowy OUTPUT 

```C
| q/\p | p=>q |
+------+------+-
|  0   |   1  |
|  0   |   0  |
|  0   |   0  |
|  0   |   0  |
|  1   |   1  |
|  1   |   1  |
|  0   |   1  |
|  1   |   1  |
|  0   |   0  |
```
<details><summary>Szybkie Gisty</summary>
<p> 

##### Bartłomiej Wajdzik
* [Przypadki](https://gist.github.com/Zogfryt/1521f2301b5bbdf4b60950515b9e61d0)
* [Sklejka wersja Zog](https://gist.github.com/Zogfryt/23f0ea2bc8e43ef6a3c2e9534acbe2d9)

##### Kamil Stecyk
* [moja implikacja i alter w](https://gist.github.com/kamilstecyk/f676d7dd183b99fbb8a4502050c4eea4)
* [aktualizacja readme](https://gist.github.com/kamilstecyk/1a2b3450930c0d508759075e5369ac8a)

##### Filip Kubiś
 * [Manual](https://gist.github.com/Kubi5/f9dba10459386c77b13612d97696926f#file-gistfile1-txt)
 * [Równoważność](https://gist.github.com/Kubi5/cd2d2ccdcd0b7bb1f22466bb6073b28c#file-gistfile1-txt)
 
##### Maja Gurdek
* [O nas](https://gist.github.com/majagurdek/36efdfdb5617565f366e4250db10ce35#file-o-nas)
* [Koniunkcja](https://gist.github.com/majagurdek/6fd19eb0f97e2534d29e1beb82173890#file-koniunkcja)
  
  
  
  
  </p>
</details>
