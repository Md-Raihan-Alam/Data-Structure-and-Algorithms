#include <iostream>

template <typename T>
class Node {
public:
    Node* prev;
    T data;
    Node* next;

    Node(T data) : prev(nullptr), data(data), next(nullptr) {}
};

template <typename T>
class CircularDoublyLinkedList {
private:
    Node<T>* first;

public:
    CircularDoublyLinkedList() : first(nullptr) {}

    void Create(T A[], int n) {
        Node<T> *t, *last;
        first = new Node<T>(A[0]);
        first->prev = first->next = first; // Make it circular
        last = first;

        for (int i = 1; i < n; i++) {
            t = new Node<T>(A[i]);
            t->next = last->next;
            t->prev = last;
            last->next = t;
            first->prev = t; // Update the previous of the first node
            last = t;
        }
    }

    void Display() {
        Node<T>* temp = first;
        do {
            std::cout << temp->data << " ";
            temp = temp->next;
        } while (temp != first); // Loop until we reach the first node again
        std::cout << "\n";
    }

    int Length() {
        int len = 0;
        Node<T>* temp = first;
        do {
            len++;
            temp = temp->next;
        } while (temp != first);
        return len;
    }

    void Insert(int index, T x) {
        if (index < 1 || index > Length()) {
            return;
        }

        Node<T>* t;
        Node<T>* p = first;

        if (index == 1) {
            t = new Node<T>(x);
            t->prev = p->prev;
            t->next = p;
            p->prev->next = t;
            p->prev = t;
            if (p == first) {
                first = t; // Update first if inserting at the beginning
            }
            return;
        }

        for (int i = 1; i < index; i++)
            p = p->next;

        t = new Node<T>(x);
        t->prev = p->prev;
        t->next = p;
        p->prev->next = t;
        p->prev = t;
    }

    T Delete(int index) {
        if (index < 1 || index > Length()) {
            std::cout << "Invalid\n";
            return -1;
        }

        T x;
        Node<T>* p = first;

        if (index == 1) {
            p->prev->next = p->next;
            p->next->prev = p->prev;
            if (p == first) {
                first = p->next; // Update first if deleting the first node
            }
            x = p->data;
            delete p;
            return x;
        }

        for (int i = 1; i < index; i++)
            p = p->next;

        p->prev->next = p->next;
        p->next->prev = p->prev;

        x = p->data;

        delete p;

        return x;
    }

    void Reverse() {
      Node<T> *temp, *current=first;

      do{
          temp=current -> next ;
          current -> next=current -> prev ;
          current -> prev=temp ;
          current=current -> prev ;
      }while(current!=first);
    }
};

int main() {
    int A[5] ={10,12,15,42,29};
    
    CircularDoublyLinkedList<int> list;

    list.Create(A,5);

    std::cout << "\nLength is :" << list.Length() << "\n";

    list.Display();

    list.Insert(2,25);

    list.Display();

    list.Insert(6,14);

    list.Display();

    list.Delete(1);

    list.Display();

   list.Delete(6);
   list.Display();

   list.Delete(2);
   list.Display();

   list.Reverse();
   list.Display();

   return 0;

}
