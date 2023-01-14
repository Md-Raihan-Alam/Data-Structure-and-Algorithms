#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node* top=NULL;
int isEmpty(struct Node* top)
{
    if(top==NULL)
    {
        return 1;
    }
    return 0;
}
int isFull(struct Node* top)
{
    struct Node* p=(struct Node*)malloc(sizeof(struct Node));
    if(p==NULL)
    {
        return 1;
    }
    return 0;
}
struct Node* push(struct Node *top,int x)
{
    if(isFull(top))
    {
        printf("Stack is full\n");
        
    }else{
        struct Node* n=(struct Node*)malloc(sizeof(struct Node));
        n->data=x;
        n->next=top;
        top=n;
        return top;
    }
}
int pop(struct Node *tp)
{
    if(isEmpty(tp))
    {
        printf("empty");
        return 0;
    }
    struct Node* n=tp;
    top=tp->next;
    int x=n->data;
    free(n);
    return x;
}
int peek(int pos)
{
    struct Node *ptr=top;
    for(int i=0;(i<pos-1 && ptr!=NULL);i++)
    {
        ptr=ptr->next;
    }
    if(ptr!=NULL)
    {
        return ptr->data;
    }
    return -1;
}
void bottom()
{
    if(top==NULL)
    {
        return ;
    }
    struct Node* ptr=top;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
            printf("%d ",ptr->data);
    printf("\n");
}
void stackTop()
{
    if(top==NULL)
    {
        return ;
    }
    printf("%d \n",top->data);
}
//double pointer - dereferencing
// int pop(struct Node **top)
// {
//     if(isEmpty(*top))
//     {
//         printf("empty");
//         return 0;
//     }
//     struct Node* n=*top;
//     *top=*top->next;
//     int x=n->data;
//     free(n);
//     return x;
// }
void print(struct Node *s)
{
    while(s!=NULL)
    {
        printf("%d ",s->data);
        s=s->next;
    }
    printf("\n");
}
int main()
{
    top=push(top,78);
    top=push(top,10);
    top=push(top,98);
    top=push(top,100);
    print(top);
    // int ele=pop(&top);//double pointer - derefence
    int ele=pop(top);
    printf("pop: %d\n",ele);
    print(top);
    printf("peek at 2 :%d \n",peek(2));
    stackTop();
    bottom();
    return 0;
}