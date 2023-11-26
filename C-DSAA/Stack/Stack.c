#include<stdio.h>
#include<stdlib.h>
struct Stack
{
    int size;
    int top;
    int *s;
};
void Create(struct Stack *st)
{
    printf("Enter Size:");
    scanf("%d",&st->size);
    st->top=-1;
    st->s=(int *)malloc(st->size*sizeof(int));
}
void Display(struct Stack st)
{
    int i;
    for(i=st.top;i>=0;i--)
        printf("%d ",st.s[i]);
    printf("\n");
}
void Push(struct Stack *st,int x)
{
    if(st->top==st->size-1){
        printf("Stack Overflow\n");
        return ;
    }
    st->top++;
    st->s[st->top]=x;
}
int Pop(struct Stack *st)
{
    int x=-1;
    if(st->top==-1)
    {
        printf("Stack Overflow\n");
        return x;
    }
    x=st->s[st->top--];
    return x;
}
int peek(struct Stack st,int index)
{
    int x=-1;
    if(st.top-index<0){
        printf("Invalid index\n");
        return x;
    }
    x=st.s[st.top-index];
    return x;
}
int isEmpty(struct Stack st)
{
    if(st.top==-1)
        return 1;
    return 0;
}
int isFull(struct Stack st)
{
    return st.top==st.size-1;
}
int stackTop(struct Stack st)
{
    if(!isEmpty(st))
        return st.s[st.top];
    return -1;
}
int main()
{
    struct Stack st;
    Create(&st);
    Push(&st,10);
    Push(&st,20);
    Push(&st,30);
    Push(&st,40);
    Push(&st,50);
    // Push(&st,60);
    Display(st);
    printf("%d \n",Pop(&st));
    Display(st);
    printf("%d\n",peek(st,2));
    printf("%d\n",stackTop(st));
    return 0;
}