// https://www.alphacodingskills.com/ds/notes/circular-doubly-linked-list-reverse-the-list.php#c1
// https://www.sanfoundry.com/c-program-circular-doubly-linked-list/#:~:text=What%20is%20a%20Circular%20Doubly,sorting%20data%20is%20also%20possible.
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    struct Node* prev;
    int data;
    struct Node* next;
}*head;
int sz=0;
void insertAtHead(int x)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=x;
    if(head==NULL)
    {
        newNode->next=newNode;
        newNode->prev=newNode;
        head=newNode;
        sz++;
        return ;
    }
    head->prev->next=newNode;
    newNode->prev=head->prev;
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
    sz++;
}
void insertAtEnd(int x)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=x;
    if(head==NULL)
    {
        newNode->next=newNode;
        newNode->prev=newNode;
        head=newNode;
        sz++;
        return ;
    }
    head->prev->next=newNode;
    newNode->prev=head->prev;
    newNode->next=head;
    head->prev=newNode;
    sz++;
}
void insertAtPos(int x,int pos)
{
    if(pos<1 || pos>sz)
    {
        printf("Invalid");
        return ;
    }
    if(pos==1)
    {
        insertAtHead(x);
        return ;
    }
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=x;
    struct Node* temp=head;
    struct Node* prev=NULL;
    int i=1;
    while(i<pos)
    {
        prev=temp;
        temp=temp->next;
        i++;
    }
    prev->next=newNode;
    newNode->next=temp;
    sz++;
}
void deleteHead()
{
    if(head==NULL)
    {
        printf("Invalid");
        return ;
    }
    if(sz==1)
    {
        free(head);
        head=NULL;
        sz--;
        return ;
    }
    struct Node*temp=head;
    head->prev->next=head->next;
    head->next->prev=head->prev;
    head=head->next;
    free(temp);
    temp=NULL;
    sz--;
    return ;
}
void deleteEnd()
{
    if(head==NULL)
    {
        printf("Invalid");
        return ;
    }
    if(sz==1)
    {
        free(head);
        head=NULL;
        sz--;
        return ;
    }
    struct Node* temp=head->prev;
    temp->prev->next=head;
    head->prev=temp->prev;
    free(temp);
    temp=NULL;
    sz--;
}
void deleteAtPos(int pos)
{
    if(pos<1 || pos>sz)
    {
        printf("Invalid");
        return ;
    }
    if(pos==1)
    {
        deleteHead();
        return ;
    }
    if(pos==sz)
    {
        deleteEnd();
        return ;
    }
    struct Node *temp=head;
    struct Node *prev=NULL;
    int i=1;
    while(i<pos)
    {
        prev=temp;
        temp=temp->next;
        i++;
    }
    prev->next=temp->next;
    temp->next->prev=prev;
    free(temp);
    temp=NULL;
    sz--;
    return ;
}
void reverseList()
{
    if(head==NULL)
    {
        printf("Invalid");
        return ;
    }
    struct Node* prevNode=head;
    struct Node* tempNode=head;
    struct Node* currNode=head->next;
    prevNode->next=prevNode;
    prevNode->prev=prevNode;
    while(currNode!=head)
    {
        tempNode=currNode->next;
        currNode->next=prevNode;
        prevNode->prev=currNode;
        head->next=currNode;
        currNode->prev=head;
        prevNode=currNode;
        currNode=tempNode;
    }
    head=prevNode;
}
void print()
{
    if(head==NULL)
    {
        printf("Invalid");
        return ;
    }
    struct Node* temp=head;
    while(temp!=head->prev)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);
}
int main()
{
    insertAtHead(4);
    insertAtHead(5);
    insertAtHead(6);
    insertAtHead(7);
    print();
    insertAtEnd(10);
    insertAtEnd(11);
    print();
    insertAtPos(1,3);
    insertAtPos(2,5);
    print();
    deleteHead();
    print();
    deleteEnd();
    print();
    deleteAtPos(3);
    print();
    reverseList();
    print();
    return 0;
}