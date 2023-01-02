#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node *head=NULL;
};
class LinkedList:public Node{
    public:
    void add(int x)
    {
        Node *temp=new Node();
        temp->data=x;
        temp->next=NULL;
        if(head!=NULL)
        {
            temp->next=head;
        }
        head=temp;
    }
    void print()
    {
        Node *temp=head;
        cout<<"List is :";
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    void insert(int x,int n)
    {
        n--;
        Node *temp=new Node();
        temp->data=x;
        temp->next=NULL;
        if(n==0)
        {
            temp->next=head;
            head=temp;
            return ;
        }
        Node *temp2=head;
        for(int i=0;i<n-1;i++)
        {
            temp2=temp2->next;
        }
        temp->next=temp2->next;
        temp2->next=temp;
    }
    void del(int n)
    {
        n--;
        Node *temp=head;
        if(n==0)
        {
            head=temp->next;
            delete(temp);
            return ;
        }
        for(int i=0;i<n-1;i++)
        {
            temp=temp->next;
        }
        Node *temp2=temp->next;
        temp->next=temp2->next;
        delete(temp2);
    }
    void rev()
    {
        Node *current,*next,*prev;
        current=head;
        prev=NULL;
        while(current!=NULL)
        {
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        head=prev;
    }
};
int main()
{
    LinkedList ll;
    cout<<"How many numbers:";
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the number:";
        cin>>x;
        ll.add(x);
    }
    ll.print();
    ll.insert(2,1);
    ll.insert(3,2);
    ll.insert(4,1);
    ll.insert(5,2);
    ll.print();
    int d;
    cout<<"Enter the position you want to delete:";
    cin>>d;
    ll.del(d);
    ll.print();
    ll.rev();
    ll.print();
    return 0;
}
