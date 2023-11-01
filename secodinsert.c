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
    tree *prev = NULL;
    tree *current = *root;

    while (current != NULL)
    {
        prev = current;
        if (current->data == data)
        {
            printf("The %d data is already present in the tree\n", data);
            return;
        }
        if (current->data > data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    tree *n = createNode(data);

    if (prev == NULL)
    {
        *root = n;  // Update the root pointer when the tree is empty
    }
    else if (prev->data > data)
    {
        prev->left = n;
    }
    else
    {
        prev->right = n;
    }
}

void inorder(tree *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
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
    insert(&root, 40);
    insert(&root, -1000);
    insert(&root, 700);

    inorder(root);

    return 0;
}
