#include <stdio.h>
#include <stdlib.h>

// 定义双链表节点结构
typedef struct Node
{
    int data;          // 数据域
    struct Node *prev; // 指向前一个节点的指针
    struct Node *next; // 指向后一个节点的指针
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
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// 在链表末尾插入节点
void add(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// 在链表开头插入节点
void addbegin(Node **head, int data)
{
    Node *newNode = createNode(data);
    newNode->next = *head;
    if (*head != NULL)
    {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void insert() {}

// 删除链表中的节点
void deleteNode(Node **head, int data)
{
    Node *temp = *head;
    while (temp != NULL && temp->data != data)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("未找到要删除的节点\n");
        return;
    }
    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    else
    {
        *head = temp->next;
    }
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    free(temp);
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
    Node *head = NULL;

    // 插入节点
    add(&head, 10);
    add(&head, 20);
    add(&head, 30);
    addbegin(&head, 5);

    // 打印链表
    printf("双链表: ");
    show(head);

    // 删除节点
    deleteNode(&head, 10);
    printf("删除节点后的链表: ");
    show(head);

    // 释放链表内存
    freeList(head);

    return 0;
}