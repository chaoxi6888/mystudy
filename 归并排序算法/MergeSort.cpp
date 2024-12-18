#include <vector>
#include <iostream>
using namespace std;

const int kmod = 1000000007;

void merge__(vector<int> &arr, vector<int> &tmp, int l, int mid, int r, int &ret)
{
    int i = l, j = mid + 1, k = 0;

    while (i <= mid && j <= r)
    {
        if (arr[i] > arr[j])
        {
            tmp[k++] = arr[j++];
            ret += (mid - i + 1);
            ret %= kmod;
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

void merge_sort__(vector<int> &arr, vector<int> &tmp, int l, int r, int &ret)
{
    if (l >= r)
    {
        return;
    }

    int mid = l + ((r - l) >> 1);
    merge_sort__(arr, tmp, l, mid, ret);
    merge_sort__(arr, tmp, mid + 1, r, ret);
    merge__(arr, tmp, l, mid, r, ret);
}

int InversePairs(vector<int> &data)
{
    int ret = 0;
    // 在最外层开辟数组
    vector<int> tmp(data.size());
    merge_sort__(data, tmp, 0, data.size() - 1, ret);
    return ret;
}

int main()
{
    vector<int> a{6, 4, 5, 1, 3};
    cout << InversePairs(a);
    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}