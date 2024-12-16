#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num;
    // 控制输入格式规范
    printf("请输入一个四位数：");
    scanf("%d", &num);
    while (num < 1000 || num > 9999)
    {
        printf("你输入的数不符合规范,请重新输入：");
        scanf("%d", &num);
    }
    int ws[4]; // 定义一个数组存储每一位的数字
    int i = 0;
    while (i != 4)
    {
        ws[i] = num % 10;
        num = num / 10;
        i++;
    }
    int sum = 0;
    int tum = 1; // 存放各个位数的乘积初始化为1
    for (i = 0; i < 4; i++)
    {
        sum += ws[i];
        tum *= ws[i];
    }
    printf("各个位数的乘积为:%d\n", tum);
    printf("各个位数累加和为:%d\n", sum);
    return 0;
}
