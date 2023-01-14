//fixed sized arraty
//top element
#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack *ptr)
{
    if(ptr->top==-1)
    {
        return 1;
    }
    return 0;
}
int isFull(struct stack *ptr)
{
    if(ptr->top==ptr->size-1)
    {
        return 1;
    }
    return 0;
}
void push(struct stack *ptr,int val)
{
    if(isFull(ptr))
    {
        printf("Size is full");
        return ;
    }
    ptr->top++;
    ptr->arr[ptr->top]=val;
}
void top(struct stack *ptr){
    if(isEmpty(ptr))
    {
        printf("Empty");
        return;
    }
    printf("%d\n",ptr->arr[ptr->top]);
}
void bottom(struct stack *ptr)
{
    if(isEmpty(ptr))
    {
        printf("Empty");
        return ;
    }
    printf("%d \n",ptr->arr[0]);
}
void pop(struct stack *ptr)
{
    if(isEmpty(ptr))
    {
        printf("Empty\n");
        return ;
    }
    ptr->top--;
}
//from top
int peek(struct stack *ptr,int i)
{
    if(ptr->top-i<0)
    {
        printf("Not a valid position");
        return -1;
    }
    return ptr->arr[ptr->top-i];
}
int main()
{
    // struct stack s;
    // s.size=80;
    // s.top=-1;
    // s.arr=(int *)malloc(s.size*sizeof(int));
    
    struct stack *s=(struct stack *)malloc(sizeof(struct stack));
    s->size=10;
    s->top=-1;
    s->arr=(int *)malloc(s->size*(sizeof(int)));
    printf("Full bool:%d\n",isFull(s));
    printf("Empty bool:%d\n",isEmpty(s));
    push(s,20);
    push(s,19);
    push(s,18);
    push(s,16);
    push(s,11);
    push(s,13);
    push(s,12);
    push(s,17);
    push(s,15);
    printf("Full bool:%d\n",isFull(s));
    printf("Empty bool:%d\n",isEmpty(s));
    pop(s);
    printf("Full bool:%d\n",isFull(s));
    printf("Empty bool:%d\n",isEmpty(s));
    top(s);
    //from top
    for(int j=0,k=s->top;j<=s->top;j++,k--)
    {
        printf("index %d is %d\n",k+1,peek(s,j));
    }
    bottom(s);
    return 0;
}