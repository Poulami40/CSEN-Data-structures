/*Queue implementation using linked list*/

#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node*next;
};
struct node *front=NULL,*rear=NULL;
void enqueue()
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter data");
    scanf("%d",&temp->data);
    if(temp==NULL)
    printf("\nOverflow");
    else{
        if(front==NULL)
        {
            front=temp;
            rear=temp;
            front->next=NULL;
            rear->next=NULL;
        }
        else
        {
            rear -> next = temp;
			rear = temp;
			rear->next = NULL;
        }
    }
}
void dequeue()
{
    struct node*ptr;
    if(front==NULL)
    printf("\nUnderflow");
    else
    {
        ptr=front;
        front=front->next;
        free(ptr);
    }
}
void display()
{
    printf("\nFRont data:\n%d",front->data);
    printf("\nRear data:\n%d",rear->data);
}
int main()
{
    int ch;
    while(ch)
    {
    printf("\n1)Enqueue 2)Dequeue 3)Display");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        enqueue();
        break;
        case 2:
        dequeue();
        break;
        case 3:
        display();
        break;
        default:
        printf("\nInvalid");
        break;
    }
    }
}
