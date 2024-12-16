#include <stdio.h>
#include <stdlib.h>
#define x 9

int main(int argc, char const *argv[])
{
    /* code */                                            // 定义金额
    int arr[x] = {1000, 500, 200, 100, 50, 20, 10, 5, 1}; // 储存面值
    int num[x];                                           // 用于储存张数
    int m;
    int i = 0;
    printf("请输入取款金额：");
    scanf("%d", &m); // 输入金额

    while (m != 0) // 用于计算num[i]张数
    {
        num[i] = m / arr[i];
        m = m % arr[i];
        if (num[i] != 0)
            printf("%5d张%5d元\n", num[i], arr[i]); // 输出张数和面值
        i++;
    }
    // %3d表示占三个位置%03d表示不足补零
    return 0;
}
