#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};
class LinkedList{
    private:
    Node* head;
    public:
    LinkedList(){
        head=nullptr;
    }
    ~LinkedList(){
        Node* current=head;
        while(current!=nullptr)
        {
            Node* next=current->next;
            delete current;
            current=next;
        }
    }
    void append(int data)
    {
        Node* newNode=new Node();
        newNode->data=data;
        newNode->next=nullptr;
        if(head==nullptr)
        {
            head=newNode;
            return ;
        }
        Node* current=head;
        while(current->next!=nullptr)
        {
            current=current->next;
        }
        current->next=newNode;
    }
    void prepend(int data)
    {
        Node* newNode=new Node();
        newNode->data=data;
        newNode->next=head;
        head=newNode;
    }
    void insert(int index,int data)
    {
        Node* newNode=new Node();
        newNode->data=data;
        if(index==0)
        {
            newNode->next=head;
            head=newNode;
            return ;
        }
        Node* current=head;
        for(int i=0;i<index-1;i++)
        {
            if(current==nullptr)
            {
                return ;
            }
            current=current->next;
        }
        newNode->next=current->next;
        current->next=newNode;
    }
    void remove(int index)
    {
        if(head==nullptr)
        {
            return ;
        }
        if(index==0)
        {
            Node* temp=head;
            head=head->next;
            delete temp;
            return ;
        }
        Node* current=head;
        for(int i=0;i<index-1;i++)
        {
            if(current==nullptr || current->next==nullptr)
            {
                return ;
            }
            current=current->next;
        }
        Node* temp=current->next;
        current->next=temp->next;
        delete temp;
    }
    void reverse()
    {
        Node* current=head;
        Node* prev=nullptr;
        Node* next=nullptr;
        while(current!=nullptr)
        {
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        head=prev;
    }
    void print()
    {
        Node* current=head;
        while(current!=nullptr)
        {
            cout<<current->data<<" ";
            current=current->next;
        }
        cout<<endl;
    }
};
int main() {
    LinkedList list;
    list.append(5);
    list.append(10);
    list.append(15);
    list.print();
    list.prepend(0);
    list.insert(3, 7);
    list.print();
    list.remove(2);
    list.print();
    list.reverse();
    list.print();
    
    return 0;
}