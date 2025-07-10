#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

void heapify(int *arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void build_max_heap(int *arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

int main()
{
    int arr[] = {42, 7, 31, 64, 19, 23, 1, 29};
    int n = sizeof(arr) / sizeof(arr[0]);

    build_max_heap(arr, n);

    printf("初始序列为: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}