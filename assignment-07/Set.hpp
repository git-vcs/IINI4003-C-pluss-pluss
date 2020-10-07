//
// Created by mikael on 06.10.20.
//
#pragma onnce

#include <vector>
class Set {
public:
    std::vector<int> tall;

    Set();//default constructor
    //unionen av to mengder.
    Set getUnion(const Set &set1);

    //legge et nytt tall inn i en mengde, Dersom tallet fins fra før, skal det ikke skje noe.
    Set &operator+(const int &nyttTall);


    //sette en mengde lik en annen mengde
    Set &operator=(Set &set);
};
