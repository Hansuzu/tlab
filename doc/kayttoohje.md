## Käyttöohje



./test.sh kääntää yksikkötestit ja ajaa ne. (vaatii cxx test -asennuksen. esim. sudo apt install cxxtest)

Muut toiminnot: make

bin-kansiossa voi ajaa käännettjä ohjelmia



# Substring-brute:
Kansiossa bin/substring on brutetestaaja substring-kyselyille. (suffixalgo on suffiksipuulla toteutettu isSubstring-kyselyihin vastaaminen, brute vastaa samoihin kyselyihin käyttäen std::substring-funktiota)

Kansiossa olevat python2-scriptit testaavat, tuottavatko ohjelmat samat tulosteet.
gener.py generoi testin
substring_brute_tester.py ajaa silmukassa ohjelmia gener.py, suffixalgo ja brute ja tarkastaa, että ohjelmien suffixalgo ja brute tulosteet ovat samat.



