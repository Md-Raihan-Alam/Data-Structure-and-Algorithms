#include<iostream>
using namespace std;
class myclass{
    int a;
    public:
    myclass(){
        cout<<"In construction ";
        a=10;
        cout<<endl;
    }
    ~myclass(){
        cout<<"In destruction ";
    }
    void show(){
        cout<<a<<endl;
    }
};
int main()
{
    myclass ob;
    ob.show();
    return 0;
}