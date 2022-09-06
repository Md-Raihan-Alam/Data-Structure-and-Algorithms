#include<iostream>
using namespace std;
class truck;
class car{
    int passengers;
    int speed;
    public:
    car(int p,int s)
    {
        passengers=p;
        speed=s;
    }
    friend int spe_greater(car c,truck t);
};
class truck{
    int weight;
    int speed;
    public:
    truck(int w,int s)
    {
        weight=w;
        speed=s;
    }
    friend int spe_greater(car c,truck t);
};
int spe_greater(car c,truck t)
{
    return c.speed-t.speed;
}
int main()
{
    car c(6,54);
    truck t1(1000,55);
    int t=spe_greater(c,t1);
    if(t<0) cout<<"truck is faster"<<endl;
    else if(t==0) cout<<"Both are same"<<endl;
    else cout<<"car is faster"<<endl;
}