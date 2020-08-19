#include "commodity.cpp"
#include <iostream>
#include <string>

using namespace std;
const double pi = 3.141592;

class Circle {
public:
    Circle(double radius_);
    double get_area() const;
    double get_circumference() const;


private :
    double radius;
};


Circle::Circle(double radius_) : radius(radius_){}

double Circle::get_area()const {
    return pi * radius * radius;
}

double Circle::get_circumference() const {
    double circumference = 2.0 * pi * radius;
    return circumference;
}






int main() {

    //oppgave 2
    cout << "Oppgave 2"<< endl;

    Circle circle(5);

    double area = circle.get_area();
    cout << "Arealet er lik "<<area<< endl;

    double circumference = circle.get_circumference();
    cout << "Omkretsen er lik " << circumference << endl;






    //oppgave 3
    cout<<"Oppgave 3"<<endl;

    const double quantity = 2.5;
    Commodity commodity("Norvegia", 123, 73.50);

    cout << "Varenavn: " << commodity.get_name() << ", varenr: " << commodity.get_id() << " Pris pr enhet: " << commodity.get_price() << endl;

    cout << "Kilopris: " << commodity.get_price() << endl;
    cout << "Prisen for " << quantity << " kg er " << commodity.get_price(quantity) << " uten moms" << endl;
    cout << "Prisen for " << quantity << " kg er " << commodity.get_price_with_sales_tax(quantity) << " med moms" << endl;

    commodity.set_price(79.60);
    cout << "Ny kilopris: " << commodity.get_price() << endl;
    cout << "Prisen for " << quantity << " kg er " << commodity.get_price(quantity) << " uten moms" << endl;
    cout << "Prisen for " << quantity << " kg er " << commodity.get_price_with_sales_tax(quantity) << " med moms" << endl;
    return 0;
}

/* Utskrift:
Varenavn: Norvegia, varenr: 123 Pris pr enhet: 73.5
Kilopris: 73.5
Prisen for 2.5 kg er 183.75 uten moms
Prisen for 2.5 kg er 229.688 med moms
Ny kilopris: 79.6
Prisen for 2.5 kg er 199 uten moms
Prisen for 2.5 kg er 248.75 med moms
*/