#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *first=NULL;
struct Node *second=NULL;
struct Node *third=NULL;
//turning array into linked list
void create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void create2(int A[],int n)
{
    int i;
    struct Node *t,*last;
    second=(struct Node*)malloc(sizeof(struct Node));
    second->data=A[0];
    second->next=NULL;
    last=second;
    for(int i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
//display linked list->loop method
void Display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
void RecursiveDisplay(struct Node *p)
{
    if(p!=NULL)
    {
        printf("%d ",p->data);
        RecursiveDisplay(p->next);
    }
}
//reverse display
void ReverseDisplay(struct Node *p)
{
    if(p!=NULL)
    {
        RecursiveDisplay(p->next);
        printf("%d ",p->data);
    } 
}
int count(struct Node *p)
{
    int cnt=0;
    while(p!=NULL)
    {
        cnt++;
        p=p->next;
    }
    return cnt;
}
int Rcount(struct Node *p)
{
    if(p!=NULL)
        return Rcount(p->next)+1;
    else    
        return 0;
}
int sum(struct Node *p)
{
    int s=0;
    while(p!=NULL)
    {
        s+=p->data;
        p=p->next;
    }
    return s;
}
int Rsum(struct Node *p)
{
    if(p!=NULL)
    {
        return p->data+(Rsum(p->next));
    }else{
        return 0;
    }
}
int max_element(struct Node *p)
{
    int max=INT_MIN;
    while(p)
    {
        if(p->data>max)
            max=p->data;
        p=p->next;
    }
    return max;
}
int min_element(struct Node *p)
{
    int min=INT_MAX;
    while(p)
    {
        if(p->data<min)
            min=p->data;
        p=p->next;
    }
    return min;
}
struct Node * LSearch(struct Node *p,int key)
{
    struct Node * q;
    while(p!=NULL)
    {
        if(key==p->data)
        {
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}
struct Node * RSearch(struct Node *p,int key)
{
    if(p==NULL)
        return NULL;
    if(key==p->data)
        return p;
    RSearch(p->next,key);
}
void InsertBefore(struct Node *p,int index,int x)
{
    if(index<0 || index>count(p))
    {
        return;
    }
    struct Node *t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    if(index==0)
    {
        t->next=first;
        first=t;
    }
    else{
        int i;
        for(i=0;i<index-1;i++)
            p=p->next;
        t->next=p->next;
        p->next=t;
    }
}
void InsertLast(int x)
{
    struct Node * t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
    if(first==NULL)
    {
        first=t;
    }else{
        struct Node *p=first;
        while(p->next!=NULL)
        {
            // printf("%d ",p->data);
            p=p->next;
        }
        p->next=t;
    }
}
void InsertSorted(struct Node *p,int x)
{
    struct Node *t,*q=NULL;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
    if(first==NULL)
    {
        first=t;
    }else{
        while(p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p==first)
        {
            t->next=first;
            first=t;
        }else{
            t->next=q->next;
            q->next=t;
        }
    }
}
int Delete(struct Node *p,int pos)
{
    struct Node *q;
    int x;
    if(pos<1 || pos>count(first))
        return -1;
    if(pos==1)
    {
        q=first;
        first=first->next;
        x=q->data;
        free(q);
        return x;
    }
    int i;
    for(i=0;i<pos-1 && p;i++)
    {
        q=p;
        p=p->next;
    }
    q->next=p->next;
    x=p->data;
    free(p);
    return x;
}
int isSorted(struct Node* p)
{
    int x=INT_MIN;
    while(p!=NULL)
    {
        if(p->data<x)
            return 0;
        x=p->data;
        p=p->next;
    }
    return 1;
}
void removeDuplicate(struct Node *p)
{
    struct Node *q=p->next;
    while(q!=NULL)
    {
        if(p->data!=q->data)
        {
            p=q;
            q=q->next;
        }else
        {
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }
}
void Reverse1(struct Node *p)
{
    int *A,i=0;
    struct Node *q=p;
    A=(int *)malloc(sizeof(int)*count(p));
    while(q!=NULL)
    {
        A[i]=q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;
    while(q!=NULL)
    {
        q->data=A[i];
        q=q->next;
        i--;
    }
}
void Reverse2(struct Node *p)
{
    struct Node *q=NULL,*r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}
void Reverse3(struct Node *q,struct Node *p)
{
    if(p)
    {
        Reverse3(p,p->next);
        p->next=q;
    }else{
        first=q;
    }
}
void Concat(struct Node *p,struct Node *q)
{
    third=p;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=q;
}
void Merge(struct Node *p,struct Node *q)
{
    struct Node *last;
    if(p->data<q->data)
    {
        third=last=p;
        p=p->next;
        third->next=NULL;
    }else{
        third=last=q;
        q=q->next;
        third->next=NULL;
    }
    while(p && q)
    {
        if(p->data < q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }else{
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p)
    {
        last->next=p;
    }
    if(q){
        last->next=q;
    }
}
int isLoop(struct Node *f)
{
    struct Node *p,*q;
    p=q=f;
    do{
        p=p->next;
        q=q->next;
        q=q?q->next:q;
    }while(p && q && p!=q);
    if(p==q)
        return 1;
    return 0;
}
int main()
{
    // int A[]={3,3,3,5,7,7,7,10,20,20,20};
    int A[]={10,20,30,40,50};
    // int A2[]={50,40,10,30,70};
    // int A[]={3,3,3};
    create(A,5);
    // create2(A2,5);
    Display(first);
    printf("\n");
    // Display(second);
    // printf("\n");
    // RecursiveDisplay(first);
    // printf("\n");
    // ReverseDisplay(first);
    // printf("\n");
    // printf("Length = %d %d\n",count(first),Rcount(first));
    // printf("Sum = %d %d\n",sum(first),Rsum(first));
    // printf("Max = %d %d\n",max_element(first),min_element(first));
    // struct Node * temp=LSearch(first,10);
    // if(temp)
    // {
    //     printf("Key is found %d\n",temp->data);
    // }else{
    //     printf("Key is not found\n");
    // }
    // Display(first);
    // printf("\n");
    // InsertBefore(first,0,15);
    // Display(first);
    // printf("\n");
    // InsertBefore(first,3,70);
    // Display(first);
    // printf("\n");
    // InsertLast(5);
    // Display(first);
//     printf("\n");
//     InsertLast(7);
//     Display(first);
//     printf("\n");
    // Delete(first,4);
    // Display(first);
    // printf("\n");
    // if(isSorted(first))
    // {
    //     printf("Sorted\n");
    // }else{
    //     printf("Not sorted\n");
    // }
    // removeDuplicate(first);
    // Display(first);
    // printf("\n");
    // Reverse1(first);
    // Reverse2(first);
    // Reverse3(NULL,first);
    // Display(first);
    // printf("\n");
    // Concat(first,second);
    // Display(third);
    // Merge(first,second);
    // Display(third);
    // printf("\n");
    //loop created
    // struct Node *t1,*t2;
    // t1=first->next->next;
    // t2=first->next->next->next->next;
    // t2->next=t1;
    printf("%d\n",isLoop(first));
    return 0;
}