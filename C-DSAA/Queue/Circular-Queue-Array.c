#include<stdio.h>
#include<stdlib.h>
struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};
void create(struct Queue *q,int size)
{
    q->size=size;
    q->front=q->rear=0;
    q->Q=(int *)malloc(q->size*sizeof(int));
}
void enqueu(struct Queue *q,int x)
{
    if((q->rear+1)%q->size==q->front)
    {
        printf("Queue is full\n");
        return ;
    }
    q->rear=(q->rear+1)%q->size;
    q->Q[q->rear]=x;
}
int dequeue(struct Queue *q)
{
    int x=-1;
    if(q->front==q->rear)
    {
        printf("Queue is empty\n"); 
    }else{
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}
void Display(struct Queue q)
{
    int i=q.front+1;
    do
    {
        printf("%d ",q.Q[i]);
        i=(i+1)%q.size;
    }while(i!=(q.rear+1)%q.size);
    printf("\n");
}
int main()
{
    struct Queue q;
    create(&q,5);
    enqueu(&q,10);
    enqueu(&q,20);
    enqueu(&q,30);
    enqueu(&q,40);
    enqueu(&q,50);
    enqueu(&q,60);
    Display(q);
    printf("%d ",dequeue(&q));
    enqueu(&q,70);
    Display(q);
    return 0;
}