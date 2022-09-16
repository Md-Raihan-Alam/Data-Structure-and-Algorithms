#include<iostream>
using namespace std;
class Base{
    protected:
    int a,b;//pritivate to base but accessible to derived
    public:
    void setab(int n,int m)
    {
        a=n;
        b=m;
    }
    void show(){
        cout<<a<<" "<<b<<endl;
    }
};
class Derived:public Base{
    int c;
    public:
    void setc(int n)
    {
        c=n;
    }
    void showabc()
    {
        cout<<a<<" "<<b<<" "<<c<<endl;
    }
};
int main()
{
    Derived ob;
    Base ob2;
    //a and b are not accessible here because thery are private to base and derived
    ob.setab(1,2);
    ob.setc(3);
    ob.showabc();
    ob2.setab(5,6);
    ob2.show();
    return 0;
}