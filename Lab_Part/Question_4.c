/*AUTHOR: MD. SAMI ALAM
ID: 222-16-656*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insertNode(struct Node **root, int value)
{
    if (*root == NULL)
    {
        *root = createNode(value);
    }
    else if (value < (*root)->data)
    {
        insertNode(&((*root)->left), value);
    }
    else if (value > (*root)->data)
    {
        insertNode(&((*root)->right), value);
    }
}

void printTree(struct Node *root, int space)
{
    if (root == NULL)
    {
        return;
    }

    space += 10;

    printTree(root->right, space);
    printf("\n");
    for (int i = 10; i < space; i++)
    {
        printf(" ");
    }
    printf("%d\n", root->data);
    printTree(root->left, space);
}

int main()
{
    struct Node *root = NULL;
    insertNode(&root, 25);
    insertNode(&root, 59);
    insertNode(&root, 19);
    insertNode(&root, 34);
    insertNode(&root, 44);
    insertNode(&root, 29);
    insertNode(&root, 38);
    insertNode(&root, 46);
    insertNode(&root, 18);
    insertNode(&root, 17);
    insertNode(&root, 22);

    printTree(root, 0);

    return 0;
}
