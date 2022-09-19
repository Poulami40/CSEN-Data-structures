/*Stack implementation using linked list*/

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node *top=NULL;
int isempty()
{
    if (top==NULL)
    return 0;
    else
    return -1;
}
void peek()
{
    if(top==NULL)
        printf("\nEmpty");
    else
        printf("%d",top->data);
}
void push()
{
    int d;
    struct node* temp=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter data");
        scanf("%d",&d);
        temp->data=d;
        temp->next=top;
        top=temp;
}
void pop()
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp=top;
    top=top->next;
    free(temp);
}

int main()
{
    int ch,d;
    while(ch)
    {
    printf("\n1)Push 2)Pop 3)peek 4)isempty");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        push();
        break;
        case 2:
        pop();
        break;
        case 3:
        peek();
        break;
        case 4:
        if(isempty())
        printf("\nNot empty");
        else
        printf("\nEmpty");
        break;
        default:
        printf("\nINvalid");
        break;
    }
    }
}
