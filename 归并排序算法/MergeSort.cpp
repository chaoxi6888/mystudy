#include <vector>
#include <iostream>
using namespace std;

const int kmod = 1000000007;

void merge(vector<int> &arr, vector<int> &tmp, int l, int mid, int r)
{
    int i = l, j = mid + 1, k = 0;

    while (i <= mid && j <= r)
    {
        if (arr[i] > arr[j])
        {
            tmp[k++] = arr[j++];
        }
        else
        {
            tmp[k++] = arr[i++];
        }
    }

    while (i <= mid)
    {
        tmp[k++] = arr[i++];
    }
    while (j <= r)
    {
        tmp[k++] = arr[j++];
    }

    for (k = 0, i = l; i <= r; ++i, ++k)
    {
        arr[i] = tmp[k];
    }
}

void mergesort(vector<int> &arr, vector<int> &tmp, int l, int r)
{
    if (l >= r)
    {
        return;
    }

    int mid = l + ((r - l) >> 1);
    mergesort(arr, tmp, l, mid);
    mergesort(arr, tmp, mid + 1, r);
    merge(arr, tmp, l, mid, r);
}

void MergeSort(vector<int> &data)
{
    int count = 0;
    vector<int> tmp(data.size());
    mergesort(data, tmp, 0, data.size() - 1);
}

int main()
{
    vector<int> a{6, 4, 5, 1, 3};
    printf("原来的序列为：");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    MergeSort(a);
    printf("排序后的序列：");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}