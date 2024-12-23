#include <stdio.h>

void swap(int *a, int *b) // 改变变量要使用指针
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, char const *argv[])
{
    int a = 12;
    int b = 21;
    printf("交换前：%d,%d\n", a, b);
    swap(&a, &b); // 要传地址//如果是数组则不需要&，因为a本身就是地址
    printf("交换后：%d,%d\n", a, b);

    // int z;
    // char x;
    // double c;
    // int *q = &z;
    // char *w = &x;
    // double *e = &c;
    // printf("%lu,%lu,%lu\n", sizeof(z), sizeof(x), sizeof(c));
    // printf("%lu,%lu,%lu", sizeof(q), sizeof(w), sizeof(e));
    // return 0;
}
