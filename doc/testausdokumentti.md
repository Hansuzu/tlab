# Testausdokumentti

## Toteutetut tietorakenteet ja niiden toimivuuden testaus

Vector, 
FastSet, 
UkkonenTree - Edget Vectorissa
UkkonenTree - Edget Vectorissa järjestystä ylläpitäen
UkkonenTree - Edget O(m) taulukossa
UkkonenTree - Edget FastSetissä
UkkonenTree - Edget std::setissä (vertailua varten)

Luokkia on yksikkötestattu. Lisäksi Ukkosen algoritmin toimivuutta on tutkittu satunnaisilla syötteillä substring-kyselyillä.

Yksikkötestit ovat test/ -kansiossa.

Satunnaistestaus on kansiossa bin/substring. Python2-skripti tester.py ajaa satunnaistestejä silmukassa. Skriptiä gener.py käytetään testien generoimiseen.

Satunnaistestit generoidaan generoimalla ensin satunnainen merkkijono. Sen jälkeen generoidaan joukko toisia merkkijonoja valitsemalla alkuperäisestä merkkijonosta satunnainen substring ja vaihtamalla siitä 0-3 merkkiä. Tämän jälkeen testataan jokaisella ohjelmalla, vastaako se oikein kyselyyn, mitkä merkkijonot ovat alkuperäisen merkkijonon substringejä. Vastaus vahvistetaan vertailemalla tulostetta std::substring -funktiota käyttävän ohjelman tulosteeseen.


## Nopeuden testaaminen

Vertasin eri toteutuksia toisiinsa mittaamalla time-komennolla aikaa satunnaisesti generoidun merkkijonon suffiksipuun muodostamiseen. Kansiossa bin/speedtest on python-skriptit, jolla mittasin suoritusajat.

Taulukko aikavaatimuksista. Vertailussa mukana olevan std::setin vaatimukset ovat samoja kuin FastSetin.

|                      | Vector        | Vector, järjestystä ylläpitäen | Taulukko[AAKKOSTON KOKO] | FastSet    |
| -------------------- | ------------- | ------------------------------ | ------------------------ | ---------- |
| Edgen haku           | O(m)          | O(log m)                       | O(1)                     | O(log m)   |
| Edgen lisäys         | O(m)          | O(m)                           | O(1)                     | O(log m)   |
| Noden lisäys         | O(1)          | O(1)                           | O(m)                     | O(1)       |
| Kokonaisaikavaatimus | O(m*n)        | O(m*n)                         | O(m*n)                   | O(n log m) |
| Muistinkäyttö        | O(n)          | O(n)                           | O(m*n)                   | O(n)       |


Kaaviossa mitatut ajat, kun syötteen koko on 2000000, aakkoston kokoa muutetaan. X-akselilla on logaritminen skaalaus.

![2000000](https://github.com/Hansuzu/tlab/tree/master/doc/alphabet.png)

Punainen viiva: Vector
Sininen viiva: FastSet
Syaani viiva: Vector järjestystä ylläpitäen
Violetti viiva: Taulukko
Vihreä viiva: std::set

Tulosten perusteella pienellä aakkostolla (m<30) Taulukko-ratkaisu on nopein. 

## LCS

