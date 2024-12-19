#include <stdio.h>

void is_prime(int n)
{
    for (int i = 2; i <= n; i++)
    {
        int flag = 1;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                flag = 0;
            }
        }
        if (flag == 1)
            printf("%d ", i);
    }
}

int main()
{
    int n;
    printf("请输入n的值(n>=2):");
    scanf("%d", &n);
    printf("%d以内的质数有:", n);
    is_prime(n);
    return 0;
}