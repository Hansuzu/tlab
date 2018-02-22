# Toteutusdokumentti

Projektissa on toteutettu Ukkosen algoritmi ja toteutettu Ukkosen algoritmilla toimiva ratkaisu Longest common substring -ongelmaan.

Lisäksi työssä on toteutettu itse Vector (vector.h automaattisesti kasvava taulukko) ja FastSet (fastset.h nopea lisäys ja haku) -tietorakenteet.

## Ukkosen algoritmi

Toteutin Ukkosen algoritmin tallentaen edget eri tavoilla. Mittasin eri toteutusten tehokkuutta eri kokoisilla aakkostoilla.

Tässä taulukko työssä toteutetuista edgejen tallennustavoista .

|                      | Vector        | Vector, järjestystä ylläpitäen | Taulukko[AAKKOSTON KOKO] | FastSet      |
| -------------------- | ------------- | ------------------------------ | ------------------------ | ------------ |
| Edgen haku           | O(m)          | O(log m)                       | O(1)                     | O(log^2 m)   |
| Edgen lisäys         | O(m)          | O(m)                           | O(1)                     | O(log^2 m)   |
| Noden lisäys         | O(1)          | O(1)                           | O(m)                     | O(1)         |
| Kokonaisaikavaatimus | O(m*n)        | O(m*n)                         | O(m*n)                   | O(n log^2 m) |
| Muistinkäyttö        | O(n)          | O(n)                           | O(m*n)                   | O(n)         |



### Implementaatioiden



##  Longest common substring Ukkosen algoritmilla.

