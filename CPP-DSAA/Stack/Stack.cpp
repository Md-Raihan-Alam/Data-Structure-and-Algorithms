#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
};
class Stack{
    private:
    Node *top;
    public:
    Stack(){
        top=NULL;
    }
    int Top()
    {
        return top->data;
    }
    void Push(int x)
    {
        Node *t=new Node;
        if(t==NULL)
        {
            cout<<"Stack is Full"<<endl;
            return ;
        }
        t->data=x;
        t->next=top;
        top=t;
    }
    int Pop(){
        if(top==NULL)
        {
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
        int x=-1;
        x=top->data;
        Node *t=top;
        top=top->next;
        delete t;
        return x;
    }
    void Display()
    {
        Node *p=top;
        while(p!=NULL)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }
    void Peek(int index)
    {
        Node *p=top;
        int count=1;
        while(p!=NULL && count<index)
        {
            p=p->next;
            count++;
        }
        if(p==NULL || index<=0)
        {
            cout<<"Index "<<index<<" is out of bounds"<<endl;
            return ;
        }
        cout<< p->data<<endl;
    }
};
int main()
{
    Stack st;
    st.Push(10);
    st.Push(20);
    st.Push(30);
    cout<<st.Top()<<endl;
    st.Display();
    cout<<st.Pop()<<endl;
    st.Display();
    st.Peek(2);
    return 0;
}