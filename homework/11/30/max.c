#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a;
    int b;
    int c;
    int max;
    int mid;
    int min;

    printf("请分别输入(a,b,c)的值:");
    scanf("%d,%d,%d", &a, &b, &c);

    // if (a >= b)
    // {
    //     if (a >= c)
    //     {
    //         max = a;
    //         if (b > c)
    //         {
    //             mid = b;
    //             min = c;
    //         }
    //         else
    //         {
    //             mid = c;
    //             min = b;
    //         }
    //     }
    //     else
    //     {
    //         max = c;
    //         if (b > a)
    //         {
    //             mid = b;
    //             min = a;
    //         }
    //         else
    //         {
    //             mid = a;
    //             min = b;
    //         }
    //     }
    // }
    // else
    // {
    //     if (b >= c)
    //     {
    //         max = b;
    //         if (a > c)
    //         {
    //             mid = a;
    //             min = c;
    //         }
    //         else
    //         {
    //             mid = c;
    //             min = a;
    //         }
    //     }
    //     else
    //     {
    //         min = a;
    //         mid = b;
    //         max = c;
    //     }
    // }
    // printf("三个数中的最大数为:%d\n", max);
    // printf("三个数中的中间数为:%d\n", mid);
    // printf("三个数中的最小数为:%d\n", min);

    // 建议使用？
    max = a > b ? a : b;
    max = max > c ? max : c;
    min = a < b ? a : b;
    min = min < c ? min : c;
    if (a != max && a != min)
        mid = a;
    if (b != max && b != min)
        mid = b;
    if (c != max && c != min)
        mid = c;
    printf("三个数中的最大数为:%d\n", max);
    printf("三个数中的中间数为:%d\n", mid);
    printf("三个数中的最小数为:%d\n", min);
    return 0;
}