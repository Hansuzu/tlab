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

Taulukko aikavaatimuksista.

|                      | Vector        | Vector, järjestystä ylläpitäen | Taulukko[AAKKOSTON KOKO] | FastSet      | std::set   |
| -------------------- | ------------- | ------------------------------ | ------------------------ | ------------ | ---------- |
| Edgen haku           | O(m)          | O(log m)                       | O(1)                     | O(log^2 m)   | O(log m)   |
| Edgen lisäys         | O(m)          | O(m)                           | O(1)                     | O(log^2 m)   | O(log m)   |
| Noden lisäys         | O(1)          | O(1)                           | O(m)                     | O(1)         | O(1)       |
| Kokonaisaikavaatimus | O(m*n)        | O(m*n)                         | O(m*n)                   | O(n log^2 m) | O(n log m) |
| Muistinkäyttö        | O(n)          | O(n)                           | O(m*n)                   | O(n)         | O(n)       |


Kaaviossa mitatut ajat, kun syötteen koko on 2000000, aakkoston kokoa muutetaan. X-akselilla on logaritminen skaalaus. Aakkoston kokona on testattu tässä eri 2:n potensseja. Kuvaan on otettu joka koolta viiden kerran keskiarvo. Testit on suoritettu satunnaisessa järjestyksessä, jolloin koneen suoritusnopeuden vaihtelun vaikutus tasoittuu.

![2000000](https://raw.githubusercontent.com/Hansuzu/tlab/master/doc/alphabet.png)

Punainen viiva: Vector  
Sininen viiva: FastSet  
Syaani viiva: Vector järjestystä ylläpitäen  
Violetti viiva: Taulukko  
Vihreä viiva: std::set  

Tulosten perusteella pienellä aakkostolla (m<20) Taulukko-ratkaisu on nopein. Aakkoston koon ollessa n. välillä 20<m<200 Järjestemätön Vector on nopein. Aakkoston koon kasvaessa muutamasta sadasta muutamaan tuhanteen järjestetty Vector on nopein. Siitä eteenpäin FastSet ja std::set ovat selvästi nopeampia kuin muut.

Violetti viiva loppuu kesken, koska suuremmalla aakkoston koolla muistinkäyttö kasvaisi liian isoksi.

Kuvassa näkyy, miten järjestettyä vectoria, FastSet:iä ja std::set:tiä käyttävät implementaatiot toimivat nopeammin, kun aakkoston koko kasvaa muutamasta tuhannesta muutamaan kymmeneen tuhanteen. Tämä johtunee siitä, että kun aakkoston koko on suuri suhteessa merkkijonon kokoon, puusta tulee matala ja leveä, ja edgejen pituudet (lehtiin meneviä edgejä tietysti lukuunottamatta) ovat lyhyitä. Tällöin tarvittavien edgejen splittausten määrä vähenee ja suurempi osa tiloista on jonkin noden kohdalla, jolloin siirtymien olemasasolon tutkiminen on nopeampaa.

## LCS

