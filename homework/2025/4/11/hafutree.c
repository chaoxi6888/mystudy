#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *insert(Node *root, int val);
void preorder(Node *root);
void inorder(Node *root);
void postorder(Node *root);

Node *insert(Node *root, int val)
{
    if (root == NULL)
    {
        root = (Node *)malloc(sizeof(Node));
        root->data = val;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    if (val < root->data)
    {
        // 小于当前节点值，插入到左子树
        root->left = insert(root->left, val);
    }
    else if (val > root->data)
    {
        // 大于当前节点值，插入到右子树
        root->right = insert(root->right, val);
    }
    return root;
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    Node *root = NULL; // 使用根节点来表示空树
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    inorder(root);
    printf("\n");
    return 0;
}