#include<stdio.h>
#include<stdlib.h>
struct myArray{
    int totalSize;
    int usedSize;
    int *ptr;
};
struct myArray marks;
void createArray(int tSize,int uSize)
{
    marks.totalSize=tSize;
    marks.usedSize=uSize;
    marks.ptr=(int *)malloc(tSize*sizeof(int));
}
void print()
{
    for(int i=0;i<marks.usedSize;i++)
    {
        printf("%d ",marks.ptr[i]);
    }
}
void setVal()
{
    int i;
    for(i=0;i<marks.usedSize;i++)
    {
        printf("Enter element %d:",i+1);
        scanf("%d",&marks.ptr[i]);
    }
}
int Insertation(int arr[],int size,int element,int capacity,int index)
{
    if(size>=capacity)
    {
        return -1;
    }
    for(int i=size-1;i>=index;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index]=element;
    return 1;
}
int deleteionArray(int arr[],int size,int capacity,int index)
{
    if(index>size)
    {
        return -1;
    }
    for(int i=index;i<size-1;i++)
    {
        arr[i]=arr[i+1];
    }
    return 1;
}
void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main()
{
    // createArray(10,2);
    // setVal();
    // print();
    int arr[100]={7,8,12,27,88};
    int size=5,element=45,index=3;
    display(arr,size);
    Insertation(arr,size,element,100,index);
    size++;
    display(arr,size);
    element=45,index=0;
    display(arr,size);
    deleteionArray(arr,size,100,index);
    size--;
    display(arr,size);
    return 0;
}