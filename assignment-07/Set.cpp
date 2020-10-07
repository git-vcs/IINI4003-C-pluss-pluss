//
// Created by mikael on 06.10.20.
//
using namespace std;
#include "Set.hpp"
Set::Set(){}

//todo unionen av to mengder.
Set Set::getUnion(const Set &set1) {
    Set set=*this;
    for (int i = 0; i <(int)set1.tall.size() ; ++i) {
        set + set1.tall[i];

    }
    return set;
}


//legge et nytt tall inn i en mengde, Dersom tallet fins fra før, skal det ikke skje noe.


Set &Set::operator+(const int &nyttTall) {

    bool funnet=false;
    for(int i = 0;i < tall.size(); i++){
        if(tall[i]==nyttTall){
            funnet= true;
            break;
        }
    }
    if(!funnet) tall.emplace_back(nyttTall);
    return *this;
}

//sette en mengde lik en annen mengde

Set &Set::operator=(Set &set) {
    tall.clear();
    tall=set.tall;
    return *this;
}

