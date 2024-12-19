#include <vector>    // 引入vector容器库，用于动态数组操作
#include <iostream>  // 引入输入输出流库，用于标准输入输出操作
using namespace std; // 使用标准命名空间，避免std::前缀

// 合并函数，用于归并排序算法中合并两个已排序的子数组
void merge(vector<int> &arr, vector<int> &tmp, int l, int mid, int r)
{
    int i = l, j = mid + 1, k = 0; // 初始化左右子数组的起始索引和临时数组的索引

    // 合并两个子数组，直到一个子数组已经完全合并
    while (i <= mid && j <= r)
    {
        if (arr[i] > arr[j]) // 如果左子数组的元素大于右子数组的元素
        {
            tmp[k++] = arr[j++]; // 将右子数组的元素添加到临时数组，并移动索引
        }
        else
        {
            tmp[k++] = arr[i++]; // 将左子数组的元素添加到临时数组，并移动索引
        }
    }

    // 将剩余的左子数组元素复制到临时数组
    while (i <= mid)
    {
        tmp[k++] = arr[i++];
    }
    // 将剩余的右子数组元素复制到临时数组
    while (j <= r)
    {
        tmp[k++] = arr[j++];
    }

    // 将临时数组中的元素复制回原数组
    for (k = 0, i = l; i <= r; ++i, ++k)
    {
        arr[i] = tmp[k];
    }
}

// 归并排序函数，递归地将数组分成更小的部分进行排序
void mergesort(vector<int> &arr, vector<int> &tmp, int l, int r)
{
    if (l >= r) // 如果左边界大于或等于右边界，表示子数组只有一个元素，无需排序
    {
        return;
    }

    int mid = l + ((r - l) >> 1);    // 计算中间索引，防止溢出
    mergesort(arr, tmp, l, mid);     // 递归排序左子数组
    mergesort(arr, tmp, mid + 1, r); // 递归排序右子数组
    merge(arr, tmp, l, mid, r);      // 合并排序后的子数组
}

// 归并排序的封装函数，初始化临时数组并调用mergesort
void MergeSort(vector<int> &data)
{
    int count = 0;                            // 未使用变量
    vector<int> tmp(data.size());             // 创建一个与原数组大小相同的临时数组
    mergesort(data, tmp, 0, data.size() - 1); // 调用mergesort函数进行排序
}

int main() // 主函数，程序的入口点
{
    vector<int> a{6, 4, 5, 1, 3}; // 创建一个整数类型的动态数组并初始化
    printf("原来的序列为：");     // 输出原始序列前的提示信息
    for (int i = 0; i < 5; i++)   // 遍历数组并打印每个元素
    {
        printf("%d ", a[i]);
    }
    printf("\n");               // 输出换行符
    MergeSort(a);               // 调用归并排序函数对数组进行排序
    printf("排序后的序列：");   // 输出排序后序列前的提示信息
    for (int i = 0; i < 5; i++) // 再次遍历数组并打印排序后的每个元素
    {
        printf("%d ", a[i]);
    }
    return 0; // 程序正常结束
}
