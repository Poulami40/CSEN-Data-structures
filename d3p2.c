/*Doubly linked list
1)Creation
2)Traversal
3)Inserion:i)beginning ii)end 
4)Deletion:i)beginning ii)end */

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node*head=NULL;
void creation()
{ 
    struct node*ptr,*newnode;
    int n;
    printf("\nEnter elements");
    while(1)
    {
        scanf("%d",&n);
        newnode=(struct node*)malloc(sizeof(struct node));
        if(n==-1)
        break;
        else{
            newnode->data=n;
            newnode->next=NULL;
            newnode->prev=NULL;
            if(head==NULL)
            {
                head=newnode;
                ptr=head;
                head->prev=NULL;
            }
            else
            {
                ptr->next=newnode;
                newnode->prev=ptr;
                ptr=ptr->next;
            }
            ptr->next=NULL;
        }
    }
}
void traversalb()
{
    struct node*ptr;
    printf("\nLinked list from begin:\n");
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
}
void traversale()
{
    struct node*ptr;
    printf("\nLinked list from end:\n");
    ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    while(ptr!=NULL)
    {
        printf("%d",ptr->data);
        ptr=ptr->prev;
    }
}
void insertbegin()
{
    struct node *ptr=NULL;
    ptr=(struct node*)malloc(sizeof(struct node));
    int d;
    printf("\nEnter data");
    scanf("%d",&d);
    ptr->data=d;
    ptr->next=head;
    ptr->prev=NULL;
    ptr->next->prev=ptr;
    head=ptr;
}
void insertend()
{
    struct node *ptr=NULL,*temp=NULL;
    temp=(struct node*)malloc(sizeof(struct node));
    int d;
    printf("\nEnter data");
    scanf("%d",&d);
    temp->data=d;
    temp->next=NULL;
    ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=temp;
    temp->prev=ptr;
}

void deletebegin()
{
    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp=head;
    head=head->next;
    head->prev=NULL;
    free(temp);
}
void deletend()
{
    struct node *temp,*ptr1,*ptr2;
    if(head==NULL)
    printf("\nList is empty");
    else{
    temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    ptr2=temp->next;
    free(ptr2);
    temp->next=NULL;
    }
}

int main()
{
    int ch,po;
    while(ch){
    printf("\n1)Creation 2)Traversal 3)Insertion 4)Deletion ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        creation();
        break;
        case 2:
        traversalb();
        traversale();
        break;
       
        case 3:
        printf("\n1)Beginning 2)End");
        scanf("%d",&po);
        switch(po)
        {
            case 1:
            insertbegin();
            break;
            case 2:
            insertend();
            break;
        }
        break;
         case 4:
        printf("\n1)Beginning 2)End");
        scanf("%d",&po);
        switch(po)
        {
            case 1:
            deletebegin();
            break;
            case 2:
            deletend();
            break;
        }
        break;
        default:
        printf("\nInvalid choice");
        break;
    }
    }
}
