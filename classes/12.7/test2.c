#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n;
    printf("请输入n:\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || i == n - 1)
            {
                printf("* ");
            }
            else
            {
                if (j == 0 || j == n - 1)
                    printf("* ");
                else
                    printf("  ");
            }
        }
        printf("\n");
    }
    return 0;
}
