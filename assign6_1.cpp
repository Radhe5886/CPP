#include<iostream>
using namespace std;

class Product
{
    protected:
    int id;
    string title;
    double price;

    public:
    Product():id(0),title(""),price(0.0)
    {  }
     
    Product(int id,string title,double price):id(id),title(title),price(price)
    {  }

    virtual void accept()
    {
        cout<<"Id : ";
        cin>>id;
        cout<<"Title : ";
        cin>>title;
        cout<<"Price : ";
        cin>>price;
    }

    virtual void display()
    {
        cout<<"Id : "<<id<<endl;
        cout<<"Title : "<<title<<endl;
        cout<<"Price : "<<price<<endl;
    }

    virtual int cal_price_after_discount() = 0;
};

class Book : public Product
{
    private:
    string author;

    public:


    Book():author(""),Product()
    {  }

    Book(int id,string title,double price,string author):Product(id,title,price),author(author)
    {  }

    void accept()
    {
        Product::accept();
        cout<<"Author : ";
        cin>>author;
    }

    void display()
    {
        Product::display();
        cout<<"Author : "<<author<<endl;
    }

    int cal_price_after_discount()
    {
        return price-(price*0.10);
    }
};


class Tape : public Product
{
    private:
    string artist;

    public:


    Tape():artist(""),Product()
    {  }

    Tape(int id,string title,double price,string artist):Product(id,title,price),artist(artist)
    {  }

    void accept()
    {
        Product::accept();
        cout<<"Artist : ";
        cin>>artist;
    }

    void display()
    {
        Product::display();
        cout<<"Artist : "<<artist<<endl;
    }

    int cal_price_after_discount()
    {
        return price-(price*0.05);
    }
};

int menuList()
{
    int choice;
    cout<<"------------------"<<endl;
    cout<<"0. Exit "<<endl;
    cout<<"1. Book"<<endl;
    cout<<"2. Tape"<<endl;
    cout<<"Enter your choice: "<<endl;
    cin>>choice;

    return choice;
}

int main()
{
    int choice;
    int count = 0;
    Product *arr[3];
    while ((choice = menuList()) != 0 && count<3)
    {
        switch (choice)
        {
        case 1:
            arr[count] = new Book();
            arr[count]->accept();
            //arr[count]->display();
            count++;
            break;
        case 2:
            arr[count] = new Tape();
            arr[count]->accept();
            //arr[count]->display();
            count++;
            break;
        
        default:
            cout<<"Invalid Choice"<<endl;
            break;
        }
    }
    double total = 0;
    for (int i = 0; i < count; i++)
    {
        total = total + arr[i]->cal_price_after_discount();
    }
    
    cout<<"The Total Bill is : "<<total<<endl;

    delete[] *arr;
    *arr = NULL;
    
    return 0;
}
