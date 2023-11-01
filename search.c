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
int isBSt(tree *root)
{  static tree *prev = NULL;
   if(root!=NULL)
   {
     if(!isBSt(root->left)) return 0;
     if(prev!=NULL&& root->data<=prev->data)return 0;
     prev=root;
     return isBSt(root->right);
   }
   else
   {
    
     return 1;
   }
}
tree *search(tree *root,int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==key)
    {
        return root;
    }
    if(key<root->data)
    {
        return search(root->left,key);
    }
    else
    {
        return search(root->right,key);
    }
}

tree *iterative_search(tree *root,int key)
{
    if (root==NULL)return NULL;
    tree *t=root;
    while(t!=NULL)
    {
        if (t->data==key)
        {
            return t;
        }
        else if(t->data>key)
        {
            t=t->left;
        }
        else
        {
            t=t->right;
        }
        
    } 
    return NULL;  
    
}
int main()
{
    tree *root = NULL;
    insert(&root, 10);
    insert(&root, 45);
    insert(&root, 20);
    insert(&root, 500);
    insert(&root, 40);
    insert(&root, 50);
    insert(&root, 6000);
    insert(&root, 700);

  inorder(root);
  printf("%d\n", isBSt(root));
  tree *temp=search(root,50);
  if(temp!=NULL)
  {
   printf("%d\n",temp->data);
  }
  else
  {
    printf("not found\n");
  }

  temp=iterative_search(root,6000);
  if(temp!=NULL)
  {
   printf("%d\n",temp->data);
  }
  else
  {
    printf("not found\n");
  }
  return 0;
}