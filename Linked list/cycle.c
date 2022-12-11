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
int cycle(struct node* head)
{
    struct node* fast=head,*slow=head;
    while(fast&&fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            return 1;
    }
    return 0;
}
int main()
{
    struct node *head=NULL;
    head=creation(head);
    head->next->next->next->next=head;
    int j=cycle(head);
    if(j)
        printf("\nCycle\n");
    else    
        printf("\nNo cycle\n");
}
