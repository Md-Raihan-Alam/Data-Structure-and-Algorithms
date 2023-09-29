#include<iostream>
using namespace std;
template<class DT> class Node{
    public:
        DT data;
        Node *next;
};
template <class DT2> class CircularLinkedList{
    private:
        Node<DT2> *head;
    public:
        CircularLinkedList()
        {
            head=NULL;
        }
        void CreateFromArray(DT2 A[],int n)
        {
            Node<DT2> *t,*last;
            head=new Node<DT2>;
            head->data=A[0];
            head->next=head;
            last=head;
            for(int i=1;i<n;i++)
            {
                t=new Node<DT2>;
                t->data=A[i];
                t->next=last->next;
                last->next=t;
                last=t;
            }
        }
        void Display()
        {
            Node<DT2> *node=head;
            do{
                cout<<node->data<<" ";
                node=node->next;
            }while(node!=head);
            cout<<endl;
        }
        int Length()
        {
            Node<DT2> *node=head;
            int cnt=0;
            do{
                cnt++;
                node=node->next;
            }while(node!=head);
            return cnt;
        }
        void InsertAt(int index,int x)
        {
            Node<DT2> *node;
            if(index<=0 || index>Length())
            {
                cout<<"Invalid"<<endl;
                return ;
            }
            if(index==1)
            {
                node=new Node<DT2>;
                node->data=x;
                if(head==NULL)
                {
                    head=node;
                    head->next=head;
                    return ;
                }
                Node<DT2> *node2=head;
                while(node2->next!=head)
                    node2=node2->next;
                node2->next=node;
                node->next=head;
                head=node;
                return ;
            }
            Node<DT2> *node2=head;
            for(int i=1;i<index;i++)
                node2=node2->next;
            node=new Node<DT2>;
            node->data=x;
            node->next=node2->next;
            node2->next=node;
        }
        int Delete(int index)
        {
            int x;
            if(index<=0 || index>Length())
            {
                cout<<"Invalid"<<endl;
                return -1;
            }
            if(index==1)
            {
                Node<DT2> *node=head;
                while(node->next!=head)
                {
                    node=node->next;
                }
                x=head->data;
                if(head==node)
                {
                    delete head;
                    head=NULL;
                    return x;
                }
                node->next=head->next;
                delete head;
                head=node->next;
                return x;
            }
            Node<DT2> *node=head,*node2=head;
            for(int i=0;i<index-2;i++)
            {
                node=node->next;
            }
            node2=node->next;
            node->next=node2->next;
            x=node2->data;
            delete node2;
            return x;
        }
};
int main()
{
    char A[5]={'a','b','g','c','n'};
    CircularLinkedList<char> C;
    C.CreateFromArray(A,5);
    C.Display();
    C.InsertAt(1,'z');
    C.Display();
    C.InsertAt(6,'y');
    C.Display();
    C.InsertAt(3,'f');
    C.Display();
    C.Delete(1);
    C.Display();
    C.Delete(7);
    C.Display();
    C.Delete(4);
    C.Display();
}