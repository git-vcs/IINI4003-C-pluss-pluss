#include "fraction.hpp"
#include <iostream>
#include <string>
#include "Set.hpp"

using namespace std;

void print(const string &text, const Fraction &broek) {
  cout << text << broek.numerator << " / " << broek.denominator << endl;
}

/*
 * Oppgave 1
 * a) Lag funksjoner slik at vi kan skrive fraction1 – 5 og 5 – fraction1. Utvid main.cpp slik at du får prøvd dette. Hint: Den ene funksjonen kan ikke være en medlemsfunksjon.
 * b) Teori: Forklar hvordan 5 - 3 - fraction1 - 7 - fraction2 blir tolket. Hvilke versjoner av operatoren - blir brukt?
 *
 * # er satt for å kunnne referere til opperasjoneen.
 *   #1  #2          #3   #4
 *  5 - 3 - fraction1 - 7 - fraction2
 * #metoder:
 * 1: int -
 * 2: - fraction
 * 3: fraction -
 * 4: - fraction
 *
 */


/*
 * Oppgave 2
 * å skrive ut en mengde
 */

void print(const Set set) {
  for (int i = 0; i <(int)set.tall.size() ; ++i) {
      cout<<set.tall[i]<<"\n";
  }
  cout<<"\n";
}

int main() {
  Fraction a(10, 20);
  Fraction b(3, 4);
  Fraction c;
  c.set(5);
  Fraction d = a / b;

  print("a = ", a);
  print("b = ", b);
  print("c = ", c);
  print("d = ", d);

  b += a;
  ++c;
  d *= d;

  print("b = ", b);
  print("c = ", c);
  print("d = ", d);

  c = a + b - d * a;
  c = a-c;

  print("c = ", c);

  if (a + b != c + d)
    cout << "a + b != c + d" << endl;
  else
    cout << " a + b == c + d" << endl;
  while (b > a)
    b -= a;
  print("b = ", b);

    Fraction fraction1(2, 8);
    print("fraction1-2 ", fraction1-2);
  Fraction fraction2(1, 2);
    print("4- 1/2: ", 4-fraction2);



    Set set;
    set + 1;
  set + 2;
  set + 3;

  Set set2;
    set2 + 3;
  set2 + 4;
  set2 + 5;
  set2 + 6;

  //print(set);
    Set test3=set2.getUnion(set);
    print(test3);
    set2=test3;
  print(test3);



    return 0;
}
