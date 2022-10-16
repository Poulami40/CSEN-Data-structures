/*Input an array using dynamic memory allocation and find an element in it using sequential search*/

#include <stdio.h>
#include <stdlib.h>
int *allocate(int n)
{
    int *p;
    p=(int*)calloc(n,sizeof(int));
    return p;
}
void read(int *p,int n)
{
    for(int i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
    }
}
int search(int *p,int n,int a)
{
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(p[i]==a)
        c++;
    }
    return c;
}
int main()
{
    int n,*ptr,f,ele;
    printf("\nEnter no of elements");
    scanf("%d",&n);
    ptr=allocate(n);
    printf("\nEnter elements");
    read(ptr,n);
    printf("\nEnter element to search");
    scanf("%d",&ele);
    f=search(ptr,n,ele);
    if(f==0)
    printf("\nElement doesnt exist");
    else
    printf("Element exists");
} 
