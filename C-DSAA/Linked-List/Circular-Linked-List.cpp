#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
int sz=0;
struct Node *tail;
// void insert(int x)
// {
//     struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
//     newNode->data=x;
//     if(head==NULL)
//     {
//         head=newNode;
//         temp=newNode;
//         return ;
//     }
//     temp->next=newNode;
//     temp=newNode;
//     temp->next=head;
//     sz++;
// }
void insertAtBegin(int x)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=x;
    if(tail==NULL)
    {
        tail=newNode;
        tail->next=newNode;
        sz++;
        return ;
    }
    newNode->next=tail->next;
    tail->next=newNode;
    sz++;
}
void insertAtEnd(int x)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=x;
    if(tail==NULL)
    {
        tail=newNode;
        tail->next=newNode;
        sz++;
        return ;
    }
    newNode->next=tail->next;
    tail->next=newNode;
    tail=newNode;
    sz++;
}
void insertAtPos(int x,int pos)
{
    if(pos<1 || (pos>sz && sz!=0))
    {
        printf("Invalid\n");
        return ;
    }
    if(pos==1)
    {
        insertAtBegin(x);
        return ;
    }
    if(pos==sz+1)
    {
        insertAtEnd(x);
        return ;
    }
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    struct Node* temp;
    int i=1;
    newNode->data=x;
    temp=tail->next;
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    sz++;
}
void deleteBeg()
{
    struct Node* temp=tail->next;
    if(tail==NULL)
    {
        printf("Invalid");
        return ;
    }
    else if(temp->next==temp)
    {
        tail=NULL;
        free(temp);
        sz--;
        return ;
    }
    tail->next=temp->next;
    free(temp);
    sz--;
}
void deleteEnd()
{
    if(tail==NULL)
    {
        printf("Invalid");
        return ;
    }
    struct Node *current,*previous;
    current=tail->next;
    if(current->next==current)
    {
        tail=NULL;
        free(current);
        sz--;
        return ;
    }
    while(current->next!=tail->next)
    {
        previous=current;
        current=current->next;
    }
    previous->next=tail->next;
    tail=previous;
    free(current);
    sz--;
}
void deleteAtPos(int pos)
{
    if(tail==NULL || pos<1 || pos>sz)
    {
        printf("Invalid");
        return ;
    }
    if(pos==1)
    {
        deleteBeg();
        return ;
    }
    if(pos==sz)
    {
        deleteEnd();
        return ;
    }
    struct Node *current,*nextNode;
    int i=1;
    current=tail->next;
    while(i<pos-1)
    {
        current=current->next;
        i++;
    }
    nextNode=current->next;
    current->next=nextNode->next;
    free(nextNode);
    sz--;
}
void reverseList()
{
    struct Node *current,*prev,*nextNode;
    if(tail==NULL)
    {
        printf("Empty");
        return ;
    }
    current=tail->next;
    nextNode=current->next;
    while(current!=tail)
    {
        prev=current;
        current=nextNode;
        nextNode=current->next;
        current->next=prev;
    }
    nextNode->next=tail;
    tail=nextNode;
}
void print()
{
    struct Node* temp=tail->next;
    while(temp->next!=tail->next)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d ",temp->data);
    printf("\n");
}
int main()
{
    // insertAtBegin(1);
    // insertAtEnd(5);
    // print();
    // insertAtBegin(2);
    // insertAtEnd(7);
    // print();
    // insertAtBegin(4);
    // insertAtEnd(3);
    // print();
    // insertAtPos(10,2);
    // print();
    // insertAtPos(11,4);
    // print();
    // deleteBeg();
    // print();
    // deleteEnd();
    // print();
    // deleteAtPos(3);
    // print();
    // reverseList();
    // print();
    insertAtPos(5,1);
    insertAtPos(5,1);
    print();
    return 0;
}