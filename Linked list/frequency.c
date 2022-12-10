#include <stdio.h>
#include <stdlib.h>
int* allocate(int n)
{
        int* a=(int*)calloc(n,sizeof(int));
        return a;
}
void read(int *a,int n)
{
    printf("\nEnter elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
int frequency(int* a,int n)
{
    int result=0;
    for(int i=0;i<n;i++)
    {
        result=result^a[i];
    }
    return result;
}
int main()
{
    const int l;
    printf("\nEnter no of elements\n");
    scanf("%d",&l);
    int *a=allocate(l);
    read(a,l);
    printf("\nElement occuring once is %d",frequency(a,l));
}
