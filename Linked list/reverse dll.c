#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* prev;
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
        struct node*temp;
        if(n==-1)
            break;
        newnode->data=n;
        newnode->prev=NULL;
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
            ptr=head;
            head->prev=NULL;
        }
        else{
    
            ptr->next=newnode;
            newnode->prev=ptr;
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
    struct node* curr=head,*temp=NULL;
    while(curr!=NULL)
    {
        temp=curr->prev;
        curr->prev=curr->next;
        curr->next=temp;
        curr=curr->prev;
    }
    if(temp!=NULL)
    head=temp->prev;
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
