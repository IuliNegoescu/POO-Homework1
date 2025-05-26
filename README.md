Negoescu Iulian Andrei - 321-AB

Sistemul de operare: macOS
IDE: Visual Studio Code

                                                    -Clasa Produs-


Clasa Produs este folosită pentru a reprezenta un produs din stoc. Fiecare produs are un ID unic, o denumire, un preț și o cantitate.
Membri de date:

static int nextId: Un contor static care se ocupă de generarea ID-urilor unice pentru produse.
const int id: ID-ul unic al produsului. Este constant și nu se schimbă după inițializare.
char denumire[50]: Un șir de caractere pentru denumirea produsului, cu o limită de 50 de caractere.
float pret: Prețul produsului.
int cantitate: Cantitatea disponibilă în stoc.
Constructori:

Produs(): Constructorul implicit care inițializează un produs cu valori de bază. ID-ul este generat automat folosind nextId.
Produs(const int id, const char denumire[50], const float pret, const int cantitate): Un constructor care setează toate detaliile produsului.
Metode:

scadeCantitate(int cantitateScazuta): Scade o anumită cantitate din stoc, având grijă să nu devină negativ.
getId(), getDenumire(), getPret(), getCantitate(): Metode care returnează diferite informații despre produs.
Operatori supraîncărcați:

operator<<: Pentru afișarea unui produs.
operator>>: Pentru citirea detaliilor unui produs.


                                                -Clasa Comanda-


Clasa Comanda reprezintă o comandă plasată de un client și include o listă de produse și data la care a fost făcută.
Membri de date:

int id: ID-ul comenzii.
int zi, luna, an: Data la care a fost făcută comanda.
int nrProduse: Numărul de produse din comandă.
Produs* produse: Un vector dinamic de produse.
Constructori:

Comanda(): Constructor implicit care setează comanda cu valori de bază.
Comanda(const int id, const int zi, const int luna, const int an, const int nrProduse, const Produs* produse): Constructor care inițializează toate detaliile comenzii și copiază produsele într-un vector dinamic.
Destructor:

~Comanda(): Eliberează memoria alocată pentru vectorul de produse.
Operatori supraîncărcați:

operator<<: Pentru afișarea unei comenzi.
operator>>: Pentru citirea detaliilor comenzii.


                                                -Clasa Client-


Clasa Client ține evidența unui client care a făcut o comandă.
Membri de date:

char nume[60]: Numele clientului, limitat la 60 de caractere.
Comanda comanda: Comanda asociată acestui client.
Constructori:

Client(): Constructor implicit care setează numele ca un șir gol.
Client(const char* numeClient, const Comanda& comandaClient): Constructor care inițializează numele clientului și comanda asociată.
Operatori supraîncărcați:

operator<<: Pentru afișarea detaliilor unui client.
operator>>: Pentru citirea datelor unui client.
-Legătura dintre Clase-
Clasele sunt conectate astfel: Produs este clasa de bază care stochează informațiile despre fiecare produs. Comanda gestionează o listă de produse și reprezintă o comandă făcută de un client. Client include detalii despre client și comanda sa. În esență, un Client face o Comanda care conține mai multe Produse.

                                                -main-
Programul începe prin a verifica dacă are toate fișierele de intrare de care are nevoie. Aceste fișiere conțin detalii despre produse și clienți. Dacă lipsește vreun fișier, programul afișează un mesaj de eroare și se închide.

Odată ce fișierele sunt deschise, programul citește datele și creează două fișiere de ieșire: unul pentru comenzile procesate și altul pentru stocul rămas. Acest lucru îi permite programului să salveze totul în mod organizat.

Prima dată, programul citește numărul de produse și alocă memorie pentru un vector în care le stochează. Apoi, parcurge fiecare produs și îl încarcă în memorie, astfel încât să fie gata de utilizare.

Urmează citirea datelor despre clienți. Programul alocă un vector pentru clienți și citește fiecare client și comanda sa. Apoi, scrie toate aceste informații într-un fișier de ieșire, având grijă să adauge spații între comenzi pentru a fi ușor de citit.

Partea principală a programului este procesarea comenzilor. Pentru fiecare client, programul verifică dacă există suficiente produse în stoc pentru a onora comanda. Dacă nu sunt destule, afișează un mesaj de avertizare și trece la următorul produs. Dacă stocul este suficient, scade cantitatea din inventar.

La final, programul scrie stocul rămas în fișierul de ieșire, cu detalii despre fiecare produs. Închide fișierele și eliberează memoria, asigurându-se că totul este în ordine înainte de a se termina.