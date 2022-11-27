#include <stdio.h>
#include <stdbool.h>
int interpolation(int a[],int val,int n)
{
    int low=0;
    int high=n-1;
    int mid;
    while(a[low]<=val&&a[high]>=val)
    {
        mid=low+((val-a[low])*(high-low))/(a[high]-a[low]);
        if(mid==val)
            return val;
        else if(val<mid)
            high=mid-1;
        else 
            low=mid+1;
    }
    if(a[low]==val)
    return low;
    else
    return -1;
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
    int res=interpolation(a,val,n);
    if(res)
        printf("\nExists\n");
    else
        printf("\nDoesnt exist\n");
}
