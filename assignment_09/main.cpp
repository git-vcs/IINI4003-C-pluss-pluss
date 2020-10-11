#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


ostream &operator<<(ostream &out, const vector<int> &table) {
    for (auto &e : table)
        out << e << " ";
    return out;
}


int main() {
    vector<int> v1 = {3, 3, 12, 14, 17, 25, 30};
    vector<int> v2 = {2, 3, 12, 14, 24};
    cout<<"V1: "<<v1<<endl;
    cout<<"V2: "<<v2<<endl;


    //Finn første element i v1 som er større enn 15 ved hjelp av find_if. Tips: Den logiske funksjonen skal ta ett argument og returnere true dersom dette er større enn 15
    auto oppg_a = find_if(v1.begin(),v1.end(),[](const int &input)->bool{return input>15;});
    cout<<"Det førtste elemente i v1 som er større enn 15 er :"<<oppg_a.operator*()<<endl;
    /*
     *  Vi definerer "omtrent lik" til å bety at forskjellen mellom to verdier ikke er mer enn 2.
     *  Finn ut om intervallet [v1.begin(), v1.begin() + 5> og v2 er like i denne betydningen av likhet.
     *  Hva med intervallet [v1.begin(), v1.begin() + 4>? Bruk algoritmen equal.
    */

    auto oppg_b=equal(v1.begin(),v1.begin()+5,v2.begin(),v2.begin()+5,[](const int &v1, const int &v2)->bool{
        return (v1-v2)<=2;
    });

    if(oppg_b){
        cout<<"De 2 intervalliene er Omtrent like"<<endl;
    } else{
        cout<<"De 2 intervalliene er IKKE Omtrent like"<<endl;
    }

    oppg_b=equal(v1.begin(),v1.begin()+5,v2.begin(),v2.begin()+4,
            [](const int &v1, const int &v2)->bool{
                return (v1-v2)<=2;
    });

    if(oppg_b){
        cout<<"De 2 intervalliene er Omtrent like"<<endl;
    } else{
        cout<<"De 2 intervalliene er IKKE Omtrent like"<<endl;
    }



    // Erstatt alle oddetall i v1 med 100 ved hjelp av replace_copy_if.
    replace_copy_if(v1.begin(),v1.end(),v1.begin(),[](const int &input)->bool{ return input%2==1;},100);
    cout<<"V1: "<<v1<<endl;


    return 0;
}