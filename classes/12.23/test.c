#include <stdio.h>

int main()
{
    int a[5] = {100, 200, 300, 400, 500};
    int *p = a;
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t%d\t%p\n", i, *(p + i) + 1, p + i);
    }
    printf("新增了一行");
    // for (int i = 0; i < 5; i++)
    // {
    //     printf("%d\t%d\t%p\n", i, *p, p);
    //     p++; // 会改变指针的指向
    // }
    // 使用指针尽量不要修改指针的指向

    // printf("%d\t%p\t\n", *(p + 1), p + 1);
    return 0;
}