#include <stdio.h>
#include <stdlib.h>

/* Structure of a binary tree node */
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

/* Stack structure */
struct Stack
{
    struct Node *node;
    struct Stack *next;
};

/*------------------------------------------------
  Create a new node
------------------------------------------------*/
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
  Create binary tree recursively
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
  i) Iterative Inorder Traversal
  Left -> Root -> Right
------------------------------------------------*/
void inorder(struct Node *root)
{
    struct Stack *stack = NULL;
    struct Node *current = root;

    while (current != NULL || stack != NULL)
    {
        /* Push all left nodes */
        while (current != NULL)
        {
            struct Stack *temp =
                (struct Stack*)malloc(sizeof(struct Stack));

            temp->node = current;
            temp->next = stack;
            stack = temp;

            current = current->left;
        }

        /* Pop node */
        {
            struct Stack *temp = stack;

            current = temp->node;
            stack = stack->next;

            free(temp);
        }

        printf("%d ", current->data);

        /* Move to right subtree */
        current = current->right;
    }

    printf("\n");
}

/*------------------------------------------------
  ii) Iterative Postorder Traversal
  Left -> Right -> Root
------------------------------------------------*/
void postorder(struct Node *root)
{
    struct Stack *stack1 = NULL;
    struct Stack *stack2 = NULL;

    if (root == NULL)
        return;

    /* Push root into stack1 */
    {
        struct Stack *temp =
            (struct Stack*)malloc(sizeof(struct Stack));

        temp->node = root;
        temp->next = stack1;
        stack1 = temp;
    }

    while (stack1 != NULL)
    {
        struct Node *current;

        /* Pop from stack1 */
        {
            struct Stack *temp = stack1;

            current = temp->node;
            stack1 = stack1->next;

            free(temp);
        }

        /* Push into stack2 */
        {
            struct Stack *temp =
                (struct Stack*)malloc(sizeof(struct Stack));

            temp->node = current;
            temp->next = stack2;
            stack2 = temp;
        }

        /* Push left child */
        if (current->left != NULL)
        {
            struct Stack *temp =
                (struct Stack*)malloc(sizeof(struct Stack));

            temp->node = current->left;
            temp->next = stack1;
            stack1 = temp;
        }

        /* Push right child */
        if (current->right != NULL)
        {
            struct Stack *temp =
                (struct Stack*)malloc(sizeof(struct Stack));

            temp->node = current->right;
            temp->next = stack1;
            stack1 = temp;
        }
    }

    /* Print stack2 */
    while (stack2 != NULL)
    {
        struct Stack *temp = stack2;

        printf("%d ", temp->node->data);

        stack2 = stack2->next;

        free(temp);
    }

    printf("\n");
}

/*------------------------------------------------
  iii) Iterative Preorder Traversal
  Root -> Left -> Right
------------------------------------------------*/
void preorder(struct Node *root)
{
    struct Stack *stack = NULL;

    if (root == NULL)
        return;

    /* Push root */
    {
        struct Stack *temp =
            (struct Stack*)malloc(sizeof(struct Stack));

        temp->node = root;
        temp->next = stack;
        stack = temp;
    }

    while (stack != NULL)
    {
        struct Node *current;

        /* Pop node */
        {
            struct Stack *temp = stack;

            current = temp->node;
            stack = stack->next;

            free(temp);
        }

        printf("%d ", current->data);

        /*
          Push right first so that
          left is processed first.
        */
        if (current->right != NULL)
        {
            struct Stack *temp =
                (struct Stack*)malloc(sizeof(struct Stack));

            temp->node = current->right;
            temp->next = stack;
            stack = temp;
        }

        /* Push left */
        if (current->left != NULL)
        {
            struct Stack *temp =
                (struct Stack*)malloc(sizeof(struct Stack));

            temp->node = current->left;
            temp->next = stack;
            stack = temp;
        }
    }

    printf("\n");
}

/*------------------------------------------------
  iv) Print parent of a given element
------------------------------------------------*/
int findParent(struct Node *root, int key)
{
    if (root == NULL)
        return 0;

    if ((root->left != NULL && root->left->data == key) ||
        (root->right != NULL && root->right->data == key))
    {
        printf("Parent of %d = %d\n", key, root->data);
        return 1;
    }

    if (findParent(root->left, key))
        return 1;

    if (findParent(root->right, key))
        return 1;

    return 0;
}

/*------------------------------------------------
  v) Find depth / height of tree
------------------------------------------------*/
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
  vi) Print ancestors of a given element
------------------------------------------------*/
int printAncestors(struct Node *root, int key)
{
    if (root == NULL)
        return 0;

    if (root->data == key)
        return 1;

    if (printAncestors(root->left, key) ||
        printAncestors(root->right, key))
    {
        printf("%d ", root->data);
        return 1;
    }

    return 0;
}

/*------------------------------------------------
  vii) Count number of leaf nodes
------------------------------------------------*/
int countLeaves(struct Node *root)
{
    if (root == NULL)
        return 0;

    /* A leaf has no left and right child */
    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeaves(root->left) +
           countLeaves(root->right);
}

/*------------------------------------------------
  Main function
------------------------------------------------*/
int main()
{
    struct Node *root;
    int key;

    printf("Create Binary Tree\n");
    root = createTree();

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("Preorder Traversal: ");
    preorder(root);

    printf("Postorder Traversal: ");
    postorder(root);

    printf("\nEnter element to find parent: ");
    scanf("%d", &key);

    if (!findParent(root, key))
        printf("Parent not found.\n");

    printf("\nHeight of tree: %d\n", height(root));

    printf("\nEnter element to find ancestors: ");
    scanf("%d", &key);

    printf("Ancestors of %d: ", key);

    if (!printAncestors(root, key))
        printf("Element not found.\n");
    else
        printf("\n");

    printf("\nNumber of leaf nodes: %d\n",
           countLeaves(root));

    return 0;
}1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1
