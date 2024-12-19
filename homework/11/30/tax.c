#include <stdio.h>
int main(int argc, char const *argv[])
{
    double salay; // 每月收入
    printf("请输入每月工资:");
    scanf("%lf", &salay);
    double wx = 2000;                                          // 定义五险一金
    double yls = salay - wx - 5000;                            // 定义应纳税所得额
    double sl[7] = {0.03, 0.10, 0.20, 0.25, 0.30, 0.35, 0.45}; // 定义税率数组
    double ssk[7] = {0, 210, 1410, 1660, 4410, 7160, 15160};   // 定义速算扣除数
    double dw_value[5] = {3000, 12000, 25000, 55000, 80000};   // 定义挡位值
    double yns = 0;                                            // 定义应纳税额
    double sh_salay = 0;                                       // 定义税后收入

    int level = 6;
    for (int i = 0; i < 5; i++)
    {
        if (yls < dw_value[i])
        {
            level = i;
            break;
        }
    }

    yns = yls * sl[level] - ssk[level];
    sh_salay = salay - wx - yns;
    printf("应纳税:%.2lf\n", yns);
    printf("税后收入:%.2lf\n", sh_salay);
    return 0;
}
