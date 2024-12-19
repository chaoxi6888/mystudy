#include <stdio.h>
#define N 8

int main()
{
    char input;
    int nums;
    int array[nums][N];
    do
    {
        printf("--------------------\n");
        printf("1.录入成绩(i)\n");
        printf("2.显示成绩(l)\n");
        printf("3.查看排行榜(r)(暂时未实现)\n");
        printf("4.退出(q)\n");
        printf("--------------------\n");

        printf("请输入操作指令：\n");
        // scanf("%c", &input);
        // %c 读取一个字符
        // i enter
        // 读取到了一个回车
        // 会输出两遍

        // 读取一个字符
        input = getchar();
        // 读取回车
        getchar();
        switch (input)
        {
        case 'i':
        {
            printf("请输入运动员的人数：");
            scanf("%d", &nums);
            for (int i = 0; i < nums; ++i)
            {
                printf("请输入第%d个运动员的成绩:", i + 1);
                for (int j = 0; j < N - 3; ++j)
                {
                    scanf("%3d", &array[i][j]);
                }
            }
            for (int i = 0; i < nums; i++)
            {
                int max = array[i][0], min = array[i][0], sum = 0;
                for (int j = 1; j < N - 3; j++)
                {
                    if (array[i][j] >= max)
                        max = array[i][j];
                    if (array[i][j] <= min)
                        min = array[i][j];
                    sum += array[i][j];
                }
                array[i][N - 3] = min;
                array[i][N - 2] = max;
                array[i][N - 1] = sum / (N - 3);
            }
            getchar();
        };
        break;
        case 'l':
        {
            printf("第一个评委打分\t第二个评委打分\t第三个评委打分\t第四个评委打分\t第五个评委打分\t最低分    \t最高分    \t平均成绩\n");
            for (int i = 0; i < nums; ++i)
            {
                for (int j = 0; j < N; ++j)
                {
                    printf("%d\t\t", array[i][j]);
                }
                printf("\n");
            }
        };
        break;
        case 'r':
        {
            // int temp[nums];
            // for (int i = 0; i < nums; i++)
            //     temp[i] = array[i][N - 1];
            // for (int i = 0; i < N; i++)
            // {
            //     for (int j = i + 1; j < N; j++)
            //         if (temp[i] >= temp[j])
            //         {
            //             int te = temp[i];
            //             temp[i] = temp[j];
            //             temp[j] = te;
            //         }
            // }
            // printf("第一个评委打分\t第二个评委打分\t第三个评委打分\t第四个评委打分\t第五个评委打分\t最低分    \t最高分    \t平均成绩\n");
            // int k = 0;
            // int i = 0;
            // while (k < nums)
            // {
            //     if (array[i][N - 1] == temp[k])
            //     {
            //         printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t    \t%d\t\t    \t%d\t\t\n", array[i][0], array[i][1], array[i][2], array[i][3], array[i][4], array[i][5], array[i][6], array[i][7]);
            //         k++;
            //     }
            //     i++;
            //     if (i = nums - 1)
            //         i = 0;
            // }
        };
        break;
        case 'q':
        case 'Q':
            break;
        }

    } while (input != 'q' && input != 'Q');

    return 0;
}