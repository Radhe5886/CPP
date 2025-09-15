#include<iostream>
using namespace std;

class cylinder
{
    private:
    double radius;
    double height;
    static float pi  ;
    
    public:
    cylinder()
    {
        radius=10;
        height=15;

    }

    cylinder(double radius,double height)
    {
        this->radius=radius;
        this->height=height;

    }

    float setRadius(int radius)
    {
        this->radius=radius;
    }
    float getRadius()
    {
        return this->radius;
        
    }

    float setheight(int height)
    {
        this->height=height;
    }
    float getheight()
    {
        return this->height;
    }

    float calculateVolume()
    {
        int res = pi * radius * height;
        cout<<"result: "<<res<<endl;
    }


};

float cylinder::pi=3.14;

int main()
{
    cylinder c;
    c.calculateVolume();

    int x;
    int y;
    cout<<"Enter radius and height: "<<endl;

    cin>>x>>y;
    cylinder c3(x,y);
    c3.calculateVolume();

    cylinder c1;
    c1.setheight(5);
    cout<<c1.getheight()<<endl;
    c1.calculateVolume();

    cylinder c2;
    c2.setRadius(10);
    cout<<c2.getRadius()<<endl;
    c2.calculateVolume();
}