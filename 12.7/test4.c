#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    printf("请输入n:\n");
    scanf("%d", &n);
    n = (n + 1) / 2;
    int c[n][2 * n];

    for (int i = 0; i < n; i++) // 初始化
        for (int j = 0; j < 2 * n; j++)
            c[i][j] = ' ';

    for (int i = 0; i < n; i++)
    {
        int time = i + 1;
        for (int j = 0; j < time; j++)
        {
            c[i][n - i - 1 + j * 2] = '*';
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n; j++)
        {
            printf("%c", c[i][j]);
        }
        printf("\n");
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < 2 * n; j++)
        {
            printf("%c", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}
