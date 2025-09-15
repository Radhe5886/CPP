#include<iostream>
using namespace std;

class Date
{
    private:
    int day;
    int month;
    int year;

    public:
    Date(void):day(0),month(0),year(0)
    { }

    Date(int day,int month,int year):day(day),month(month),year(year)
    { }

    void accept()
    {
        cout<<"Day : "<<endl;
        cin>>day;
        cout<<"Month : "<<endl;
        cin>>month;
        cout<<"Year : "<<endl;
        cin>>year;
    }

    void printDate()
    {
        cout<<day<<"/"<<month<<"/"<<year<<endl;
    }
};

class Person
{
    private:
    string name;
    string address;
    Date *dob;

    public:

    Person(void):name(""),address(""),dob(NULL)
    { }

    Person(string name, string address):name(name),address(address),dob(NULL)
    { }

    Person(string name, string address,int day,int month,int year):Person(name,address)
    {
        dob = new Date(day,month,year);
    }

    void personRecord(void)
    {
        cout<<"Enter Name: "<<endl;
        cin>>name;
        cout<<"Enter Address: "<<endl;
        cin>>address;
        cout<<"Enter Date of Birth: "<<endl;
        if (dob!=NULL)
        {
            delete dob;
            dob=NULL;
        }
        this->acceptDate();
    }

    void acceptDate()
    {
        if (dob!=NULL)
        {
            delete dob;
            dob = NULL;
        }
        dob = new Date();
        dob->accept();
    }

    void showPersonRecord()
    {
        cout<<"Person Name: "<<name<<endl;
        cout<<"Person Address: "<<address<<endl;
        cout<<"Person Date of Birth: ";
        if (dob!=NULL)
        {
            dob->printDate();
        }
    }

    ~Person()
    {
        if (dob!=NULL)
        {
            delete dob;
            dob = NULL;
        }
        
    }
};

class Student 
{
    private:
    int student_id;
    int marks;
    string course;
    Date *joinDate;
    Date *endDate;

    public:

    Student(void):student_id(0),marks(0),course(""),joinDate(NULL),endDate(NULL)
    { }

    Student(int student_id,int marks,string course,int day,int month,int year,int day1,int month1, int year1):student_id(student_id),marks(marks),course(course)
    { 
        joinDate = new Date(day,month,year);
        endDate = new Date(day1,month1,year1);
    }

    void studentRecord()
    {
        cout<<"Student ID: ";
        cin>>student_id;
        cout<<"Marks: ";
        cin>>marks;
        cout<<"Course: ";
        cin>>course;
        this->studentDate();
    }

    void studentDate()
    {
        cout<<"Enter Join Date: "<<endl;
        if (joinDate!=NULL)
        {
            delete joinDate;
            joinDate = NULL;
        }
        joinDate = new Date();
        joinDate->accept();

        cout<<"Enter End Date: "<<endl;
        if (endDate!=NULL)
        {
            delete endDate;
            endDate = NULL;
        }
        endDate = new Date();
        endDate->accept();
    }

    void printStudentRecord(void)
    {
        cout<<"Student ID: "<<student_id<<endl;
        cout<<"Marks: "<<marks<<endl;
        cout<<"Course: "<<course<<endl;
        cout<<"Join Date: ";
        if (joinDate!=NULL)
        {
            joinDate->printDate();
        }
        cout<<"End Date: ";
        if (endDate!=NULL)
        {
            endDate->printDate();
        }
    }

    ~Student()
    {
        if (joinDate!=NULL)
        {
            delete joinDate;
            joinDate = NULL;
        }
        if (endDate!=NULL)
        {
            delete endDate;
            endDate = NULL;
        }
        
    }
};

int menulist()
{
    int choice;

    cout<<"1. Add Person Details"<<endl;
    cout<<"2. Add Student Details"<<endl;
    cout<<"0. Exit"<<endl;

    cout<<"Enter Your Choice: "<<endl;
    cin>>choice;

    return choice;
}



int main() 
{

    int choice;

    Person p;
    Student s;

    while ((choice = menulist())!=0)
    {
        switch (choice)
        {
        case 1:
            p.personRecord();
            p.showPersonRecord();
            break;
        case 2:
            s.studentRecord();
            s.printStudentRecord();
            break;
        
        default:
            cout<<"Enter Valid Choice!!!"<<endl;
            break;
        }
    }
    
    //Person p;
    //p.personRecord();
    //p.showPersonRecord();

    //Student s;
    //s.studentRecord();
    //s.printStudentRecord();
    return 0;
}