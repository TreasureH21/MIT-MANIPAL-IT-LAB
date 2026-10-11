#include <stdio.h>
#include <stdlib.h>

/* Structure of a binary tree node */
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

/* Create a new node */
struct Node* createNode(int data)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

/*------------------------------------------------
  i) Recursive function to create a binary tree

  Enter -1 if there is no node.
------------------------------------------------*/
struct Node* createTree()
{
    int data;
    struct Node *newNode;

    printf("Enter data (-1 for no node): ");
    scanf("%d", &data);

    if (data == -1)
        return NULL;

    newNode = createNode(data);

    printf("Enter left child of %d:\n", data);
    newNode->left = createTree();

    printf("Enter right child of %d:\n", data);
    newNode->right = createTree();

    return newNode;
}

/*------------------------------------------------
  ii) Recursive function to print nodes
      at a particular level
------------------------------------------------*/
void printLevel(struct Node *root, int level)
{
    if (root == NULL)
        return;

    if (level == 1)
    {
        printf("%d ", root->data);
    }
    else
    {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

/* Find height of tree */
int height(struct Node *root)
{
    int leftHeight, rightHeight;

    if (root == NULL)
        return 0;

    leftHeight = height(root->left);
    rightHeight = height(root->right);

    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

/*------------------------------------------------
  Print binary tree in Level Order
------------------------------------------------*/
void levelOrder(struct Node *root)
{
    int h, i;

    h = height(root);

    for (i = 1; i <= h; i++)
    {
        printLevel(root, i);
    }

    printf("\n");
}

/*------------------------------------------------
  Main function
------------------------------------------------*/
int main()
{
    struct Node *root;

    printf("Create Binary Tree\n");

    root = createTree();

    printf("\nBinary Tree in Level Order:\n");
    levelOrder(root);

    return 0;
}
