#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left,*right;
};
int i=0;
struct node *create()
{
    int x;
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter %d data\n",i+1);i++;
    scanf("%d",&x);
    if( x == -1)
        {
            return NULL;
        }
    newnode->data=x;
    printf("\nenter data of left child\n");
    newnode->left=create();
    printf("\nenter data of right child\n");
    newnode->right=create();
    return newnode;
}
void preorder(struct node *root)
{
    if(root==0){return;}
    printf("%d\t",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node *root)
{
    if(root==0){return;}
    postorder(root->left);
    postorder(root->right);
    printf("%d\t",root->data);
}
void inorder(struct node *root)
{
    if(root==0){return;}
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
}
int main()
{
    struct node *root;
    root=create();
    printf("preorder\n");
    preorder(root);
    printf("\npostorder\n");
    postorder(root);
    printf("\ninorder\n");
    inorder(root);
    return 0;
}
