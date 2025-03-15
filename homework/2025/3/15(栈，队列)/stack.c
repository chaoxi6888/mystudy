#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int *data;    // 数据域
    int capacity; // 最大容量
    int top;      // 栈顶元素的索引
} Stack;

void init(Stack *stack)
{
    stack->capacity = 5;
    stack->data = (int *)malloc(sizeof(int) * stack->capacity);
    stack->top = -1;
}

void grow(Stack *stack)
{
    stack->capacity *= 2;
    stack->data = (int *)realloc(stack->data, sizeof(int) * stack->capacity);
}

void stackpush(Stack *stack, int e)
{
    if (stack->top >= stack->capacity - 1)
        grow(stack);
    stack->data[++stack->top] = e;
}

void stackpop(Stack *stack)
{
    int e;
    if (stack->top < 0)
        printf("栈空\n");
    else
    {
        e = stack->data[stack->top--];
        printf("出栈的元素为:%d\n", e);
    }
}

void show(Stack *stack)
{
    printf("栈(从左往右为从栈底开始):");
    for (int i = 0; i <= stack->top; i++)
    {
        printf("%d->", stack->data[i]);
    }
    printf("\n");
    printf("大小:%d,容量:%d\n", stack->top + 1, stack->capacity);
}

int main()
{
    Stack *stack;
    stack = (Stack *)malloc(sizeof(Stack));
    init(stack);
    stackpush(stack, 2);
    stackpush(stack, 4);
    stackpush(stack, 6);
    stackpush(stack, 8);
    stackpush(stack, 11);
    stackpush(stack, 15);
    show(stack);
    stackpop(stack);
    stackpop(stack);
    stackpop(stack);
    stackpop(stack);
    stackpop(stack);
    stackpop(stack);
    stackpop(stack);
    stackpop(stack);
    show(stack);
    return 0;
}
