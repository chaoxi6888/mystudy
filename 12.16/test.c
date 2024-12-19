#include <stdio.h>

int main()
{
    int num_sum(int); // 如果函数定义在主函数下面则应该先声明在使用
    printf("各个位的累加和为：%d", num_sum(10086));
    return 0;
}

int num_sum(int num)
{
    int sum = 0;
    while (num > 0)
    {
        sum += num % 10;
        num = num / 10;
    }
    return sum;
}