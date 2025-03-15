#include <stdlib.h>
#include <stdio.h>

// 定义结构体
typedef struct Node
{
    char data;          // 数据域
    struct Node *front; // 指向当前节点的前继元素
    struct Node *next;  // 指针域，指向当前节点的后继元素
} Node;

// 初始化双链表
void init(Node **header, Node **end)
{
    *header = (Node *)malloc(sizeof(Node));
    *end = (Node *)malloc(sizeof(Node));
    // 空表即初始化
    (*header)->next = *end;
    (*header)->front = *end;
    (*end)->next = *header;
    (*end)->front = *header;
}

// 计算链表长度
int len(Node *header, Node *end)
{
    Node *p = header->next;
    int len = 0;
    while (p != end)
    {
        len++;
        p = p->next;
    }
    return len;
}

// 添加节点到链表尾部
void add(Node *end, char c)
{
    Node *node;
    node = (Node *)malloc(sizeof(Node));
    node->data = c;
    end->front->next = node;
    node->front = end->front;
    node->next = end;
    end->front = node;
}

// 在指定位置插入节点
void insert(Node *header, int index, char c)
{
    Node *p = header->next;
    Node *node;
    node = (Node *)malloc(sizeof(Node));
    node->data = c;
    for (int i = 0; i < index; i++)
    {
        p = p->next;
    }
    p->front->next = node;
    node->front = p->front;
    node->next = p;
    p->front = node;
}

void del(Node *header, int index)
{
    Node *p = header->next;
    for (int i = 0; i < index; i++)
    {
        p = p->next;
    }
    p->front->next = p->next;
    p->next->front = p->front;
}

// 打印链表
void show(Node *header, Node *end)
{
    printf("双链表:");
    Node *p;
    p = header->next; // 从第一个实际节点开始遍历
    while (p != end)
    {
        printf("%c->", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    Node *header, *end;
    init(&header, &end); // 初始化链表
    add(end, 'A');       // 添加节点
    add(end, 'B');
    add(end, 'C');
    add(end, 'D');
    add(end, 'E');
    insert(header, 3, 'F'); // 在位置 3 插入节点 'F'
    del(header, 1);
    show(header, end); // 打印翻转前的链表
    printf("长度为:%d\n", len(header, end));
    return 0;
}