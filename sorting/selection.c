#include <stdio.h>
int *selection(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            int temp=a[min];
            a[min]=a[i];
            a[i]=temp;
        }
    }
    return a;
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
    int *sort=selection(a,n);
    printf("\nAfter sort\n");
    print(sort,n);
}