#include <stdio.h>

int day_(int y, int m, int d)
{
    int date = 0;
    int date_add[12] = {31, 0, 30, 31, 30, 31, 31, 31, 30, 31, 30, 31};
    if (y % 400 == 0 || y % 4 == 0 && y % 100 != 0) //  判断是否为闰年
    {
        date_add[1] = 29;
    }
    else
    {
        date_add[1] = 28;
    }
    for (int i = 0; i < m - 1; i++)
    {
        date += date_add[i];
    }
    date += d;
    return date;
}

int main(int argc, char const *argv[])
{
    int year;
    int month;
    int day;
    printf("请输入年月日:");
    scanf("%d%d%d", &year, &month, &day);
    printf("%d年%d月%d日是第%d天", year, month, day, day_(year, month, day));
    return 0;
}
