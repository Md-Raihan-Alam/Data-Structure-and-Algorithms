#include<iostream>
using namespace std;
template<class X> void swapargs(X &a,X &b)
//this is also same template<typename X> void swapargs(X &a,X &b)
{
    X temp;
    temp=a;
    a=b;
    b=temp;
}
int main()
{
    int i=10,j=20;
    float x=10.1,y=23.3;
    cout<<"Original i "<<i<<" j "<<j<<endl;
    swapargs(i,j);
    cout<<"now i "<<i<<" j "<<j<<endl;
    cout<<"Original x "<<x<<" y "<<y<<endl;
    swapargs(x,y);
    cout<<"Now x "<<x<<" y "<<y<<endl;
    return 0;
}