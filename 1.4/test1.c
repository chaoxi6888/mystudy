#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MyStruct
{
    int a;    // 占4字节，按照4字节对齐
    double c; // 占8字节，按照8字节对齐
    char b;   // 占1字节，不改变对齐
};

int main()
{
    // 使用sizeof运算符来获取结构体的大小
    printf("Size of MyStruct: %zu bytes\n", sizeof(struct MyStruct));
    return 0;
}