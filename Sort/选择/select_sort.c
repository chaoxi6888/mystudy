#include <stdio.h>
#include <stdlib.h>

void select_sort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        int t = arr[min];
        arr[min] = arr[i];
        arr[i] = t;
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
    select_sort(a, 8);
    show(a, 8);
    return 0;
}