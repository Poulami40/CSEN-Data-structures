/*Postfix operator*/

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node *top=NULL;
void push(int d)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
        temp->data=d;
        temp->next=top;
        top=temp;
}
int pop()
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp=top;
    top=top->next;
    int d=temp->data;
    free(temp);
    return d;
}
int eval(char c,int a,int b)
{
    switch(c)
    {
    case '+':
        return (a+b);
        break;
    case '-':
        return (a-b);
        break;
    case '*':
        return (a*b);
        break;
    case '/':
        return (a/b);
        break;
    }
}
int main()
{
    char d[50],ch;
    int op1,op2,val,x;
    printf("\nEnter expression");
    gets(d);
    for(int i=0;d[i]!=0;i++)
    {
        ch=d[i];
        if(ch>='0'&&ch<='9')
            push(ch-'0');
        else{
            op2=pop();
            op1=pop();
            push(eval(ch,op1,op2));
        }
    }
    printf("\nEvaluated value=%d",pop());
}
