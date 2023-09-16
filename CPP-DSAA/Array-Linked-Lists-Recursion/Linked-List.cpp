#include<iostream>
#include<limits.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
};
class LinkedList{
    private:
        Node *first;
        Node *second;
        Node *third;
    public:
        LinkedList(){
            first=NULL;
        }
        void createFromArray(int A[],int n){
            int i;
            Node *last,*t;
            first=new Node;
            first->data=A[0];
            first->next=NULL;
            last=first;
            for(int i=1;i<n;i++)
            {
                t=new Node;
                t->data=A[i];
                t->next=NULL;
                last->next=t;
                last=t;
            }
        }
        ~LinkedList(){
            Node *p=first;
            while(first)
            {
                first=first->next;
                delete p;
                p=first;
            }
        }
        void Display(){
            Node *p=first;
            while(p!=NULL)
            {
                cout<<p->data<<" ";
                p=p->next;
            }
            cout<<endl;
        }
        int Count()
        {
            int cnt=0;
            Node *p=first;
            while(p!=NULL)
            {
                p=p->next;
                cnt++;
            }
            return cnt;
        }
        int Sum()
        {
            int sum=0;
            Node *p=first;
            while(p!=NULL)
            {
                sum+=p->data;
                p=p->next;
            }
            cout<<sum<<endl;
        }
        int max_element()
        {
            int mx=INT_MIN;
            Node *p=first;
            while(p!=NULL)
            {
                mx=max(mx,p->data);
                p=p->next;
            }
            cout<<mx<<endl;
        }
        int mn_element()
        {
            int mn=INT_MAX;
            Node *p=first;
            while(p!=NULL)
            {
                mn=min(mn,p->data);
                p=p->next;
            }
            cout<<mn<<endl;
        }
        void Search(int target)
        {
            Node *p=first;
            while(p!=NULL)
            {
                if(p->data==target)
                {
                    cout<<p<<endl;
                    return ;
                }
                p=p->next;
            }
            cout<<"Not found"<<endl;
        }
        void InsertBefore(int index, int x)
        {
            if(index<0 || index >Count())
            {
                cout<<"out of bound"<<endl;
                return ;
            }
            Node *p=new Node;
            p->data=x;
            Node *node=first;
            if(index==0)
            {
                p->next=first;
                first=p;
                return ;
            }
            for(int i=0;i<index-1;i++)
                node=node->next;
            p->next=node->next;
            node->next=p;
        }
        void InsertLast(int x)
        {
            Node *p=new Node;
            Node *node=first;
            p->data=x;
            p->next=NULL;
            if(node==NULL)
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
            Node *p=new Node;
            p->next=NULL;
            p->data=x;
            Node *node=first;
            Node *secondNode=NULL;
            if(node==NULL)
            {
                first=p;
                return ;
            }
            while(node && node->data<x)
            {
                secondNode=node;
                node=node->next;
            }
            if(node==first)
            {
                p->next=first;
                first=node;
                return ;
            }
            p->next=secondNode->next;
            secondNode->next=p;
        }
        int Delete(int pos)
        {
            Node *node=first;
            Node *q;
            int x;
            if(pos<0 || pos>Count()-1)
            {
                return -1;
            }
            if(pos==0)
            {
                q=first;
                first=first->next;
                x=q->data;
                delete q;
                return x;
            }
            for(int i=0;i<pos && node;i++)
            {
                q=node;
                node=node->next;
            }
            q->next=node->next;
            x=node->data;
            delete node;
            return x;
        }
        bool isSorted()
        {
            int x=INT_MIN;
            Node *node=first;
            while(node->next!=NULL)
            {
                if(node->data<x)
                    return 0;
                x=node->data;
                node=node->next;
            }
            return 1;
        }
        void Reverse()
        {
            Node *p=first;
            Node *q=NULL,*r=NULL;
            while(p!=NULL)
            {
                r=q;
                q=p;
                p=p->next;
                q->next=r;
            }
            first=q;
        }
        void Concat(LinkedList& otherList) {
        Node* current = first;
        
        if (!current) {
            // If the current list is empty, simply point the first node
            // of the current list to the first node of the other list.
            first = otherList.first;
        } else {
            // Traverse the current list to find its last node.
            while (current->next) {
                current = current->next;
            }
            
            // Append the first node of the other list to the end of the current list.
            current->next = otherList.first;
        }
        
        // Reset the other list to an empty state.
        otherList.first = nullptr;
        }
    bool hasLoop() {
        Node* p = first;
        Node* q = first;

        while (p && q && q->next) {
            p = p->next;
            q = q->next->next;

            if (p == q) {
                return true;
            }
        }

        return false;
    }
    //below functions ,better if linked list is sorted
    void Merge(LinkedList& otherList) {
        Node* p = first;
        Node* q = otherList.first;
        Node* last = nullptr;

        if (!p) {
            first = q;
        } else if (!q) {
            // No need to merge if one of the lists is empty.
            return;
        } else {
            if (p->data < q->data) {
                last = third = p;
                p = p->next;
                third->next = nullptr;
            } else {
                last = third = q;
                q = q->next;
                third->next = nullptr;
            }
        }

        while (p && q) {
            if (p->data < q->data) {
                last->next = p;
                last = p;
                p = p->next;
                last->next = nullptr;
            } else {
                last->next = q;
                last = q;
                q = q->next;
                last->next = nullptr;
            }
        }

        if (p) {
            last->next = p;
        }

        if (q) {
            last->next = q;
        }

        // Reset the other list to an empty state.
        otherList.first = nullptr;
    }
        void InsertSorted(int x) {
        Node* t = new Node;
        t->data = x;
        t->next = nullptr;

        if (first == nullptr) {
            // If the list is empty, make the new node the first node.
            first = t;
        } else {
            Node* p = first;
            Node* q = nullptr;

            while (p && p->data < x) {
                q = p;
                p = p->next;
            }

            if (p == first) {
                // If the new node should be inserted at the beginning.
                t->next = first;
                first = t;
            } else {
                // Insert the new node in the middle or at the end.
                t->next = q->next;
                q->next = t;
            }
        }
    }
     void removeDuplicates() {
        Node* p = first;

        while (p && p->next) {
            if (p->data == p->next->data) {
                // Duplicate node found; remove it.
                Node* q = p->next;
                p->next = q->next;
                delete q;
            } else {
                p = p->next;
            }
        }
    }
};
int main()
{
    int A[5]={2,5,7,10,14};
    LinkedList L;
    LinkedList L2;
    int B[3]={32,54,67};
    L.createFromArray(A,5);
    L2.createFromArray(B,3);
    L.Display();
    cout<<L.Count()<<endl;
    L.Sum();
    L.max_element();
    L.mn_element();
    L.Search(5);
    L.InsertBefore(2,6);
    L.Display();
    L.InsertLast(20);
    L.Display();
    L.Delete(6);
    L.Display();
    cout<<L.isSorted()<<endl;
    L.Reverse();
    L.Display();
    L2.Display();
    L.Concat(L2);
    L.Display();
    return 0;
}