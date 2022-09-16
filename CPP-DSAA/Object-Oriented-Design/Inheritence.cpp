#include<iostream>
#include<string>
using namespace std;
class Person{
    string name;
    string idNum;
    public:
    Person(string name,string idNum)
    {
        this->name=name;
        this->idNum=idNum;
    }
    void print()
    {
        cout<<name<<" "<<idNum<<endl;
    }
    string getName()
    {
        return name;
    }
};
class Student:public Person{
    string major;
    int gradYear;
    public:
    Student(string name,string idNum,string major,int gradYear):Person(name,idNum)
    {
        this->major=major;
        this->gradYear=gradYear;
    }
    void printStudent(){
        print();
        cout<<major<<" "<<gradYear<<endl;
    }
    void changeMajor(const string &newMajor)
    {
        this->major=newMajor;
    }
};
int main()
{
    Person person("Mary","C194345");
    Student student("Raihan","C221066","CSE",2026);
    cout<<person.getName()<<endl;
    person.print();
    student.printStudent();
    student.changeMajor("SWE");
    student.printStudent();
    return 0;
}