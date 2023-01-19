#include<stdio.h>
#include<stdlib.h>
int find(int arr[],int n,int k)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==k)
            return i;
    }
   
    return -1;
}
int cmp(const void *a, const void *b)
{
    return (*(int *)a-*(int *)b);
}
int binarySearch(int arr[],int size,int element)
{
    // qsort(arr,10,sizeof(int),cmp);
    int low,mid,high;
    low=0;
    high=size-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==element)
        {
            return mid;
        }
        if(arr[mid]<element)
        {
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return -1;
}
int main()
{
    int arr[10],i;
    for(i=0;i<10;i++)
        scanf("%d",&arr[i]);
    int k;
    scanf("%d",&k);
    int linearSearch=find(arr,10,k);
    if(linearSearch==-1)
    {
        printf("Not found\n");
    }else{
        printf("element at %d\n",linearSearch);
    }
    for(i=0;i<10;i++)
        scanf("%d",&arr[i]);
    scanf("%d",&k);
    printf("binary search %d",binarySearch(arr,10,k));
    return 0;
}