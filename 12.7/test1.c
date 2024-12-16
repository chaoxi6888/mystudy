#include <stdio.h>

int main()
{
    char input;
    do
    {
        printf("--------------------\n");
        printf("1.录入成绩(i)\n");
        printf("2.显示排名(l)\n");
        printf("3.编辑成绩(e)\n");
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
            printf("执行录入\n");
            break;
        case 'l':
            printf("列表显示\n");
            break;
        case 'e':
            printf("执行编辑\n");
            break;
        case 'q':
        case 'Q':
            break;
        }

    } while (input != 'q' && input != 'Q');
    return 0;
}