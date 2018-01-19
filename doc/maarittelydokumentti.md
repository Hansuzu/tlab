##Määrittelydokumentti

Toteutan suffiksipuun luominen merkkijonolle Ukkosen algoritmilla, ja sen jälkeen erilaisten hakutoimintojen toteuttaminen suffiksipuusta.

Ongelmana on suffiksipuun luominen tehokkaasti. Ukkosen algoritmilla tämä onnistuu myös onlinenä, eli ylläpitämällä koko ajan jo luetun merkkijonon suffiksipuuta samalla kun merkkijonoa luetaan merkki kerrallaan (vasemmalta oikealle).

Ohjelma saa syötteenä merkkijonon, jolle luodaan puu.
Sen jälkeen ohjelma voi tehdä hakuja puuhun.

Tavoitteena on puun luominen O(n) ajassa O(n) tilavaatimuksella.

###Lähteet:
[On-line construction of suffix trees, Esko Ukkonen, 1995](https://www.cs.helsinki.fi/u/ukkonen/SuffixT1withFigs.pdf)

[Suffix tree, wikipedia](https://en.wikipedia.org/wiki/Suffix_tree)

[Ukkonen Suffix Tree Construction, geeksforgeeks.org](https://www.geeksforgeeks.org/ukkonens-suffix-tree-construction-part-1/)
