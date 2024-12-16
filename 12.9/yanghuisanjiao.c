#include <stdio.h>
#define N 100

int main()
{
    int n, i, j;
    int arr[N][N];

    printf("请输入杨辉三角的行数:\n");
    scanf("%d", &n);

    // 初始化杨辉三角的第一行
    arr[0][0] = 1;

    // 生成杨辉三角
    for (i = 1; i < n; i++)
    {
        arr[i][0] = 1; // 每行的第一个数是1
        arr[i][i] = 1; // 最后一个数也是1
        for (j = 1; j < i; j++)
        {
            // 每个数是它上方和左上方两个数之和
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        }
    }

    // 打印杨辉三角
    for (i = 0; i < n; i++)
    {
        // 打印前导空格以形成三角形
        for (j = 0; j < n - i - 1; j++)
        {
            printf("  ");
        }
        // 打印每行的数字
        for (j = 0; j <= i; j++)
        {
            printf("%4d", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
