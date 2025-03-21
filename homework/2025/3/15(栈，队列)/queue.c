#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int *data;
    int MaxSize;
    int front, rear;
} Queue;

void init(Queue *q)
{
    q->MaxSize = 4;
    q->data = (int *)malloc(sizeof(int) * q->MaxSize);
    q->front = -1;
    q->rear = -1;
}

void grow(Queue *q)
{
    q->MaxSize *= 2;
    q->data = (int *)realloc(q->data, sizeof(int) * q->MaxSize);
}

void enqueue(Queue *q, int e)
{
    if (q->rear == -1)
    {
        q->front++;
    }
    if (q->rear == q->MaxSize - 1)
    {
        grow(q);
    }
    else
    {
        q->rear++;
        q->data[q->rear] = e;
    }
}

void dequeue(Queue *q)
{
    int e = q->data[q->front];
    if (q->front > q->rear)
    {
        printf("队列空\n");
    }
    else
    {
        printf("出队元素:%d\n", e);
        q->front++;
    }
}

void show(Queue *q)
{
    printf("队列:");
    int temp = q->front;
    while (temp <= q->rear)
    {
        printf("%d ", q->data[temp++]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    Queue *queue;
    queue = (Queue *)malloc(sizeof(Queue)); // 建列表
    init(queue);
    enqueue(queue, 2);
    enqueue(queue, 4);
    enqueue(queue, 6);
    show(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    show(queue);
    return 0;
}
