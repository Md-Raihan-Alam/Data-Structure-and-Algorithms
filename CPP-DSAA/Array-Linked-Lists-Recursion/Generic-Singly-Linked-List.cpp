#include<iostream>
#include<limits.h>
using namespace std;
template<class DT> class Node{
    public:
        DT data;
        Node *next;
};
template<class DT2> class LinkedList{
    private:
        Node<DT2> *first;
        Node<DT2> *second;
        Node<DT2> *third;
    public:
        LinkedList()
        {
            first=NULL;
        }
        void CreateFromArray(DT2 A[],int n)
        {
            first=new Node<DT2>;
            first->data=A[0];
            first->next=NULL;
            Node<DT2> *t,*last;
            last=first;
            for(int i=1;i<n;i++)
            {
                t=new Node<DT2>;
                t->data=A[i];
                t->next=NULL;
                last->next=t;
                last=t;
            }
        }
        ~LinkedList(){
            Node<DT2> *node=first;
            while(first)
            {
                first=first->next;
                delete node;
                node=first;
            }
        }
        void Display()
        {
            if(first==NULL)
            {
                return ;
            }
            Node<DT2> *node=first;
            while(node!=NULL)
            {
                cout<<node->data<<" ";
                node=node->next;
            }
            cout<<endl;
        }
        int Count()
        {
            int cnt=0;
            Node<DT2> *node=first;
            while(node!=NULL)
            {
                cnt++;
                node=node->next;
            }
            return cnt;
        }
        int Sum()
        {
            int sum=0;
            Node<DT2> *node=first;
            while(node!=NULL)
            {
                sum+=node->data;
                node=node->first;
            }
            return sum;
        }
        DT2 Max_element()
        {
            DT2 mx=first->data;
            Node<DT2> *node=first;
            while(node!=NULL)
            {
                mx=max(node->data,mx);
                node=node->next;
            }
            return mx;
        }
        DT2 Min_element()
        {
            DT2 mn=first->data;
            Node<DT2> *node=first;
            while(node!=NULL)
            {
                mn=min(node->data,mn);
                node=node->next;
            }
            return mn;
        }
        void Search(DT2 target)
        {
            Node<DT2> *node=first;
            while(node!=NULL)
            {
                if(node->data==target)
                {
                    cout<<"found at "<<node<<endl;
                    return ;
                }
                node=node->next;
            }
            cout<<"Not found"<<endl;
        }
        void InsertBefore(int index, DT2 x)
        {
            if(index<1 || index>Count())
            {
                cout<<"Out of bound"<<endl;
                return ;
            }
            Node<DT2> *node=first;
            Node<DT2> *p=new Node<DT2>;
            p->data=x;
            if(index==1)
            {
                p->next=first;
                first=p;
                return ;
            }
            for(int i=1;i<index;i++)
                node=node->next;
            p->next=node->next;
            node->next=p;
        }
        void InsertLast(int x)
        {
            Node<DT2> *node=first;
            Node<DT2> *p=new Node<DT2>;
            p->data=x;
            p->next=NULL;
            if(first==NULL)
            {
                first=p;
                return ;
            }
            while(node->next!=NULL)
            {
                node=node->next;
            }
            node->next=p;
        }
        void InsertSorted(int x)
        {
            Node<DT2> *node=first;
            Node<DT2> *p=new Node<DT2>;
            p->data=x;
            p->next=NULL;
            Node<DT2> *second=NULL;
            if(node==NULL)
            {
                first=p;
                return ;
            }
            while(node && node->data<x)
            {
                second=node;
                node=node->next;
            }
            if(node==first)
            {
                p->next=first;
                first=p;
                return ;
            }
            p->next=second->next;
            second->next=p;
        }
        DT2 Delete(int pos)
        {
            if(pos<0 || pos>Count())
            {
                cout<<"Out of bound"<<endl;
                return DT2(0);
            }
            Node<DT2> *node=first;
            Node<DT2> *p;
            DT2 x;
            if(pos==1)
            {
                p=first;
                first=first->next;
                x=p->data;
                delete p;
                return x;
            }
            for(int i=1;i<pos && node;i++)
            {
                p=node;
                node=node->next;
            }
            p->next=node->next;
            x=node->data;
            delete node;
            return x;
        }
        bool isSorted()
        {
            DT2 x=first->data;
            Node<DT2>* node=first;
            while(node->next!=NULL)
            {
                if(node->data<x)
                {
                    return 0;
                }
                x=node->data;
                node=node->data;
            }
            return 1;
        }
        void Reverse()
        {
            Node<DT2> *p=first;
            Node<DT2> *q=NULL,*r=NULL;
            while(p!=NULL)
            {
                r=q;
                q=p;
                p=p->next;
                q->next=r;
            }
            first=q;
        }
};
int main()
{
    char A[5]={'a','b','g','c','n'};
    LinkedList<char> L;
    L.CreateFromArray(A,5);
    L.Display();
    cout<<L.Count()<<endl;
    L.Search('k');
    L.InsertBefore(1,'z');
    L.Display();
    L.InsertLast('y');
    L.Display();
    L.Delete(3);
    L.Display();
    L.Reverse();
    L.Display();
    return 0;
}