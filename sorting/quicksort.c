#include <stdio.h>
void swap(int *a,int* b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
int partition(int a[],int start,int end)
{
    int pindex=start;
    int pivot=a[end];
    for(int i=start;i<end;i++)
    {
        if(a[i]<pivot)
        {
            swap(&a[i],&a[pindex]);
            pindex++;
        }
    }
    swap(&a[end],&a[pindex]);
    return pindex;
}

void quicksort(int a[],int start,int end)
{
    if(start<end)
    {
        int pindex=partition(a,start,end);
        quicksort(a,start,pindex-1);
        quicksort(a,pindex+1,end);
    }
}

void print(int *a,int n)
{
    for(int i=0;i<n;i++)
        printf("%d",a[i]);
}
int main()
{
     int n,a[100];
    printf("\nEnter no of elements\n");
    scanf("%d",&n);
    printf("\nEnter elements\n");   
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nBefore sort\n");
    print(a,n);
    quicksort(a,0,n-1);
    printf("\nAfter sort\n");
    print(a,n);
}