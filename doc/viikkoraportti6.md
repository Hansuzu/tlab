## Viikkoraportti 6

Tällä viikolla tein ensin uuden toteutuksen edgejen tallennukselle, ja sen
jälkeen tein useamman vaihtoehtoisen edgejen tallennuksen. Tein useamman
eri toteutuksen ja tutkin niiden tehokkuutta.

Aikaisemmassa edgejen tallennuksessa m-kokoiseen taulukkoon oli haittapuolena
suuri muistinkäyttö O(n*m) ja template-säätö. Nyt toteutin edgejen tallennuksen
erilaisiin rakenteisiin, jotka vähentävät muistinkäytön O(n)-tasolle ja mahdollistavat
suffiksipuun luomisen ilman, että aakkoston kokoa on määrätty etukäteen.

Aakkoston koon ollessa pieni aikaisempi toteutus on tehokkaampi, mutta aakkoston kasvaessa
muutamaan kymmeneen, muut tavat ovat parempia. Kirjoitin näistä tarkemman analyysin testaus-
ja toteutus-dokumentteihin.

Korvasin myös std::vectorin omalla Vector-luokalla ja lisäsin oman "FastSet" -tietorakenteen,
näiden lisäksi koodasin myös Bitsetin (LCS:sää varten) ja Pairin (korvaamaan std::pair, mitä
joissain kohdissa käytin)

Lisäsin projektiin myös makefile:n ja muokkasin rakennetta. Yksikkötestit compilataan
edelleen .sh -scripteillä.

Lisäsin ohjelmaan Longest Common Substring -algoritmin, joka toimii O(n*k) - ajassa, missä
n on merkkijonon kokonaispituus ja k eri merkkijonojen lukumäärä.

Seuraavaksi jatkan dokumentaation kirjoittamista, parantelen testausta ja selvitän, saanko
yksikkötestien coveragen jotenkin helpolla tavalla näkyville.