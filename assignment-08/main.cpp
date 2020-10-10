#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
using namespace std;

/*
 * Opgpave 1 Lag en funksjonstemplate som finner ut om to verdier er like
 */
template <typename Type>
bool equal(Type a, Type b){
    std::cout << "Template utageve" << std::endl;
    return a==b;
}


/*
 * Lag en spesialutgave for doubl,
 * Anta at to slike verdier betraktes som like dersom forskjellen mellom dem er mindre enn for eksempel 0.00001.
 */
bool equal(double a, double b){
    std::setprecision(5);
    std::cout << "Spesialisert double utgave" << std::endl;
    double limit =0.00001;
    if(std::abs(a-b)<=limit){
        return true;
    }

    return a==b;



}


/*
 * Oppgave 2
 *
 * Du skal lage en template-klasse for par. De to elementene som inngår i et par kan være av forskjellig type. Klassen skal tilby følgende:
 *      En konstruktør som tar begge elementene som argumenter.
 *      En operator for å legge sammen to par. Den skal lages ved elementvis summering, se eksemplet nedenfor.
 *      En operator for å finne ut om et par er større enn et annet par. Her skal du sammenligne summen av elementene i hvert enkelt par, se eksemplet nedenfor.
 * Forutsett at det du måtte trenge av ytterligere versjoner av operatorene + og > eksisterer. Hvilke forutsetninger gjør du?
 *
 *
 */

//definerer 2 forkjellige typer
template <typename type01,typename type02>
class Pair{
public:
    Pair(type01 variabel01, type02 variabel02):first(variabel01),second(variabel02){};
    type01 first;
    type02 second;

    //En operator for å legge sammen to par. Den skal lages ved elementvis summering
    //this + pair
    Pair operator+(Pair pair){
        return (Pair(first+pair.first,second+pair.second));
    }


    //En operator for å finne ut om et par er større enn et annet par. Her skal du sammenligne summen av elementene i hvert enkelt par
    bool operator>(Pair pair){
        return sum()>pair.sum();
    }

    auto sum(){
        return first+second;
    }
};





int main() {

    // oppgave 1
    bool resultat=equal("Dette er en test","Dette er en test");
    if(resultat){
        std::cout << "Verdiene er like!" << std::endl;
    } else{
        std::cout << "Verdiene er IKKE like!" << std::endl;
    }



     resultat=equal(1,1.0000001);
    if(resultat){
        std::cout << "Verdiene er like!" << std::endl;
    } else{
        std::cout << "Verdiene er IKKE like!" << std::endl;
    }



    // opgpave 2

    Pair<double, int> p1(3.5, 14);
    Pair<double, int> p2(2.1, 7);
    cout << "p1: " << p1.first << ", " << p1.second << endl;
    cout << "p2: " << p2.first << ", " << p2.second << endl;

    if (p1 > p2)
        cout << "p1 er størst" << endl;
    else
        cout << "p2 er størst" << endl;

    auto sum = p1 + p2;
    cout << "Sum: " << sum.first << ", " << sum.second << endl;
    return 0;
}










