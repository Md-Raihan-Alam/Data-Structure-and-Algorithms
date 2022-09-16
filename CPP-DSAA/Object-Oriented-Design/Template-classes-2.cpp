#include<iostream>
using namespace std;
template<typename Type1,typename Type2> class myclass
{
    Type1 i;
    Type2 j;
    public:
    myclass(Type1 a,Type2 b)
    {
        i=a;
        j=b;
    }
    void show()
    {
        cout<<i<<" "<<j<<endl;
    }
};
int main()
{
    myclass<int,int> ob(2,3);
    ob.show();
}