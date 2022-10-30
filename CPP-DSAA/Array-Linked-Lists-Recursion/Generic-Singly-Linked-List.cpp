#include<iostream>
using namespace std;
template<typename E>
class SNode{    //singly linked list node
    private:
    E elem; //linked list element node
    SNode<E>* next; //next item in the list
    friend class SLinkedList<E>;    //provide SLinedList access
};
template<typename E>
class SLinkedList{
    private:
    SNode<E>* head;
    public:
    SLinkedList();
    ~SLinkedList();
    bool empty() const;
    const E& front() const;
    void addFront(const E& e);
    void removeFront();
};
template<typename E> SLinkedList<E>::SLinkedList():head(NULL)
{

}
template<typename E> bool SLinkedList<E>::empty() const{
    return head==NULL;
}
template<typename E> const E& SLinkedList<E>::front() const{
    return head->elem;
}
template<typename E> SLinkedList<E>::~SLinkedList(){
    while(!empty())
    {
        removeFront();
    }
}
template<typename E> void SLinkedList<E>::addFront(const E& e)
{
    SNode<E>* v=new SNode<E>;
    v->elem=e;
    v->next=head;
}
template<typename E> void SLinkedList<E>::removeFront()
{
    SNode<E>* old=head;
    head=old->next;
    delete old;
}
int main()
{
    SLinkedList<string> a;
    a.addFront("Raihan");
    a.addFront("David");
    a.addFront("Mystogun");
    a.addFront("Shank");
    cout<<a.front();
    return 0;
}