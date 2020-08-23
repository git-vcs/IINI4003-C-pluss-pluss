#include <iostream>
#include <algorithm>
#include <vector> // header-fil for vektor
using namespace std;


int main() {
    //øving 4 Oppgave 1
    vector<double> tall={1.1, 2.2, 3.3, 4.4, 5.5};
    cout <<"front() "<<tall.front()<<", back()"<<tall.back()<<endl;
    tall.emplace(tall.begin()+1,2.1);
    cout<<"front()"<<tall.front()<<endl;
    double finn=2.2;
    auto a=find(tall.begin(),tall.end(),2.2);
    if(a[0]==finn){
        cout<<"Funet!"<<endl;
    }else{
        cout<<"Ikke funnet!"<<endl;
    }


    return 0;
}