#include<iostream>
using namespace std;
class myclass{
    int a;
    public:
    myclass(int x)
    {
        a=x;
    }
    int get(){
        return a;
    }
};
int main()
{
    myclass ob(120);
    myclass *p;
    p=&ob;
    cout<<p->get();
    return 0;
}