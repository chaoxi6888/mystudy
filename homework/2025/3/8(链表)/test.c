#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 先定义结构体
typedef struct Contact
{
    /* data */
    char name[10];
    char tele[12];
} Contact;

typedef struct Node
{
    Contact data;      // 数据域
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

void add(Node *header, char *n, char *t)
{
    Node *node;
    Node *p = header;
    node = malloc(sizeof(Node));
    strncpy(node->data.name, n, 10);
    strncpy(node->data.tele, t, 11);
    while (p->next != NULL)
    {
        p = p->next;
    }
    node->next = NULL;
    p->next = node;
}

void show(Node *header)
{
    printf("链表:\n");
    printf("__________\n");
    Node *p;
    p = header->next; // 从第一个实际节点开始遍历
    while (p != NULL)
    {
        printf("%s\n", p->data.name);
        printf("%s\n", p->data.tele);
        p = p->next;
    }
    printf("__________\n");
}

void insert(Node *header, int index, char *n, char *t)
{
    if (index < 0 || index > len(header))
    {
        printf("index error!\n");
    }
    else if (index == len(header) - 1)
    {
        add(header, n, t);
    }
    else
    {
        Node *node = malloc(sizeof(Node));
        Node *p = header->next;
        strncpy(node->data.name, n, 10);
        strncpy(node->data.tele, t, 11);
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        node->next = p->next;
        p->next = node;
    }
}

void del(Node *header, int index)
{
    Node *p = header->next;
    Node *temp;
    for (int i = 0; i < index - 1; i++)
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

    add(header, "xiaomi", "13537544658");
    add(header, "xiaojiang", "17891010755");
    show(header);
    printf("长度为:%d\n\n", len(header));
    insert(header, 1, "haohao", "16789010566");
    show(header);
    printf("长度为:%d\n\n", len(header));
    del(header, 2);
    show(header);
    printf("长度为:%d\n\n", len(header));
    // 释放链表内存
    freeList(header);

    return 0;
}