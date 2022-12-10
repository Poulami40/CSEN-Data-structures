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
struct node* reverse(struct node* head)
{
    struct node* curr=head,*prev=NULL,*ptr=NULL;
    while(curr!=NULL)
    {
        ptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=ptr;
    }
    head=prev;
    return head;
}
int main()
{
    struct node *head=NULL;
    head=creation(head);
    traversal(head);
    head=reverse(head);
    traversal(head);
}
