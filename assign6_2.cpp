#include<iostream>
using namespace std;

class Employee
{
    private:
    int id;
    double salary;

    public:

    Employee():id(0),salary(0.0)
    {  }

    Employee(int id, double salary):id(id),salary(salary)
    {   }

    void setId(int id)
    {
        this->id = id;
    }

    int getId( void )
    {
        return this->id;
    }

    void setSalary( double salary)
    {
        this->salary = salary;
    }

    double getSalary( void )
    {
        return this->salary;
    }

    virtual void accept()
    {
        cout<<"Id : "<<endl;
        cin>>id;
        cout<<"Salary : "<<endl;
        cin>>salary;
    }

    virtual void display()
    {
        cout<<"Id : "<<id<<endl;
        cout<<"Salary : "<<salary<<endl;
    }
};


class Manager : virtual public Employee
{
    private:
    double bonus;

    public:

    Manager():Employee(),bonus(0.0)
    {  }

    Manager(int id, double salary, double bonus): Employee(id,salary),bonus(bonus)
    {   }

    void setBonus(double bonus)
    {
        this->bonus = bonus;
    }

    double getSalary( void )
    {
        return this->bonus;
    }

    void acceptManager()
    {
        cout<<"Bonus : "<<endl;
        cin>>bonus;
    }

    void displayManager()
    {
        cout<<"Bonus : "<<bonus<<endl;
    }

    void accept()
    {
        Employee::accept();
        this->acceptManager();
    }

    void display()
    {
        Employee::display();
        this->displayManager();
    }
};


class Salesman : virtual public Employee
{
    private:
    double comm;

    public:

    Salesman():Employee(),comm(0.0)
    {  }

    Salesman(int id, double salary, double comm): Employee(id,salary),comm(comm)
    {   }

    void setComm(double comm)
    {
        this->comm = comm;
    }

    double getComm( void )
    {
        return this->comm;
    }

    void acceptSalesman()
    {
        cout<<"Commission : "<<endl;
        cin>>comm;
    }

    void displaySalesman()
    {
        cout<<"Commission : "<<comm<<endl;
    }

    void accept()
    {
        Employee::accept();
        this->acceptSalesman();
    }

    void display()
    {
        Employee::display();
        this->displaySalesman();
    }
};

class SalesManager : public Manager, public Salesman
{
    public:
    SalesManager():Manager(),Salesman()
    {  }

    SalesManager(int id,double  salary, double bonus, double comm):Employee(id,salary),Manager(id,salary,bonus),Salesman(id,salary,comm)
    {  }

    void accept()
    {
        Employee::accept();
        Manager::acceptManager();
        Salesman::acceptSalesman();
    }

    void display()
    {
        Employee::display();
        Manager::displayManager();
        Salesman::displaySalesman();
    }
};

int menuList()
{
    int choice;
    cout<<"----------------------"<<endl;
    cout<<"1. Employee"<<endl;
    cout<<"2. Manager"<<endl;
    cout<<"3. Salesman"<<endl;
    cout<<"4. Sales Manager"<<endl;
    cout<<"Enter Your Choice : "<<endl;
    cin>>choice;
    return choice;
}


int main()
{
    int choice;
    Employee *e = NULL;
    while ((choice = menuList()) != 0)
    {
        
        switch (choice)
        {
        case 1:
            e = new Employee();
            break;
        case 2:
            e = new Manager();
            break;
        case 3:
            e = new Salesman();
            break;
        case 4:
            e = new SalesManager();
            break;
        
        default:
            cout<<"Invalid Choice";
            break;
        }
        if (e != NULL)
        {
            e->accept();
            e->display();
        }
        
    }
    delete e;
    e = NULL;
    
    return 0;
}
