#include<stdio.h>
#include<stdlib.h>
int sz=0;
struct Node{
    int data;
    struct Node *next;
};
struct Node *head=NULL;
void Print()
{
    struct Node *ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
void insertAtHead(int x)
{
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=x;
    if(head==NULL)
    {
        head=newNode;
        newNode->next=NULL;
        sz++;
        return ;
    }
    newNode->next=head;
    head=newNode;
    sz++;
    return ;
}
void insertAtEnd(int x)
{
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=x;
    struct Node *temp=head;
    if(temp==NULL)
    {
        head=newNode;
        newNode->next=NULL;
        sz++;
        return ;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->next=NULL;
    sz++;
    return ;
}
void insertAfterGivenPosition(int x,int pos)
{
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=x;
    struct Node *temp=head;
    if(pos>sz || pos<1)
    {
        printf("Invalid\n");
        return ;
    }
    int i=1;
    while(i<pos)
    {
        temp=temp->next;
        i++;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    sz++;
    return ;
}
void deleteBegin()
{
    if(head==NULL)
    {
        printf("Empty\n");
        return ;
    }
    struct Node *temp=head;
    head=head->next;
    free(temp);
    sz--;
    return ;
}
void deleteEnd()
{
    if(head==NULL)
    {
        printf("Empty\n");
        return ;
    }
    struct Node *temp=head;
    struct Node *prev;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==head)
    {
        head=NULL;
        free(temp);
        sz--;
        return ;
    }
    prev->next=NULL;
    free(temp);
    sz--;
    return ;
}
void deletePos(int pos)
{
    if(pos<1 || pos>sz || sz==0)
    {
        printf("Invalid\n");
        return ;
    }
    if(pos==1)
    {
        deleteBegin();
        return ;
    }
    if(pos==sz)
    {
        deleteEnd();
        return ;
    }
    struct Node *nextNode;
    int i=1;
    struct Node *temp=head;
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    nextNode=temp->next;
    temp->next=nextNode->next;
    free(nextNode);
    sz--;
    return ;
}
void reverse()
{
    struct Node *prev,*curr,*next;
    prev=NULL;
    curr=head;
    next=head;
    while(next!=NULL)
    {
        next=next->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
}
int main()
{
    insertAtHead(5);
    insertAtHead(7);
    insertAtHead(10);
    Print();
    insertAtEnd(11);
    insertAtEnd(25);
    Print();
    insertAfterGivenPosition(12,2);
    Print();
    insertAfterGivenPosition(15,1);
    Print();
    deleteBegin();
    Print();
    deleteEnd();
    Print();
    deletePos(3);
    Print();
    reverse();
    Print();
    insertAfterGivenPosition(20,1);
    Print();
    return 0;
}