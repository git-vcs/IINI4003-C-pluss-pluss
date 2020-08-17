#include <iostream> //innlesning/utlesning

#include <cstdlib>

using namespace std; //bruker standard navnerom.




void read_temperatures(double temperatures[], int length);

void opptelling(double temperatures[], int length){
    const int lavTemperatur=10;
    const int overTemperatur=20;
    int antUnderLavtemperatur=0;
    int antMellom=0;
    int antOver=0;
    for(int i=0;i<=length-1;i++){
        //DEBUG cout
        //cout<<"jeg lese disse tallene fra minne: "<<temperatures[i]<<endl;
       if (temperatures[i]<lavTemperatur){
            antUnderLavtemperatur++;
        }else if(temperatures[i]>overTemperatur) {
            antOver++;
        }
        if(temperatures[i]>=lavTemperatur&&temperatures[i]<=overTemperatur){
            antMellom++;
        }



    }
    cout<<"\n";
    cout<<"Antall under 10 er ";
    cout<<antUnderLavtemperatur;
    cout<<"\n";
    cout<<"Antall mellom 10 og 20 er "<<antMellom<<endl;
    cout<<"Antall over 20 er "<<antOver<<endl;
}


int main() {



    //oppgave a
    const int length = 5;
    const int lavTemperatur=10;
    const int overTemperatur=20;
    int antUnderLavtemperatur=0;
    int antMellom=0;
    int antOver=0;
    cout <<"Oppgave A"<< endl;
    cout <<"Du skal skrive inn 5 temperaturer."<< endl;

    double nr1;
    cout <<"Temperatur nr 1:"<<endl;
    cin>>nr1;

    if (nr1<lavTemperatur){
        antUnderLavtemperatur++;
    }else if(nr1>overTemperatur) {
        antOver++;
    }
    if(nr1>=lavTemperatur&&nr1<=overTemperatur){
        antMellom++;
    }

    double nr2;
    cout <<"Temperatur nr 2:"<<endl;
    cin>>nr2;
    if (nr2<lavTemperatur){
        antUnderLavtemperatur++;
    }else if(nr2>overTemperatur) {
        antOver++;
    }
    if(nr2>=lavTemperatur&&nr2<=overTemperatur){
        antMellom++;
    }



    double nr3;
    cout <<"Temperatur nr 3:"<<endl;
    cin>>nr3;

    if (nr3<lavTemperatur){
        antUnderLavtemperatur++;
    }else if(nr3>overTemperatur) {
        antOver++;
    }
    if(nr3>=lavTemperatur&&nr3<=overTemperatur){
        antMellom++;
    }
    double nr4;
    cout <<"Temperatur nr 4:"<<endl;
    cin>>nr4;

    if (nr4<lavTemperatur){
        antUnderLavtemperatur++;
    }else if(nr4>overTemperatur) {
        antOver++;
    }
    if(nr4>=lavTemperatur&&nr4<=overTemperatur){
        antMellom++;
    }

    double nr5;
    cout <<"Temperatur nr 5:"<<endl;
    cin>>nr5;
    if (nr5<lavTemperatur){
        antUnderLavtemperatur++;
    }else if(nr5>overTemperatur) {
        antOver++;
    }
    if(nr5>=lavTemperatur&&nr5<=overTemperatur){
        antMellom++;
    }


    cout<<"\n";
    cout<<"Antall under 10 er ";
    cout<<antUnderLavtemperatur;
    cout<<"\n";
    cout<<"Antall mellom 10 og 20 er "<<antMellom<<endl;
    cout<<"Antall over 20 er "<<antOver<<endl;

    // Oppgave B

    cout <<"Oppgave B"<< endl;
    double temperatures[length*2];
    read_temperatures(temperatures,length*2);
    }



void read_temperatures(double temperatures[], int length) {
    /*
     * Funksjonen skal åpne filen,
     * lese inn temperaturene og lagre dem i tabellen temperatures,
     * og endelig lukke filen.
     *
     */
    #include <fstream> //for å lese/skrive til filer
    const char filenavn[]="temperaturer";
    ifstream file;
    file.open(filenavn);
    if(!file){
        cout << "feil med fil-lesing\n";
        exit(EXIT_FAILURE);
    }
    int teller=0;
    int currentNumber;
    while (file>>currentNumber){
        if(teller>=length){
            cout << "Fila har for mange temperaturer\n";
            exit(EXIT_FAILURE);
            file.close();
        }
        temperatures[teller]=currentNumber;
        //debug cout
       // cout<<"Jeg leste nettopp tallet: "<<currentNumber<<endl;
        teller++;
    }
    file.close();
    cout << "Jeg er ferdig å lese fil"<<endl;
    opptelling(temperatures,length);

}