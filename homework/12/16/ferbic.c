#include <stdio.h>
#define N 100

int time = 0;

int ferbic(int n) // 递归实现
{
    time++;
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }
    return (ferbic(n - 1) + ferbic(n - 2));
}

int ferbic_for(int n) // 循环实现
{
    int arr[N];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i < n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n - 1];
}

int main()
{
    int n;
    printf("请输入n(n<=100):");
    scanf("%d", &n);
    int result = ferbic(n);
    printf("斐波那契数列的第%d个数为:%d,递归的次数:%d\n", n, result, time);
    printf("斐波那契数列的第%d个数为:%d", n, ferbic_for(n));
    return 0;
}
