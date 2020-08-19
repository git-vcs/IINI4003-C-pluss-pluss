

#include <string>
#include <iostream>
using namespace std;
const double sales_tax=1.25;


class Commodity{
public:
    Commodity(string name_, int id_, double price_);
    string get_name();
    int get_id();
    void set_price(const double newPrice);
    double get_price(const double quantity);
    double get_price();
    double get_price_with_sales_tax();
    double get_price_with_sales_tax(const double quantity);

    //variabler
    double quantity;
private:
    string name;
    int id;

    double price;
};

//implementsjon

//                                         variabeler inn            setter variablene i klassen
Commodity::Commodity(string name_, int id_, double price_):name(name_),id(id_),price(price_) {}
/*
 * Er dette ekvivalent med javas constructor(int imput){this.input=input}
 *
 */


string Commodity::get_name() {
    return name;
}

int Commodity::get_id() {
    return id;
}

void Commodity::set_price(double newPrice) {
    price=newPrice;

}

double Commodity::get_price(const double quantity) {
    //todo ta antall enheter som argument og regne ut prisen for så mange enheter henholdsvis uten og med moms. Du kan sette momsen som en global konstant
    //cout<<quantity<<endl;
    return price*quantity;
}
double Commodity::get_price() {
    //todo ta antall enheter som argument og regne ut prisen for så mange enheter henholdsvis uten og med moms. Du kan sette momsen som en global konstant
    return price;
}

double Commodity::get_price_with_sales_tax(const double quantity) {
    //todo ta antall enheter som argument og regne ut prisen for så mange enheter henholdsvis uten og med moms. Du kan sette momsen som en global konstant
    //cout<<quantity<<endl;
    return price*quantity*sales_tax;
}


double Commodity::get_price_with_sales_tax() {
    //todo ta antall enheter som argument og regne ut prisen for så mange enheter henholdsvis uten og med moms. Du kan sette momsen som en global konstant

    return price*sales_tax;
}
