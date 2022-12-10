#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* next;
};

struct node* creation(struct node* head)
{
    int n=0;
    struct node* ptr;
    printf("\nEnter elements:\n");
    while(1)
    {
        scanf("%d",&n);
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        if(n==-1)
            break;
        newnode->data=n;
        if(head==NULL)
        {
            head=newnode;
            ptr=head;
        }
        else{
            ptr->next=newnode;
            ptr=ptr->next;
        }
    }
    ptr->next=NULL;
    return head;
}
void traversal(struct node* head)
{
    printf("\nLINKED LIST:\n");
    struct node* ptr=head;
    if(head==NULL)
        printf("\nEmpty\n");
    while(ptr!=NULL)
    {
        printf("%d -> ",ptr->data);
        ptr=ptr->next;
    }
}
struct node* oddeven(struct node* head)
{
    struct node* ptr=head,*evenstart=NULL,*evenend=NULL,*oddstart=NULL,*oddend=NULL;
    int i=1;
    if(head==NULL||head->next==NULL)
        return head;
    while(ptr!=NULL)
    {
        if(i%2==0)
        {
            if(evenstart==NULL)
                evenstart=ptr;
            else
                evenend->next=ptr;
            evenend=ptr;
        }
        else{
            if(oddstart==NULL)
                oddstart=ptr;
            else
                oddend->next=ptr;
            oddend=ptr;
        }
        ptr=ptr->next;
        i++;
    }
    evenend->next=NULL;
    oddend->next=evenstart;
    head=oddstart;
    return head;
}
int main()
{
    struct node *head=NULL;
    head=creation(head);
    traversal(head);
    head=oddeven(head);
    traversal(head);
}
