#include <stdio.h>

void ptr(int *p, int l) // 因为函数定义的指针所以需要传入数组长度，若int a[]，则不需要传入长度
{
    for (int i; i < l; i++)
    {
        printf("%d\t", *(p + i));
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int a[] = {12, 3, 45, 7, 9, 16, 14};
    int b[] = {};
    printf("a数组内容:");
    ptr(a, (int)(sizeof(a) / sizeof(int)));
    printf("b数组内容:");
    ptr(b, (int)(sizeof(b) / sizeof(int)));
    return 0;
}
