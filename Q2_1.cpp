#include<iostream>

using namespace std;

class box
{
    int length;
    int width;
    int height;
 
    public:
    box()
    {
        length = 5;
        width = 6;
        height = 6;
    }

    box(int length,int width,int height)
    {
        this->length=length;
        this->width=width;
        this->height=height;
    }

    box(int x)
    {
        length=x;
        width=x;
        height=x;
    }

    int area()
    {
        int area = length*width*height;
        cout<<"area: "<<area<<endl;
    }
};

int main()
{
    cout<<"Enter a no. of what type of constructor you want to use 1. Parameterless 2.parameterized 3.singleparamaterized: "<<endl;
    int y;
    cin>>y;
    switch (y)
    {
    case 1:
    {
        box b;
        b.area();
        break;
    }
    case 2:
    { 
        box b1(10,20,30);
        b1.area();
        break;

    }
    case 3:
    {
        box b2(10);
        b2.area();
        break;
     
    }
    
    default:
    cout<<"Enter a valid no. (between 1 to 3)";
        break;
    }
    
    
    
}