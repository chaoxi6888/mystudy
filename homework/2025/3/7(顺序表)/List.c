#include <stdio.h>
#include <stdlib.h>

typedef struct List // 定义线性表List可不写
{
    // 类型取决于存放的数据类型
    // 建议数组使用指针动态分配空间
    int *data;
    int size;     // 现在大小
    int capacity; // 容量（最大值）
} List;

// 声明相关操作,参数类型为指针
List *create(List *l)
{
    l = (List *)malloc(sizeof(List)); // 指针初始化，分配空间
    return l;
}

void init(List *l) // 初始化
{
    l->capacity = 4;
    l->size = 0;
    // 初始化，创建了一块连续的存储空间
    l->data = (int *)malloc(sizeof(int) * l->capacity);
}

void grow(List *l)
{
    l->capacity++;
    l->data = (int *)realloc(l->data, sizeof(int) * l->capacity);
    // printf("容量变大一位\n");
}

void add(List *l, int e) // 添加数
{
    // 是否越界
    if (l->size == l->capacity)
        grow(l);
    l->data[l->size] = e;
    l->size++;
}

void insert(List *l, int index, int e)
{
    // 是否越界
    if (l->size == l->capacity)
        grow(l);
    if (index <= l->size)
    {
        for (int i = l->size - 1; i >= index; i--)
        {
            l->data[i + 1] = l->data[i];
        }
        l->data[index] = e;
        l->size++;
    }
}

int del(List *l, int index)
{
    int val = l->data[index];
    // index是否越界
    if (index >= l->size)
    {
        printf("不存在第%d号索引位置元素\n", index);
    }
    else
    {
        for (int i = index; i < l->capacity - 1; i++)
        {
            l->data[i] = l->data[i + 1];
        }
        l->size--;
    }
    return val;
}

void find(List *l, int val)
{
    for (int i = 0; i < l->size; i++)
    {
        if (l->data[i] == val)
            printf("你要找的数在第几位(索引位置):%d\n", i);
        return;
    }
    printf("顺序表中不存在这个值\n");
}

void empty(List *l)
{
    l->size = 0; // 清空线性表，但不释放内存
    printf("线性表已清空\n");
}

void destroy(List *l)
{
    if (l->data)
    {
        free(l->data); // 释放数组内存
        l->data = NULL;
    }
    free(l); // 释放线性表结构体内存
    printf("线性表已销毁\n");
}

void show(List *l)
{
    printf("线性表:");
    for (int i = 0; i < l->size; i++)
    {
        printf("%d->", l->data[i]);
    }
    printf("\n大小:%d, 容量:%d\n", l->size, l->capacity);
}

int main()
{
    List *list;
    list = create(list);
    //   初始化线性表
    init(list);
    add(list, 100);
    add(list, 200);
    add(list, 300);
    add(list, 400);
    add(list, 500);
    insert(list, 3, 999);
    show(list);
    printf("删除的元素为%d\n", del(list, 3));
    show(list);
    find(list, 100);
    empty(list);
    show(list);
    destroy(list);
    return 0;
}