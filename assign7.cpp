#include<iostream>
#include<vector>
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
        cout<<"---Manager---"<<endl;
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
        cout<<"---SalesMan---"<<endl;
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
        cout<<"---SalesManager---"<<endl;
        Employee::display();
        Manager::displayManager();
        Salesman::displaySalesman();
    }
};


void addManager(vector<Employee*> &emp_list)
{
    Manager *m = new Manager();
    m->accept();
    emp_list.push_back(m);
}

void addSalesman(vector<Employee*> &emp_list)
{
    Salesman *s = new Salesman();
    s->accept();
    emp_list.push_back(s);
}

void addSalesmanager(vector<Employee*> &emp_list)
{
    SalesManager *sm = new SalesManager();
    sm->accept();
    emp_list.push_back(sm);
}

void displayCountOfEmployeeWRTDesignation(vector<Employee*> &emp_list)
{
    int manager =0 ;
    int salesman = 0;
    int salesmanager = 0;
    for (int i = 0; i < emp_list.size(); i++)
    {
        if (typeid(*emp_list[i]) == typeid(Manager))
        {
            manager++;
        }
        else if(typeid(*emp_list[i]) == typeid(Salesman))
        {
            salesman++;
        }
        else
        {
            salesmanager++;
        }
    }
    cout<<"Manager count : "<<manager<<endl;
    cout<<"Salesman count: "<<salesman<<endl;
    cout<<"SalesManager: "<<salesmanager<<endl;
}


void displayAllManagers(vector<Employee*> &emp_list)
{
    for (int i = 0; i < emp_list.size(); i++)
    {
        if (typeid(*emp_list[i]) == typeid(Manager))
        {
            emp_list[i]->display();
        }
    }
}



void displayAllSalesmans(vector<Employee*> &emp_list)
{
    for (int i = 0; i < emp_list.size(); i++)
    {
        if (typeid(*emp_list[i]) == typeid(Salesman))
        {
            emp_list[i]->display();
        } 
    }
}


void displayAllSalesManagers(vector<Employee*> &emp_list)
{
    for (int i = 0; i < emp_list.size(); i++)
    {
        if (typeid(*emp_list[i]) == typeid(SalesManager))
        {
            emp_list[i]->display();
        }
    }
}



int menuList()
{
    int choice;
    cout<<"-------------------------------------"<<endl;
    cout<<"1. Add Manager"<<endl;
    cout<<"2. Add Salesman"<<endl;
    cout<<"3. Add SalesManager"<<endl;
    cout<<"4. Display the count of all employees with respect to designation"<<endl;
    cout<<"5. Display All Managers"<<endl;
    cout<<"6 Display All Salesman"<<endl;
    cout<<"7 Display All SalesManagers"<<endl;
    cout<<"-------------------------------------"<<endl;
    
    cout<<"Enter Your Choice : "<<endl;
    cin>>choice;
    return choice;
}



int main()
{
    int choice;
    vector<Employee*> emp_list;
    while ((choice = menuList()) != 0)
    {
        
        switch (choice)
        {
        case 1:
        cout<<"-------------------------"<<endl;
            addManager(emp_list);
            cout<<"-------------------------"<<endl;
            break;
        case 2:
        cout<<"-------------------------"<<endl;
            addSalesman(emp_list);
            cout<<"-------------------------"<<endl;
            break;
        case 3:
        cout<<"-------------------------"<<endl;
            addSalesmanager(emp_list);
            cout<<"-------------------------"<<endl;
            break;
        case 4:
        cout<<"-------------------------"<<endl;
            displayCountOfEmployeeWRTDesignation(emp_list);
            cout<<"-------------------------"<<endl;
            break;
        case 5:
        cout<<"-------------------------"<<endl;
            displayAllManagers(emp_list);
            cout<<"-------------------------"<<endl;
            break;
        case 6:
        cout<<"-------------------------"<<endl;
            displayAllSalesmans(emp_list);
            cout<<"-------------------------"<<endl;
            break;
        case 7:
        cout<<"-------------------------"<<endl;
            displayAllSalesManagers(emp_list);
            cout<<"-------------------------"<<endl;
            break;
        
        default:
            cout<<"Invalid Choice";
            break;
        }
        
    }
    
    return 0;
}
