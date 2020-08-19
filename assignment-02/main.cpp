#include <iostream> //innlesning/utlesning
#include <cstdlib>
#include <cstring>

using namespace std; //bruker standard navnerom.

int main() {
// Oppgave 1 A
    cout<<"Oppgave 1 A"<<endl;
    int i = 3;
    int j = 5;
    int *p = &i;
    int *q = &j;
    cout<<"Verdi i: "<<i<<endl;
    cout<<"Adrese i: "<<&i<<endl;
    cout<<"Verdi j: "<<j<<endl;
    cout<<"Adrese j: "<<&j<<endl;
    cout<<"Andressen p peker til: "<<p<<endl;
    cout<<"Verdien som p peker til: "<<*p<<endl;
    cout<<"Andressen q peker til: "<<q<<endl;
    cout<<"Verdien som q peker til: "<<*q<<endl;


    // B
    cout<<"Oppgave 1 B"<<endl;

    //setter verdien til 7 i plassen p peker til, altså i=7
    *p = 7;

    // Legger til til 4 til verdien som q peker til, altså j=5+4=9
    *q += 4;

    // Setter verdien q peker til lik verdien p peker til + 1, altså q= j=> i+1 => 7+1=8
    *q = *p + 1;

    // setter adressen til p lik adressen til q, som betyr at begge peker til samme verdi j=8
    p = q;
    cout << *p << " " << *q << endl;


    //Oppgave 2 - teorioppgave
    cout << "Oppgave 2"<< endl;
    // Vi setter poiterens adresse til NULL
    char *line = nullptr;

    // kopierer en streng inn i line men siden line peker til NULL vi dette betyr at teksten forsvinner eller koden feiler
    //strcpy(line, "Dette er en tekst");


    cout << "Oppgave 3"<< endl;
    /*
     * I denne koden kan du lese utenfor char tabellen siden while-løkken ikke stopper
     * når pointer og har samme verdi som legden på tabellen.
     *
     */

    char text[5];
    char *pointer = text;
    char search_for = 'e';
    cin >> text;


//    while (*pointer != search_for) {
        /*
         * i tillegg setter man alle verdiene i tabellen til e samtidig om man søker.
         */
    //      *pointer = search_for;
    //      pointer++;
    // }





    cout << "Oppgave 4"<< endl;
    int a = 5;

    //B må initialiseres eller settet samtidig som den blir definert hvis den skal bli bruk som en referanse
    //int &b;
    int b;
    int *c;
    c = &b;

    // a og b brukes som en pointer men er definert som variabler
    // *a = *b + *c;
    a = b + *c;

    //b brukes som referanse isteden for variabel
    //&b = 2;g

    b = 2;

    cout << "Oppgave 5"<< endl;
    double number;
    double *peker=&number;
    double &referanse=number;

    cout<<number<<endl;
    cout<<*peker<<endl;
    cout<<referanse<<endl;

}