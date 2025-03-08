#include <stdio.h>
#include <stdlib.h>

// 先定义结构体
typedef struct Node
{
    int data;          // 数据域
    struct Node *next; // 指针域，指向当前节点的后继元素
} Node;

int len(Node *header)
{
    Node *p = header->next;
    int len = 0;
    while (p != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}

void add(Node *header, int e)
{
    Node *node;
    node = malloc(sizeof(Node));
    node->data = e;
    // 新节点指向头指针的next
    node->next = header->next;
    // 头指针的next指向node
    header->next = node;
}

void show(Node *header)
{
    printf("链表:");
    Node *p;
    p = header->next; // 从第一个实际节点开始遍历
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void insert(Node *header, int index, int e)
{
    Node *node = malloc(sizeof(Node));
    Node *p = header;
    int l = len(header);
    node->data = e;
    for (int i = 0; i < l - index; i++)
    {
        p = p->next;
    }
    node->next = p->next;
    p->next = node;
}

void del(Node *header, int index)
{
    Node *p = header;
    Node *temp;
    int l = len(header);
    for (int i = 0; i < l - index - 1; i++)
    {
        p = p->next;
    }
    temp = p->next;
    p->next = p->next->next;
    free(temp);
}

void freeList(Node *header)
{
    Node *p = header;
    Node *tmp;
    while (p != NULL)
    {
        tmp = p;
        p = p->next;
        free(tmp);
    }
}

int main()
{
    Node *header;
    header = malloc(sizeof(Node));
    // 空表即初始化
    header->next = NULL;

    add(header, 100);
    add(header, 200);
    add(header, 300);
    add(header, 400);
    show(header);
    printf("长度为:%d\n", len(header));
    insert(header, 2, 666);
    show(header);
    printf("长度为:%d\n", len(header));
    del(header, 2);
    show(header);
    printf("长度为:%d\n", len(header));

    // 释放链表内存
    freeList(header);

    return 0;
}