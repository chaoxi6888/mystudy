#include <stdio.h>
#define N 32

// void swap(int *a, int *b) // 交换函数
// {
//     int t = *a;
//     *a = *b;
//     *b = t;
// }

int main()
{
    int n; // 要转换的数
    int a[N];
    int i = 0;
    printf("请输入要转换的整数：");
    scanf("%d", &n);
    // 转换过程
    while (n != 0)
    {
        a[i++] = n % 2;
        n /= 2;
    }
    // 翻转数组
    for (int j = 0; j != i - 1 - j; j++)
    {
        int t = a[j];
        a[j] = a[i - 1 - j];
        a[i - 1 - j] = t;
        // swap(&a[j], &a[i - 1 - j]);
    }
    printf("转成二进制数为：\n");
    // 输出翻转的数组
    for (int j = 0; j < i; j++)
    {
        printf("%d", a[j]);
    }
    return 0;
}