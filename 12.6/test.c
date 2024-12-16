#include <stdio.h>

int main()
{
    // int a[4] = {0,1,2,3};
    // for (int i = 0; i < 4; i++)
    // {
    //     a[i] = i;
    // }
    // printf("%p\n", a); // 数组本身，首地址，指针
    // printf("%d\n", a[0]);
    // printf("%d\n", a[1]);
    // printf("%d\n", a[2]);
    // printf("%d\n", a[3]);
    // printf("%d\n", a[4]); // 不要越界

    // for (int i = 9; i > 0; i--) // size_t 就是unsigned long 无符号长整型
    // {
    //     if (i == 5) // 如果是i=5则立刻跳出循环
    //         break;
    //     printf("%d\n", i);
    // }

    int a[10] = {0};
    for (int i = 0; i < 10; i++)
    {
        a[i] = (i + 1) * 10;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("a[%d]=%d\n", i, a[i]);
    }
    return 0;
}