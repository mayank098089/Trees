#include <stdio.h>
#include <stdlib.h>
typedef struct tree
{
    struct tree *left;
    int data;
    struct tree *right;
} tree;

tree *createNode(int d)
{
    tree *n = (tree *)malloc(sizeof(tree));
    (n)->left = (n)->right = NULL;
    n->data = d;
    return n;
}
void insert(tree **root, int data)
{
    if (*root == NULL)
    {
        *root = createNode(data);
    }
    if (data < (*root)->data)
    {
        insert(&((*root)->left), data);
    }
    if (data > (*root)->data)
    {
        insert(&((*root)->right), data);
    }
}

void preorder(tree *r)
{
    if(r==NULL)
    {
        return;
    }
    printf("%d ",r->data);
    preorder(r->left);
    preorder(r->right);
}
void postorder(tree *r)
{
    if(r==NULL)
    {
        return;
    }
    
    postorder(r->left);
    postorder(r->right);
    printf("%d ",r->data);
    
}

void inorder(tree *root)
{
    if (root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
    
}
int main()
{
    tree *root = NULL;
    insert(&root, 10);
    insert(&root, 5);
    insert(&root, 4);
    insert(&root, 6);
    insert(&root, 40);
    insert(&root, 50);
    insert(&root, 6000);
    insert(&root, 700);
     
    printf("Preorder Representation\n");
    preorder(root);
    printf("\nPostorder representation\n");
    postorder(root);
    printf("\nInorder representation\n");
    inorder(root);

    
}