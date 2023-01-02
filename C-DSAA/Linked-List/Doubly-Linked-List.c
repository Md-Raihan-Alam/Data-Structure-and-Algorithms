#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};
int sz=0;
struct Node *head,*tail;//global variable - pointer to head node
struct Node* GetNewNode(int x)
{
    // //local variable
    // //will be cleared from memory when function is called
    // struct Node myNode;
    // myNode.data=x;
    // myNode.prev=NULL;
    // myNode.next=NULL;
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=x;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}
void insert(int x)
{
    struct Node* temp=GetNewNode(x);
    if(head==NULL)
    {
        sz++;
        head=temp;
        tail=temp;
        return ;
    }
    sz++;
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}
void insertAtHead(int x)
{
    struct Node* temp=GetNewNode(x);
    if(head==NULL)
    {
        sz++;
        head=temp;
        tail=temp;
        return ;
    }
    sz++;
    head->prev=temp;
    temp->next=head;
    head=temp;
}
void insertAtTail(int x)
{
    struct Node* temp=GetNewNode(x);
    if(head==NULL)
    {
        sz++;
        head=temp;
        tail=temp;
        return ;
    }
    sz++;
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}
void insertAtPos(int x,int pos)
{
    if(pos<1 || pos>sz)
    {
        printf("INVALID\n");
        return ;
    }
    if(pos==1)
    {
        insertAtHead(x);
    }
    struct Node* temp=GetNewNode(x);
    struct Node* temp2=head;
    int i=1;
    while(i<pos-1)
    {
        temp2=temp2->next;
        i++;
    }
    sz++;
    temp->prev=temp2;
    temp->next=temp2->next;
    temp2->next=temp;
    temp->next->prev=temp;
}
void insertAfterPos(int x,int pos)
{
    if(pos<1 || pos>sz)
    {
        printf("INVALID\n");
        return ;
    }
    struct Node* temp=GetNewNode(x);
    struct Node* temp2=head;
    int i=1;
    while(i<pos)
    {
        temp2=temp2->next;
        i++;
    }
    sz++;
    temp->prev=temp2;
    temp->next=temp2->next;
    temp2->next=temp;
    temp->next->prev=temp;
}
void deleteHead()
{
    struct Node* temp=head;
    if(head==NULL)
    {
        printf("List is empty\n");
        return ;
    }
    temp=head;
    head=head->next;
    head->prev=NULL;
    free(temp);
    sz--;
}
void deleteTail()
{
    struct Node* temp;
    if(tail==NULL)
    {
        printf("List is empty\n");
        return ;
    }
    temp=tail;
    tail->prev->next=NULL;
    tail=tail->prev;
    free(temp);
    sz--;
}
void deleteAtPos(int pos)
{
    int i=1;
    struct Node* temp=head;
    if(sz==0)
    {
        printf("list is empty\n");
        return ;
    }
    if(pos==1)
    {
        deleteHead();
        return ;
    }
    if(pos==sz)
    {
        deleteTail();
        return ;
    }
    while(i<pos)
    {
        i++;
        temp=temp->next;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
    sz--;
}
void print()
{
    struct Node* temp=head;
    printf("Forward: ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void reversePrint()
{
    struct Node* temp=tail;
    if(temp==NULL) return ;//empty list,exit
    //travering backward using prev pointer
    printf("Reverse: ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->prev;
    }
    printf("\n");
}
int main()
{
    head=NULL;//empty list
    insertAtHead(2);
    insert(10);
    insertAtTail(3);
    print();
    reversePrint();
    insertAtHead(4);
    insertAtTail(5);
    print();
    reversePrint();
    insertAtHead(6);
    insertAtTail(7);
    print();
    reversePrint();
    insertAtPos(11,3);
    print();
    reversePrint();
    insertAfterPos(20,5);
    print();
    reversePrint();
    deleteHead();
    print();
    reversePrint();
    deleteTail();
    print();
    reversePrint();
    deleteAtPos(3);
    print();
    reversePrint();
    printf("%d\n ",sz);
    return 0;
}