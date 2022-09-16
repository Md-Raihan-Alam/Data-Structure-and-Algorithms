#include<iostream>
using namespace std;
template<class Type1> class pow
//template<typename Type1> class pow
{
    Type1 res=1;
    public:
    pow(Type1 i,Type1 j)
    {
        for(int n=1;n<=j;n++)
        res*=i;
    }
    void show()
    {
        cout<<res<<endl;
    }
};
int main()
{
    pow<int> p(3,2);
    p.show();
    return 0;
}