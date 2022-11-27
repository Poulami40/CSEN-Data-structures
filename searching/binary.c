#include <stdio.h>
#include <stdbool.h>
int binary(int a[],int val,int n)
{
    int low=0;
    int high=n-1;
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(mid==val)
            return val;
        else if(val<mid)
            high=mid-1;
        else 
            low=mid+1;
    }
    return 0;
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
    int res=binary(a,val,n);
    if(res==0)
        printf("\nDoesnt Exists\n");
    else
        printf("\nexist\n");
}
