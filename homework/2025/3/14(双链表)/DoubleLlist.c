#include <stdlib.h>
#include <stdio.h>

// 先定义结构体
typedef struct Node
{
    int data;           // 数据域
    struct Node *front; // 指向当前节点的前继元素
    struct Node *next;  // 指针域，指向当前节点的后继元素
} Node;

void init(Node **header, Node **end)
{
    *header = (Node *)malloc(sizeof(Node));
    *end = (Node *)malloc(sizeof(Node));
    // 空表即初始化
    (*end)->data = -1;
    (*header)->next = *end;
    (*header)->front = *end;
    (*end)->next = *header;
    (*end)->front = *header;
}

int len(Node *header)
{
    Node *p = header->next;
    int len = 0;
    while (p != header)
    {
        len++;
        p = p->next;
    }
    return len;
}

void add(Node *end, int e)
{
    Node *node;
    node = (Node *)malloc(sizeof(Node));
    node->data = e;
    end->front->next = node;
    node->front = end->front;
    node->next = end;
    end->front = node;
}

void show(Node *header, Node *end)
{
    printf("双链表:");
    Node *p;
    p = header->next; // 从第一个实际节点开始遍历
    while (p != end)
    {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    Node *header, *end;
    init(&header, &end); // 传递指针的地址
    add(end, 100);
    add(end, 200);
    add(end, 300);
    add(end, 400);
    show(header, end);
    return 0;
}