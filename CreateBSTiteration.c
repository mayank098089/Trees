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
void insert(tree **root,int data)
{
    if (*root==NULL)
    {
        *root=createNode(data);
        return;
    }
    tree* l=*root;
    while (l)
    {
        if(data<l->data)
        {
           if (l->left==NULL)
           {
             l->left=createNode(data);
             break;
           }
           l=l->left;
           
        }
        else if (l->data<data)
        
        
        {
           if (l->right==NULL)
           {
              l->right=createNode(data);
             break;
           }
           l=l->right;
        }
        else
        {
            break;
        }
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
    insert(&root, 5);
    insert(&root, 30);
    insert(&root, -5000);
    insert(&root, 40);
    insert(&root,40 );
    insert(&root, -1000);
    insert(&root, 700);

  inorder(root);
}