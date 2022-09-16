#include<iostream>
using namespace std;
class Nums{
    public:
//function overloading - polymorphism
    void func(int x)
    {
        cout<<"X "<<x<<endl;
    }
    void func(double x)
    {
        cout<<"X double "<<x<<endl;
    }
    void func(int x,int y)
    {
        cout<<"X "<<x<<" Y "<<y<<endl;
    }
};
int main()
{
    Nums obj;
    obj.func(7);
    obj.func(32.43);
    obj.func(4,5);
    return 0;
}