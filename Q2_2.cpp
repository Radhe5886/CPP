#include<iostream>
using namespace std;

class tollbooth
{

    unsigned int car;
    unsigned int ncar;
    double amount ;

    public:
    tollbooth()
    {
        car=0;
        amount=0;
        ncar=0;

    }

    int payingCar()
    {
        car++;
        amount=amount+0.50;
    }
    int nopayCar()
    {
        ncar++;
    }
    int printonConsole()
    {
        cout<<"Cars paid toll : "<<car<<endl;
        cout<<"Total Amount collected: "<<amount<<endl;
        cout<<"Cars paid no toll : "<<ncar<<endl;
        cout<<"Total number of cars: "<<car+ncar<<endl;
    }

   
};

 int main()
    {
        tollbooth tb;
        tb.payingCar();
        tb.payingCar();
        tb.payingCar();
        tb.nopayCar();
        tb.printonConsole();

    }

