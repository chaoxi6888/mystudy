#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j + 1 < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}

void show(int *arr, int l)
{
    for (int i = 0; i < l; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int a[] = {1, 6, 2, 55, 3, 8, 4, 12};
    bubble_sort(a, 8);
    show(a, 8);
    return 0;
}