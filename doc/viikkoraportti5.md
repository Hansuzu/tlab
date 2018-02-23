## Viikkoraportti 5

Tällä viikolla tein ohjelmalle alustavia suorituskykytestausta.

Käytin ohjelmaa, joka lukee syötteenä merkkijonon ja muodostaa siitä suffiksipuun käyttäen aakkoston kokona kokoa 30.
Generoin syötteiksi eri pituuksilla satunnaisia merkkijonoja ja mittasin rakennukseen kulunutta aikaa komennolle time.
Likiarvoja suoritusajasta:
Merkkijonon pituus, ~aika sekunteina time-komennon real-arvo
100000, 0.05
200000, 0.09
500000, 0.26
1000000, 0.57
2000000, 1.2
4000000, 2.6
8000000, 5.3
16000000, 12

Implementaationi ei vaikuta erityisen nopealta, koska miljoonan kokoisen merkkijonon käsittelyyn menee yli puoli sekuntia ja kahden miljoonan kokoiseen yli sekunti. Lisäksi ohjelma hidastuu merkittävästi jos aakkostoa kasvaa. (Luultavasti pääasiallinen syy tähän on se, että Nodet vievät nykyisessä implementaatiossa aakkoston koon suhteen lineaarisen määrän muistia ja jatkuva new-komennon kutsuminen puuta kasvattaessa on varsin hidasta. Hitauden lisäksi tämä implementaatio vie itse asiassa muistia tarpeettoman paljon - n. puolet nodeista on koko ajan lehtiä, eivätkä ne siksi käytä tätä muistia hyödyksi.) 

Havaitsin, että on melko vaikeaa tehdä hyvää yksikkötestausta tietyille osille puun muodostamista. Aion osittain siksi lisätä brute-force -testaajan, jolla voin testata nopeasti suurelle määrälle (satunnaisesti generoituja) testejä, ratkaiseeko algoritmin puu tietyn merkkijono-ongelman oikein. (Aion testata tätä ensin yksinkertaisella substring-testauksella)

Lisäksi pitää selvittää, saanko jotenkin helposti testattua tuolla cxx:llä testien coveragea.

[Longest common substring -ongelman](https://en.wikipedia.org/wiki/Longest_common_substring_problem) ratkaiseminen suffiksipuulla näyttäisi melko mielenkiintoiselta. Ajattelin, että ensi viikolla voisin alkaa tekemään tuota.

Käytän tällä hetkellä std-vectoria suffiksipuussa olevan merkkijonon tallentamiseen. Merkkijonon tallentaminen ei ole kovin olennainen osa algoritmia, mutta voisin silti korvata tuon jollain omalla rakenteella.