#include<iostream>
using namespace std;
void f1(int a)
{
    cout<<"In f1 ";
    cout<<a<<endl;
}
void f2(int a,int b)
{
    cout<<"In f2 ";
    cout<<a<<" "<<b<<endl;
}
int main()
{
    f1(10);
    f2(10,20);
    return 0;
}