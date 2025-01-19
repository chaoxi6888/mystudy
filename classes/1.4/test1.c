#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MyStruct
{
    int a;    // 占4字节，按照4字节对齐
    double c; // 占8字节，按照8字节对齐
    char b;   // 占1字节，不改变对齐
};

void print(struct MyStruct *p)
{
    printf("%d\n", p->a);
    printf("%f\n", p->c);
    printf("%d\n", p->b);
}

int main()
{
    // 使用sizeof运算符来获取结构体的大小
    struct MyStruct u1 = {4, 8, 6};
    struct MyStruct u2 = u1; // 可以使用另一个对象对对象初始化
    printf("Size of MyStruct: %zu bytes\n", sizeof(struct MyStruct));
    print(&u1);
    print(&u2);
    return 0;
}