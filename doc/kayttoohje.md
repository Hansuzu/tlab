## Käyttöohje


./test.sh kääntää yksikkötestit ja ajaa ne. (cxxtest)

Muu compilaus: make


### Substring-brute:
Kansiossa bin/substring on brutetestaaja substring-kyselyille. (suffixalgo on 
suffiksipuulla toteutettu isSubstring-kyselyihin vastaaminen, brute vastaa samoihin
kyselyihin käyttäen std::substring-funktiota)

Kansiossa olevat python2-scriptit testaavat, tuottavatko ohjelmat samat tulosteet.
Skripti gener.py generoi testin, skripti substring_brute_tester.py ajaa silmukassa 
ohjelmia gener.py, suffiks-algo-ohjelmat ja brute ja tarkastaa, että suffixalgo
-ohjelmien ja bruten tulosteet ovat samat.


### Visualizer
Kansiossa bin/visualize on ohjelma, joka lukee merkkijonon ja piirtää siitä suffiksipuun
tiedostoon tree.png

### Speedtest
Kansiossa bin/speedtest on nopeuden testaamisen työkalut. Python-scriptit ajavat testit. (kestää melko kauan)

### LCS
bin/LCS/lcs on LCS:n suffiksipuulla ratkaiseva ohjelma.
Ohjelma lukee syötteenä merkkijonojen lukumäärän ja merkkijonot, 
tulostaa pisimmän yhteisen merkkijonon pituuden ja erilaiset
tämän pituiset merkkijonot.

Samassa kansiossa on myös samantapainen brutetestaaja kuin substring-kansiossa.