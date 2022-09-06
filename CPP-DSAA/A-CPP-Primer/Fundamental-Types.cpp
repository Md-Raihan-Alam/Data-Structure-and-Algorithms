#include<iostream>
using namespace std;
int main()
{
    short n;
    int octalNumber=0400;
    char newLine='\n';
    long BIGnumber=4846546L;
    short var;
    enum Day {SUN,MON,TUE,WED,THU,FRI,SAT};
    enum Mood {HAPPY=3,SAD=1,ANXIOUS=4,SLEEPY=2};
    Day today=THU;
    Mood myMood=SLEEPY;
    cout<<octalNumber<<endl;
    cout<<BIGnumber<<endl;
    cout<<today<<endl;
    cout<<myMood<<endl;
    return 0;
}