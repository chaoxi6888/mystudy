#include <stdio.h>

int gcd(int a, int b)
{
    while (b % a != 0)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main()
{
    int n1;
    int n2;
    printf("请输入n1和n2(n1<<n2)分别为：");
    scanf("%d%d", &n1, &n2);
    printf("最大公约数为：%d", gcd(n1, n2));
    return 0;
}
