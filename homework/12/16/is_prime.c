#include <stdio.h>

// void is_prime(int n)//n以内的质数
// {
//     int count = 0;
//     for (int i = 2; i <= n; i++)
//     {
//         int flag = 1;
//         for (int j = 2; j * j <= i; j++)
//         {
//             if (i % j == 0)
//             {
//                 flag = 0;
//                 break;
//             }
//         }
//         if (flag == 1)
//         {
//             printf("%d\t", i);
//             count++;
//             if (count % 10 == 0)
//             {
//                 printf("\n");
//             }
//         }
//     }
// }

void is_prime(int n) // 前n个质数
{
    int count = 0;
    for (int i = 2; count < n; i++)
    {
        int flag = 1;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            printf("%d\t", i);
            count++;
            if (count % 10 == 0)
            {
                printf("\n");
            }
        }
    }
}

int main()
{
    int n;
    printf("请输入n的值(n>=2):");
    scanf("%d", &n);
    printf("前%d个质数:\n", n);
    is_prime(n);
    return 0;
}