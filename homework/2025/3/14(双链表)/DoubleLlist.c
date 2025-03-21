#include <stdio.h>
#include <stdlib.h>

// 定义双链表节点结构
typedef struct Node
{
    int data;           // 数据域
    struct Node *prior; // 指向前一个节点的指针
    struct Node *next;  // 指向后一个节点的指针
} Node;

// 创建新节点
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("内存分配失败\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prior = NULL;
    newNode->next = NULL;
    return newNode;
}

// 初始化链表
void init(Node *head, Node **end)
{
    head->prior = NULL;
    head->next = NULL;
    head->data = -1;
    *end = head;
}

// 在链表末尾插入节点
void add(Node **end, int data)
{
    Node *node = createNode(data);
    (*end)->next = node;
    node->prior = *end;
    *end = node;
}

// 打印链表
void show(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 释放链表内存
void freeList(Node *head)
{
    Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    Node *head = (Node *)malloc(sizeof(Node));
    Node *end;
    init(head, &end); // 传递 end 的地址
    add(&end, 10);    // 传递 end 的地址
    show(head);
    freeList(head);
    return 0;
}