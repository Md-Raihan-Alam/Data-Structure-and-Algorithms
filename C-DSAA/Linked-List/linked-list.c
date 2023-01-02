#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct  Node *head;//global variable, can be accessed anywhere
void Add(int x)
{
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=NULL;
    if(head!=NULL)
        temp->next=head;
    head=temp;
}
void Print()
{
    struct Node *temp=head;
    printf("List is: ");
    while(temp!=NULL)
    {
        printf(" %d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void Insert(int data,int n)
{
    n--;
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=NULL;
    if(n==0)
    {
        temp->next=head;
        head=temp;
        return ;
    }
    struct Node* temp2=head;
    for(int i=0;i<n-1;i++)
    {
        temp2=temp2->next;
    }  
    temp->next=temp2->next;
    temp2->next=temp;
}
void Delete(int n)
{
    n--;
    struct Node *temp=head;
    if(n==0)
    {
        head=temp->next;//head now point to second node
        free(temp);
        return ;
    }
    int i;
    for(i=0;i<n-1;i++)
        temp=temp->next;
    //temp point to (n-1)th Node
    struct Node *temp2=temp->next;//nth Node
    temp->next=temp2->next;//(n+1)th Node
    free(temp2);
}
void *Reverse()
{
    struct Node *current,*next,*prev;
    current=head;
    prev=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
}
int main()
{
    head = NULL;//empty list
    // printf("How manu numbers?\n");
    int n,i,x;
    // scanf("%d",&n);
    // for(i=0;i<n;i++)
    // {
    //     printf("Enter the number \n");
    //     scanf("%d",&x);
    //     Add(x);
    // }
    // Print();
    Insert(2,1);//at index 0 value 2
    Insert(3,2);//at index 1 value 3
    Insert(4,1);//at index 0 value 4
    Insert(5,2);//at index 1 value 5
    Print();
    // int d;
    // printf("Enter a postion you want to delete:");
    // scanf("%d",&d);
    // Delete(d);
    // Print();
    Reverse();
    Print();
    return 0;
}