#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
        Node *head=NULL;
        int sz=0;
};
class LinkedList:public Node{
    public:
        void Add(int x)
        {
            class Node *temp=new Node[sizeof(Node)];
            temp->data=x;
            temp->next=NULL;
            if(head!=NULL)
            {
                temp->next=head;
            }
            head=temp;
            sz++;
        }
        void insert(int x,int n)
        {
            if(n<1 || n>sz)
            {
                cout<<"INVALID or list is empty"<<endl;
                return ;
            }
            class Node *temp=new Node[sizeof(Node)];
            temp->data=x;
            temp->next=NULL;
            if(n==1)
            {
                temp->next=head;
                head=temp;
                sz++;
                return ;
            }
            class Node *temp2=head;
            while(n--)
                temp2=temp2->next;
            temp->next=temp2->next;
            temp2->next=temp;
            sz++;
        }
        void del(int n)
        {
            if(n<1 || n>sz)
            {
                cout<<"INVALID"<<endl;
                return ;
            }
            class Node *temp=head;
            if(n==1)
            {
                head=temp->next;
                delete(temp);
                sz--;
                return ;
            }
            for(int i=1;i<=n;i++)
                temp=temp->next;
            class Node *temp2=temp->next;
            temp->next=temp2->next;
            delete(temp2);
            sz--;
        }
        void rev()
        {
            class Node *current,*next,*prev;
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
        int length()
        {
            return sz;
        }
        void print()
        {
            if(sz==0)
            {
                cout<<"Empty"<<endl;
                return ;
            }
            class Node *temp=head;
            while(temp!=NULL)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
};
int main()
{
    LinkedList ls;
    ls.Add(10);
    ls.Add(20);
    ls.Add(30);
    ls.print();
    cout<<ls.length()<<endl;
    ls.insert(1,1);
    ls.insert(2,2);
    ls.print();
    cout<<ls.length()<<endl;
    ls.del(2);
    ls.print();
    cout<<ls.length()<<endl;
    return 0;
}