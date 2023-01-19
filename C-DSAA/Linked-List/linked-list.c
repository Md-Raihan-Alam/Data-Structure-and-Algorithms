#include<stdio.h>
#include<stdlib.h>
int sz=0;
struct Node{
    int data;
    struct Node *next;
};
void Print(struct Node *ptr)
{
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
struct Node *insertAtFirst(struct Node *head,int data)
{
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
}
// void Delete(int n)
// {
//     n--;
//     struct Node *temp=head;
//     if(n==0)
//     {
//         head=temp->next;//head now point to second node
//         free(temp);
//         return ;
//     }
//     int i;
//     for(i=0;i<n-1;i++)
//         temp=temp->next;
//     //temp point to (n-1)th Node
//     struct Node *temp2=temp->next;//nth Node
//     temp->next=temp2->next;//(n+1)th Node
//     free(temp2);
// }
// void *Reverse()
// {
//     struct Node *current,*next,*prev;
//     current=head;
//     prev=NULL;
//     while(current!=NULL)
//     {
//         next=current->next;
//         current->next=prev;
//         prev=current;
//         current=next;
//     }
//     head=prev;
// }
int main()
{
    struct Node *head,*second,*third;
    //allocate memory for nodes in the linked list in heap
    head=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node));
    third=(struct Node *)malloc(sizeof(struct Node));
    //link first and second node
    head->data=7;
    head->next=second;
    //llink second and third node
    second->data=11;
    second->next=third;
    //terminate the list at third node
    third->data=66;
    third->next=NULL;
    head=insertAtFirst(head,69);
    Print(head);
    return 0;
}