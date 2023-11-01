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
    insert(&root, 20);
    insert(&root, 30);
    insert(&root, 5000);
    insert(&root, 40);
    insert(&root, 50);
    insert(&root, 6000);
    insert(&root, 700);

  inorder(root);
}