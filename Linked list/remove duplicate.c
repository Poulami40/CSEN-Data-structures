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
struct node* duplicate(struct node* head)
{
    struct node* prev=head,*curr=head->next;
    if(head==NULL||head->next==NULL)
        return head;
    while(curr!=NULL)
    {
        if(prev->data==curr->data)
        {
            prev->next=curr->next;
            curr=curr->next;
        }
        else{
            prev=curr;
            if(curr->next!=NULL)
            curr=curr->next;
        }
    }
    
    return head;
}
int main()
{
    struct node *head=NULL;
    head=creation(head);
    traversal(head);
    struct node *newh=duplicate(head);
    printf("\nAFTER REMOVING DUPLICATES:\n");
    traversal(newh);
}
