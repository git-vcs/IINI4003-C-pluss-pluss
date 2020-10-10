#include <iostream>

/*
 * Opgpave 1 Lag en funksjonstemplate som finner ut om to verdier er like
 */
template <typename Type>
bool equal(Type a, Type b){
    std::cout << "Template utageve" << std::endl;
    if(a == b){
        return true;
    }

    return false;
}


/*
 * Lag en spesialutgave for doubl,
 * Anta at to slike verdier betraktes som like dersom forskjellen mellom dem er mindre enn for eksempel 0.00001.
 */
bool equal(double a, double b){
    std::cout << "Spesialisert double utgave" << std::endl;
    if( a-b <= 0.00001){
        return true;
    }else if(b-a <= 0.00001){
        return true;
    }
    return false;
}


/*
 * Oppgave 2
 *
 *
 *
 */




int main() {

    bool resultat=equal("Dette er en test","Dette er en test");
    if(resultat){
        std::cout << "Verdiene er like!" << std::endl;
    } else{
        std::cout << "Verdiene er IKKE like!" << std::endl;
    }



     resultat=equal(2,1.00001);
    if(resultat){
        std::cout << "Verdiene er like!" << std::endl;
    } else{
        std::cout << "Verdiene er IKKE like!" << std::endl;
    }




    return 0;
}