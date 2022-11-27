#include <stdio.h>
int *insertion(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        int key=a[i];
        int j=i-1;
        while(j>=0&&a[j]>key)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=key;
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
    int *sort=insertion(a,n);
    printf("\nAfter sort\n");
    print(sort,n);
}