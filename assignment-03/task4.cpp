#include <iostream>
#include <string>



using namespace std;



int main() {

    //oppgave 4
    cout<<"Oppgave 4\nA:"<<endl;

    //A
    string word1;
    string word2;
    string word3;
    cout<<"\nskriv inn et ord:";
    cin>>word1;
    cout<<"\nskriv inn et ord:";
    cin>>word2;
    cout<<"\nskriv inn et ord:";
    cin>>word3;


    //B
    cout<<"B:"<<endl;
    string sentence =word1+" "+word2+" "+word3+".";
    cout<<sentence<<endl;


    //c
    cout<<"C:"<<endl;
    cout<<"word1: "<<word1<<", Size: "<<word1.size()<<endl;
    cout<<"word2: "<<word2<<", Size: "<<word2.size()<<endl;
    cout<<"word3: "<<word3<<", Size: "<<word3.size()<<endl;
    cout<<"sentence: "<<sentence<<", Size: "<<word2.size()<<endl;


    //D
    string sentence2(sentence);


    //E
    /*
     * Bytt ut tegn nr 10-12 i sentence2 med x’er.
     * Tegnene nummereres fra og med 0.
     * Husk å kontrollere at dette er gyldige posisjoner!
     * Skriv ut sentence og sentence2.
     */

    int pointer=0;
    if(sentence2.length()>=12){
        sentence2.replace(9,2,"xx");
        cout<<"E:\n"<<sentence2<<endl;
    } else cout<<"E:\nTeksen er for kort til å sette in x'er"<<endl;


    //F
    /*
     *  Lagre de fem første tegnene i sentence i objektet sentence_start.
     *  Skriv ut sentence og sentence_start.
     *  (Husk kontroll av gyldige posisjoner)
     */
    cout<<"F:"<<endl;
    string sentence_start;
    pointer=0;
    while (pointer<5&&sentence.length()>=5){
        sentence_start+=sentence.at(pointer);
        pointer++;
    }
    cout<<"sentence: "<<sentence<<endl;
    cout<<"sentence_start: "<<sentence_start<<endl;


   //G
   /*
    * Finn ut om sentence inneholder ordet "hallo". Skriv ut resultatet.
    */

  cout<<"G:"<<endl;
  bool finn= false;
   int finnHallo=sentence.find("hallo");
   string search[]={" Hallo."," hallo."," hallo "," Hallo ","hallo","Hallo"};
    for(int i=0;i<search->size();i++){
        int finnHallo=sentence.find(search[i]);
        if(finnHallo!=-1){
            //for å fordindre aaaaaHalloaaaaaa
            if(i>=4&&finnHallo==0){
                finn= true;
                break;
            } else if(i<4&&finnHallo!=-1){
                finn= true;
                break;
            }

        }
    }

    if(finn){
        cout<<"ordet hallo finnes i settningen"<<endl;
    } else cout<<"ordet hallo finnes IKKE i settningen"<<endl;


   //H
   /*
    * Finn alle forekomster i sentence av strengen "er". Skriv ut resultatet.
    */

    cout<<"H:"<<endl;
    pointer=0;
    int teller=0;
    bool run=true;
    while (run){
        //finner possisjon til første instanse av er
        int temp=sentence.find("er",pointer);
        if(temp!=-1){
            teller++;

            //setter netste søkepossisjon
            pointer=temp+2;
        } else run = false;

    };
    cout<<"antall er i setniingen: "<<teller<<endl;



}

