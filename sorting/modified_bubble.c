#include <stdio.h>

int* bubble(int a[],int l)
{
    for(int i=0;i<l;i++)
    {
        int test=0;
        for(int j=0;j<l-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                test=1;
            }
        }
        if(test==0)
        break;
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
    int *sort=bubble(a,n);
    printf("\nAfter sort\n");
    print(sort,n);

}