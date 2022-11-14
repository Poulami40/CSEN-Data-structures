//Create bst and implement inorder,preorder,postorder traversal

#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* left;
    struct node *right;
};

struct node* createnode(int d)
{
    struct node* n=(struct node*)malloc(sizeof(struct node));
    n->data=d;
    n->left=n->right=NULL;
    return n;
}
struct node* creation(struct node* n,int d)
{
    struct node* newnode=createnode(d);
    if(n==NULL)
    {
        
        return createnode(d);
        
        // root->left=NULL;
        // root->right=NULL;
    }
    else if(d<n->data)
    {
        n->left=creation(n->left,d);
    }
    else{
        n->right=creation(n->right,d);
    }
   return n;
}
void inorder(struct node* n)
{
    if(n==NULL){
    return;
    }
    inorder(n->left);
    printf("%d ",n->data);
    inorder(n->right);
}
void preorder(struct node* n)
{
    if(n==NULL){
    return;
    }
    printf("%d ",n->data);
    preorder(n->left);
    
    preorder(n->right);
}
void postorder(struct node* n)
{
    if(n==NULL){
    return;
    }
    
    postorder(n->left);
    
    postorder(n->right);
    printf("%d ",n->data);
}
int main()
{
    int n;
    printf("\nEnter nos\n");
    struct node* root=NULL;
    scanf("%d",&n);
    if(n!=-1)
    root=creation(root,n);
    while(1)
    {
        
    scanf("%d",&n);
    if(n==-1)
        break;
    creation(root,n);
    
    }
    printf("\nInorder:\n");
    inorder(root);
    printf("\nPreorder:\n");
    preorder(root);
    printf("\nPostorder:\n");
    postorder(root);
}
