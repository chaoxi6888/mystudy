//
// var.c
// ctrl + /
#include <stdio.h>
int main(int argc, char const *argv[])
{
    /* code */
    // 变量
    // 常量 const
    // 静态类型,类型决定了空间大小及格式
    short int a = -65536 / 2; // 2   //最大值超过一位等于最小值加一，最大值超二位等最小值加二，最小值超一位等于最大值减一,取值范围[-32768,32767)
    int b;                    // 4
    long int c;               // 8
    const int d = 12;         // 值不能修改
    // 快速复制shift + alr + 向下箭头
    // 多行操作ctrl + alt + 上下            //esc 退出
    // 同时移动alt+ 上下
    // &取地址符号
    // %p 打印 pointer 指针的值
    printf("%d, %ld, %ld, %p\n", a, sizeof(a), sizeof(short), &a);
    printf("%d, %ld, %ld, %p\n", b, sizeof(b), sizeof(int), &b);
    printf("%ld, %ld, %ld, %p\n", c, sizeof(c), sizeof(long int), &c);
    return 0;
}
