/*Q2. Write a menu driven program for Date in a CPP language using structure and also using class. 
Date is having data members day, month, year. Implement the following functions. 
void initDate(); 
void printDateOnConsole(); 
void acceptDateFromConsole(); 
bool isLeapYear();*/
#include<iostream>
using namespace std;

struct Date{
    int day;
    int month;
    int year;
    
    void initDate(){
         day=5;
         month=4;
         year=2025;
    }

    void printDateOnConsole()
    {
        cout<<"Day: "<<day<<endl;
        cout<<"Month: "<<month<<endl;
        cout<<"Year: "<<year<<endl;
    }

    void acceptDateFromConsole()
    {
        cout<<"Enter Day: "<<endl;
        cin>>day;

        cout<<"Enter Month: "<<endl;
        cin>>month;

        cout<<"Enter Year: "<<endl;
        cin>>year;

    } 

    bool isLeapYear()
    {
        return (year%400==0 || (year%4==0 && year%100!=0));
    }

};



    int main()
    {
        struct Date d;
        d.initDate();
        d.printDateOnConsole();
        d.acceptDateFromConsole();
        d.printDateOnConsole();
        if(d.isLeapYear()){
          cout<<"This year is leap year."<<endl;
        }
        else{
            cout<<"This year is not a leap year"<<endl;
        }
        
    }




