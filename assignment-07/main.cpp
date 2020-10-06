#include "fraction.hpp"
#include <iostream>
#include <string>

using namespace std;

void print(const string &text, const Fraction &broek) {
  cout << text << broek.numerator << " / " << broek.denominator << endl;
}

/*
 * Oppgave 1
 * a) Lag funksjoner slik at vi kan skrive fraction1 – 5 og 5 – fraction1. Utvid main.cpp slik at du får prøvd dette. Hint: Den ene funksjonen kan ikke være en medlemsfunksjon.
 * b) Teori: Forklar hvordan 5 - 3 - fraction1 - 7 - fraction2 blir tolket. Hvilke versjoner av operatoren - blir brukt?
 */


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

}
