#include <stdio.h>
#include <stdlib.h>
int main()
{
    // int a;     // 定义变量
    // a = 42;    // 赋值
    // a = a + 1; // 算术表达式
    // a = rand(); 调用函数rand返回值赋给a

    // 3 = a; 错误

    // int x, y, z = 9; // 只给z赋值

    int a = RAND_MAX;
    int b = RAND_MAX - 1;
    // int a = 2, double b = 3 错误
    // 交换方案一
    // int t = a;
    // a = b;
    // b = t;
    // 方案二(一般不用性不如上面)(溢出也不影响交换)
    a = a + b;
    b = a - b;
    a = a - b;
    printf("%d,%d\n", a, b);
    // double r = 9 / 2 * 2; r=8.0000000 //  9/2会自动转换成整型
    double r = 9.0 / 2 * 2; //   9.0/2是浮点型
    printf("%lf\n", r);
    return 0;
}