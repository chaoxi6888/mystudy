#include <stdio.h>
#include <stdlib.h>

// 定义双链表节点结构
typedef struct Node
{
    int data;          // 数据域
    struct Node *prev; // 前驱指针
    struct Node *next; // 后继指针
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

// 在链表头部插入节点
void insertAtHead(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

// 在链表尾部插入节点
void insertAtTail(Node **head, int data)
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

// 删除链表中指定值的节点
void deleteNode(Node **head, int data)
{
    if (*head == NULL)
    {
        printf("链表为空，无法删除\n");
        return;
    }
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
void printList(Node *head)
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
    insertAtHead(&head, 10);
    insertAtHead(&head, 20);
    insertAtTail(&head, 30);
    insertAtTail(&head, 40);

    // 打印链表
    printf("双链表: ");
    printList(head);

    // 删除节点
    deleteNode(&head, 30);
    printf("删除节点后的链表: ");
    printList(head);

    // 释放链表内存
    freeList(head);

    return 0;
}