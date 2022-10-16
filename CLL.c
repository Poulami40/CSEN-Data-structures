/*Circular linked list
1)Creation
2)Traversal
3)Insertion i)Beginning ii)End
4)Deletion i)Beginning ii)End*/

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
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
            if(head==NULL)
            {
                head=newnode;
                ptr=head;
            }
            else
            {
                ptr->next=newnode;
                ptr=ptr->next;
            }
            ptr->next=head;
        }
    }
}
void traversal()
{
    struct node*ptr;
    printf("\nLinked list:\n");
    ptr=head;
    printf("%d",ptr->data);
        ptr=ptr->next;
    while(ptr->next!=head)
    {
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
    printf("%d",ptr->data);
}
void insertbegin()
{
    struct node *ptr=head,*last=NULL,*temp=NULL;
    temp=(struct node*)malloc(sizeof(struct node));
    int d;
    printf("\nEnter data");
    scanf("%d",&d);
    while(ptr->next!=head)
    {
        ptr=ptr->next;
    }
    last=ptr;
    temp->data=d;
    temp->next=last->next;
    last->next=temp;
    head=temp;
}
void insertend()
{
    struct node *ptr=NULL,*temp=NULL,*last=NULL;
    temp=(struct node*)malloc(sizeof(struct node));
    int d;
    printf("\nEnter data");
    scanf("%d",&d);
    temp->data=d;
    temp->next=head;
    ptr=head;
    while(ptr->next!=head)
    {
        ptr=ptr->next;
    }
    last=ptr;
    last->next=temp;
}
void deletebegin()
{
    struct node*temp,*ptr=NULL;
    temp=(struct node*)malloc(sizeof(struct node));
    temp=head;
    while(temp->next!=head)
    temp=temp->next;
    ptr=temp;
    temp=head;
    ptr->next=head->next;
    head=head->next;
    free(temp);
    
}
void deleteend()
{
    struct node *temp,*ptr=NULL,*last=NULL;
    if(head==NULL)
    printf("\nList is empty");
    else{
    temp=head;
    while(temp->next!=head)
    {
        last=temp;
        temp=temp->next;
    }
    last->next=temp->next;
    head=last->next;
    printf("\nDeletion at end node is %d",temp->data);
    free(temp);
    }
}
int main()
{
    int ch,d;
    while(ch)
    {
    printf("\n1)Creation 2)Traversal 3)Insertion 4)Deletion");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        creation();
        break;
        case 2:
        traversal();
        break;
        case 3:
        printf("\n1)Begin 2)End");
        scanf("%d",&d);
        if(d==1)
        insertbegin();
        else
        insertend();
        break;
        case 4:
        printf("\n1)Begin 2)End");
        scanf("%d",&d);
        if(d==1)
        deletebegin();
        else
        deleteend();
        break;
        default:
        printf("\nWrong choice");
        break;
    }
    }
}
