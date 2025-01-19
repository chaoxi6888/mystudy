#include <stdio.h>

int fun1(int n)
{
    int num = 1;
    for (int i = 2; i <= n; i++)
    {
        num *= i;
    }
    return num;
}

int fun2(int n)
{
    // 必须添加一个收敛条件
    if (n == 1)
        return 1;
    return (n * fun2(n - 1));
}

int main()
{
    printf("%d\n", fun1(12));
    printf("%d\n", fun2(4));
    return 0;
}