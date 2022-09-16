/*1)Creation
2)Traversal
3)Search
4)Nodes
5)Inserion:i)beginning ii)end iii)position iv)before node v)after node
6)Deletion:i)beginning ii)end iii)position iv)before node v)after node*/

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
            ptr->next=NULL;
        }
    }
}
void traversal()
{
    struct node*ptr;
    printf("\nLinked list:\n");
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
}
void count()
{
    struct node*temp=head;
    int c=0;
    while(temp!=NULL)
    {
        c++;
        temp=temp->next;
    }
    printf("\nNo of nodes=%d",c);
}
void search()
{
    struct node* temp=head;
    int d,c=0;
    printf("\nEnter element to search");
    scanf("%d",&d);
    while(temp!=NULL)
    {
        if(temp->data==d)
        c++;
        temp=temp->next;
    }
    if(c!=0)
    printf("\nElement there");
    else
    printf("\nElement not there");
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
}
void insertpos()
{
    struct node *ptr=NULL,*temp=NULL;
    temp=(struct node*)malloc(sizeof(struct node));
    int d,pos,c=1,f=0;
    printf("\nEnter data and position");
    scanf("%d %d",&d,&pos);
    ptr=head;
    while(c<pos-1)
    {
        ptr=ptr->next;
       c++;
    }
    temp->data=d;
    temp->next=ptr->next;
    ptr->next=temp;

}
void insertbnode()
{
    struct node *ptr=NULL,*temp=NULL;
    temp=(struct node*)malloc(sizeof(struct node));
    int d,n;
    printf("\nEnter node and data");
    scanf("%d %d",&n,&d);
    ptr=head;
    while((ptr->next)->data!=n)
    {
        ptr=ptr->next;
    }
            temp->data=d;
            temp->next=ptr->next;
            ptr->next=temp;
}
void insertanode()
{
    struct node *ptr=NULL,*temp=NULL;
    temp=(struct node*)malloc(sizeof(struct node));
    int d,n;
    printf("\nEnter node and data");
    scanf("%d %d",&n,&d);
    ptr=head;
    while((ptr->data)!=n)
    {
        ptr=ptr->next;
    }
            temp->data=d;
            temp->next=ptr->next;
            ptr->next=temp;
}
void deletebegin()
{
    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp=head;
    head=head->next;
    free(temp);
}
void deletend()
{
    struct node *temp,*ptr;
    if(head==NULL)
    printf("\nList is empty");
    else{
    temp=head;
    while(temp->next!=NULL)
    {
        ptr=temp;
        temp=temp->next;
    }
    
    free(temp);
    ptr->next=NULL;
    }
}
void deletepos()
{
    int pos,c=1;
    struct node *temp=NULL,*ptr=NULL;
    printf("Enter position");
    scanf("%d",&pos);
    temp=head;
    while(c<=pos-2)
    {
        temp=temp->next;
        c++;
    }
    ptr=temp->next;
    temp->next=ptr->next;
    free(ptr);
}
void deletebnode()
{
    struct node *temp=NULL,*ptr=NULL;
    temp=head;
    int n,c=0;
    printf("\nEnter node");
    scanf("%d",&n);
    while(temp->next!=NULL)
    {
        if(temp->next->next->data==n){
        c++;
        break;}
        temp=temp->next;
    }
    if(c==0)
    printf("\nNode not found");
    else{
        ptr=temp->next;
        temp->next=ptr->next;
        free(ptr);
    }
}
void deleteanode()
{
    struct node *temp=NULL,*ptr=NULL;
    temp=head;
    int n,c=0;
    printf("\nEnter node");
    scanf("%d",&n);
    while(temp->next!=NULL)
    {
        if(temp->data==n){
        c++;
        break;}
        temp=temp->next;
    }
    if(c==0)
    printf("\nNode not found");
    else{
        ptr=temp->next;
        temp->next=ptr->next;
        free(ptr);
    }
}
int main()
{
    int ch,po;
    while(ch){
    printf("\n1)Creation 2)Traversal 3)Insertion 4)Deletion 5)Search 6)Count");
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
        printf("\n1)Beginning 2)End 3)position 4)before node 5)after node");
        scanf("%d",&po);
        switch(po)
        {
            case 1:
            insertbegin();
            break;
            case 2:
            insertend();
            break;
            case 3:
            insertpos();
            break;
            case 4:
            insertbnode();
            break;
            case 5:
            insertanode();
            break;
        }
        break;
         case 4:
        printf("\n1)Beginning 2)End 3)position 4)before node 5)after node");
        scanf("%d",&po);
        switch(po)
        {
            case 1:
            deletebegin();
            break;
            case 2:
            deletend();
            break;
            case 3:
            deletepos();
            break;
            case 4:
            deletebnode();
            break;
            case 5:
            deleteanode();
            break;
        }
        break;
        case 5:
        search();
        break;
        case 6:
        count();
        break;
        default:
        printf("\nInvalid choice");
        break;
    }
    }
}
