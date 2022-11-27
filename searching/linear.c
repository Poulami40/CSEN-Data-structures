#include <stdio.h>
#include <stdbool.h>
bool linear(int a[],int l,int val)
{
   
    for(int i=0;i<l;i++)
    {
        if(a[i]==val)
        return true;
    }
    return false;
}
int main()
{
    int n,val;
    printf("\nEnter no of elements\n");
    scanf("%d",&n);
    int a[100];
    printf("\nEnter elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nEnter element to search\n");
    scanf("%d",&val);
    if(linear(a,n,val))
        printf("\nExists\n");
    else
        printf("\nDoesn't exist\n");
}
