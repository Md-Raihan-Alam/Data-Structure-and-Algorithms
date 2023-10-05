#include<iostream>
using namespace std;

template<class DT>
class Node {
public:
    DT data;
    Node* next;
    Node* prev;
};

template<class DT2>
class DoublyLinkedList {
private:
    Node<DT2>* first;
public:
    DoublyLinkedList() {
        first = NULL;
    }

    void CreateFromArray(DT2 A[], int n) {
        Node<DT2>* t, * last;
        first = new Node<DT2>;
        first->data = A[0];
        first->prev = first->next = NULL;
        last = first;
        for (int i = 1; i < n; i++) {
            t = new Node<DT2>;
            t->data = A[i];
            t->next = last->next;
            t->prev = last;
            last->next = t;
            last = t;
        }
    }

    void Display() {
        Node<DT2>* p = first;
        while (p) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    int Length() {
        Node<DT2>* p = first;
        int len = 0;
        while (p) {
            len++;
            p = p->next;
        }
        return len;
    }
    void Insert(int index, DT2 x) {
        Node<DT2>* t = new Node<DT2>;
        Node<DT2>* p = first;
        if (index <= 0 || index > Length() + 1) {
            cout << "Invalid" << endl;
            return;
        }
        if (index == 1) {
            t->data = x;
            t->prev = NULL;
            t->next = first;
            if (first)
                first->prev = t;
            first = t;
        }
        else {
            for (int i = 1; i < index ; i++) {
                p = p->next;
            }
            t->data = x;
            t->prev = p;
            t->next = p->next;
            if (p->next) {
                p->next->prev = t;
            }
            p->next = t;
        }
    }

        DT2 Delete(int index)
        {
              Node<DT2>* p = first;
    DT2 x = DT2(); 
    if (index < 1 || index > Length()) {
        cout << "Invalid" << endl;
        return x;
    }
    if (index == 1) {
        first = first->next;
        if (first)
            first->prev = NULL;
        x = p->data;
        delete p;
    }
    else {
        for (int i = 1; i < index; i++) {
            p = p->next;
        }
        p->prev->next = p->next;
        if (p->next) {
            p->next->prev = p->prev;
        }
        x = p->data;
        delete p;
    }
    return x;
        }
        void Reverse()
        {
            Node<DT2> *temp,*node=first;
            while(node!=NULL)
            {
                temp=node->next;
                node->next=node->prev;
                node->prev=temp;
                node=node->prev;
                if(node!=NULL && node->next==NULL)
                    first=node;
            }
        }
};
int main()
{
    float A[5]={2.5,1.2,6.4,8.6,10.23};
    DoublyLinkedList<float> DL;
    DL.CreateFromArray(A,5);
    DL.Display();
    DL.Insert(1,100.32);
    DL.Display();
    DL.Insert(6,90.32);
    DL.Display();
    DL.Insert(4,-32.43);
    DL.Display();
    DL.Delete(1);
    DL.Display();
    DL.Delete(6);
    DL.Display();
    DL.Delete(2);
    DL.Display();
    DL.Reverse();
    DL.Display();
    return 0;
}