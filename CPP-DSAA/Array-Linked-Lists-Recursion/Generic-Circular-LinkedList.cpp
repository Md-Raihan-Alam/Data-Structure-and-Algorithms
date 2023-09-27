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
};
int main()
{
    char A[5]={'a','b','g','c','n'};
    CircularLinkedList<char> C;
    C.CreateFromArray(A,5);
    C.Display();
}