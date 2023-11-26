#include<stdio.h>
#include<stdlib.h>
struct Node
{
    char data;
    struct Node *next;
}*top=NULL;
void Push(char x)
{
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));
    if(t==NULL){
        printf("Stack is full\n");
        return ;
    }
    t->data=x;
    t->next=top;
    top=t;
}
char Pop()
{
    struct Node *t;
    char x;
    if(top==NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    t=top;
    top=top->next;
    x=t->data;
    free(t);
    return x;
}
char Top()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return -1; 
    }

    return top->data;
}
void Display()
{
    struct Node *p;
    p=top;
    while(p!=NULL)
    {
        printf("%c ",p->data);
        p=p->next;
    }
    printf("\n");
}
char PeekAtIndex(int index)
{
    struct Node *p = top;
    int count = 1;

    while (p != NULL && count < index)
    {
        p = p->next;
        count++;
    }

    if (p == NULL || index<=0)
    {
        printf("Index %d is out of bounds.\n", index);
    }else
        return p->data;
}
int main()
{
    Push('a');
    Push('b');
    Push('c');
    Display();
    printf("%c \n",Pop());
    Display();
    Push('d');
    Push('e');
    Push('f');
    printf("%c\n",PeekAtIndex(5));
    printf("%c\n",Top());
    return 0;
}