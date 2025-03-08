#include <stdio.h>
#include <stdlib.h>

typedef struct // 定义线性表List可不写
{
    // 类型取决于存放的数据类型
    // 建议数组使用指针动态分配空间
    int *data;
    int size;     // 现在大小
    int capacity; // 容量（最大值）
} List;

void grow(List *l)
{
        int *newdata;
        l->capacity++;
        newdata = realloc(l->data, sizeof(int) * l->capacity);
        l->data = newdata;
        // printf("容量变大一位\n");
}

// 声明相关操作,参数类型为指针
void init(List *l) // 初始化
{
    l->capacity = 4;
    l->size = 0;
    // 初始化，创建了一块连续的存储空间
    l->data = malloc(sizeof(int) * l->capacity);
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

int get(List *l, int index) {}

int find(List *l, int val) {}

int size(List *l)
{
    printf("现在表的长度为:%d\n", l->size);
}

void empty(List *l) {}

void show(List *l)
{
    printf("线性表:");
    for (int i = 0; i < l->size; i++)
    {
        printf("%d ", l->data[i]);
    }
    printf("\n大小:%d, 容量:%d\n", l->size, l->capacity);
}

int main()
{
    List *list;
    list = malloc(sizeof(List)); // 指针初始化，分配空间
    //   初始化线性表
    init(list);
    add(list, 100);
    add(list, 200);
    add(list, 300);
    add(list, 400);
    add(list, 500);
    insert(list, 5, 999);
    printf("删除的元素为%d\n", del(list, 3));
    show(list);
    size(list);
    return 0;
}