#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 二叉搜索树的实现
typedef struct Student
{
    int id;
    char name[20];
    float score;
} Student;

typedef struct Node
{
    int key;
    Student student;
    struct Node *left;
    struct Node *right;
} Node;

Node *insert(Node *root, int val, Student student); // 插入节点
Node *deleteNode(Node *root, int val);              // 删除节点
Node *findMin(Node *root);                          // 查找最小值节点
void preorder(Node *root);                          // 前序遍历
void inorder(Node *root);                           // 中序遍历
void postorder(Node *root);                         // 后序遍历
void freeTree(Node *root);                          // 释放树的内存

Node *insert(Node *root, int val, Student student)
{
    if (root == NULL)
    {
        root = (Node *)malloc(sizeof(Node));
        root->key = val;
        root->student = student;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    if (val < root->key)
    {
        root->left = insert(root->left, val, student);
    }
    else if (val > root->key)
    {
        root->right = insert(root->right, val, student);
    }
    return root;
}

Node *deleteNode(Node *root, int val) // 删除符合指定索引值的节点
{
    if (root == NULL)
        return root;

    if (val < root->key)
    {
        root->left = deleteNode(root->left, val);
    }
    else if (val > root->key)
    {
        root->right = deleteNode(root->right, val);
    }
    else
    {
        // 找到要删除的节点
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        // 有两个子节点，找到右子树的最小值替代
        Node *temp = findMin(root->right);
        root->key = temp->key;
        root->student = temp->student;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

Node *findMin(Node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("Key: %d, Student ID: %d, Name: %s, Score: %.2f\n",
               root->key, root->student.id, root->student.name, root->student.score);
        inorder(root->right);
    }
}

void preorder(Node *root)
{
    if (root != NULL)
    {
        printf("Key: %d, Student ID: %d, Name: %s, Score: %.2f\n",
               root->key, root->student.id, root->student.name, root->student.score);
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
        printf("Key: %d, Student ID: %d, Name: %s, Score: %.2f\n",
               root->key, root->student.id, root->student.name, root->student.score);
    }
}

void freeTree(Node *root)
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main()
{
    Node *root = NULL;

    // 插入一些学生数据
    Student s1 = {1, "Alice", 85.5};
    Student s2 = {2, "Bob", 90.0};
    Student s3 = {3, "Charlie", 78.0};
    Student s4 = {4, "David", 92.5};
    Student s5 = {5, "Eve", 88.0};

    root = insert(root, 5, s1);
    root = insert(root, 3, s2);
    root = insert(root, 1, s3);
    root = insert(root, 2, s4);
    root = insert(root, 4, s5);

    printf("Inorder Traversal:\n");
    inorder(root);
    printf("\n");

    printf("Preorder Traversal:\n");
    preorder(root);
    printf("\n");

    printf("Postorder Traversal:\n");
    postorder(root);
    printf("\n");

    // 删除一个节点
    printf("Deleting node with key 3...\n");
    root = deleteNode(root, 3);

    printf("Inorder Traversal after deletion:\n");
    inorder(root);
    printf("\n");

    // 释放内存
    freeTree(root);

    return 0;
}