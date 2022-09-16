#include<iostream>
using namespace std;
class base{
    public:
    virtual void print()
    {
        cout<<"Print base class"<<endl;
    }
    void show()
    {
        cout<<"Show base class"<<endl;
    }
};
class derived:public base
{
    public:
    void print()//print() is already virtual function in derived class
    {
        cout<<"print derived class"<<endl;
    }
    void show()
    {
        cout<<"Show derived class"<<endl;
    }
};
int main()
{
    base *p;
    derived d;
    base b;
    p=&b;
    //virtual function, binded at runtime (Runtime polymorphism)
    p->print();
    // Non-virtual function, binded at compile time
    p->show();
    p=&d;
    //virtual function, binded at runtime (Runtime polymorphism)
    p->print();
    // Non-virtual function, binded at compile time
    p->show();
    return 0;
}