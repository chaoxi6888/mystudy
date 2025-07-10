#include <stdio.h>

void swap(int *l, int *r)
{
    int t = *l;
    *l = *r;
    *r = t;
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[high]; // 使用最后一个做基准
    int l = low;
    int r = high;
    while (l < r)
    {
        while (l < r && arr[l] <= pivot)
            l++;
        if (l < r)
            arr[r--] = arr[l];
        while (l < r && arr[r] >= pivot)
            r--;
        if (l < r)
            arr[l++] = arr[r];
    }
    arr[l] = pivot;
    return l;
}

void quick(int *arr, int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quick(arr, low, p - 1);
        quick(arr, p + 1, high);
    }
}

void qsort(int *arr, int n)
{
    quick(arr, 0, n - 1);
}

int main()
{
    int arr[] = {5, 2, 9, 1, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    qsort(arr, n);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}