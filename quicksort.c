//generate random nos in a file,use that file for input and quicksort array in another file.

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void quickSort(int arr[], int start, int end)
{
    if(start < end)
    {
        int pIndex = partition(arr, start, end);
        quickSort(arr, start, pIndex-1);
        quickSort(arr, pIndex+1, end);
    }
}

int partition(int arr[], int start, int end)
{
    int pIndex = start;
    int pivot = arr[end];
    int i;
    for(i = start; i < end; i++)
    {
        if(arr[i] < pivot)
        {
            swap(&arr[i], &arr[pIndex]);
            pIndex++;
        }
    }
    swap(&arr[end], &arr[pIndex]);
    return pIndex;
}

void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}



int main()
{
    FILE *fp;
    fp=fopen("info.txt","w");
    int ch=1,n=0,a[100];
    if(fp==NULL)
    {
        printf("\nError in creating the file\n");
        exit(1);
    }
    printf("\nEnter no of numbers\n");
    int no,num;
    scanf("%d",&no);
     srand(time(0));
    while(n!=no)
    {
        
       
        num=rand()%1000;
        fprintf(fp,"%d\n",rand()%1000);
        n++;
    }
    fclose(fp);
    fp=fopen("info.txt","r");
    
    for(int i=0;i<no;i++)
    {
        fscanf(fp,"%d\n",&a[i]);
    }
    printf("\nArray before sorting\n");
    for(int i=0;i<n;i++)
    {
        printf("%d   ",a[i]);
    }
    fclose(fp);

    quickSort(a,0,n-1);

    printf("\nAfter the QuickSort\n");

    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");

    return 0;

}
