#include <stdio.h>

int jiecheng(int n)
{
    if (n == 1 || n == 0)
        return 1;
    else
        return n * jiecheng(n - 1);
}

int main()
{
    // 循环
    int i, n, product = 1;
    printf("请输入n的值:");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        product *= i;
    }
    printf("n的阶乘为:%d\n", product);
    // 递归
    printf("n的阶乘为:%d\n", jiecheng(n));
    return 0;
}
