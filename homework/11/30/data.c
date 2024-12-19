#include <stdio.h>

int main(int argc, char const *argv[])
{
    int y, m, d;

    do
    {
        printf("请输入正确的(年,月):");
        scanf("%d,%d", &y, &m);
    } while ((y < 0) || (m < 1 || m > 12));

    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
    {
        d = 31;
    }
    else
    {
        if (m != 2)
        {
            d = 30;
        }
        else
        {
            if (y % 400 == 0 || y % 4 == 0 && y % 100 != 0) //  判断是否为闰年
            {
                d = 29;
            }
            else
            {
                d = 28;
            }
        }
    }
    printf("%d年%d月有%d天", y, m, d);
    return 0;
}
