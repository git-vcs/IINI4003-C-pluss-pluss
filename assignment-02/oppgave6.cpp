#include <iostream> //innlesning/utlesning

#include <cstdlib>
#include <cstring>

using namespace std; //bruker standard navnerom.
int fin_sum(const int *table, int length);

int main() {
    const int length=20;
    int tall[length]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    cout<<"summen av alle tallene i tabellen  er: "<<fin_sum(tall,length)<<endl;

    cout<<"summen av de 10 føreste tallene er: "<<fin_sum(tall,10)<<endl;

    //tolker dette som summen av tabl[10] til tab[15]
    int *nesteTallene=&tall[10];
    cout<<"summen av de 5 neste tallene er: "<<fin_sum(nesteTallene,5)<<endl;

    const int *sisteFemTallene=&tall[length-5];
    cout<<"summen av de 5 siste tallene er: "<<fin_sum(sisteFemTallene,5)<<endl;

}


int fin_sum(const int *table, int length){
    int sum=0;
    int pointer=0;
    while(pointer<length){
        sum+=*(table+pointer);
        pointer++;
    }
    return sum;
}