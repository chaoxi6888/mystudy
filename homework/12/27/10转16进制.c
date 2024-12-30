#include <stdio.h>
#include <string.h>

int numswitch(int n, char s[])
{
    int a = n; // 商
    int b;     // 余数
    int i = 0;
    do
    {
        b = a % 16;
        a = a / 16;
        if (b >= 10)
        {
            s[i++] = 'A' + (b - 10);
        }
        else
        {
            s[i++] = (char)(b + '0');
        }
    } while (a != 0);
    return i;
}

int main(int argc, char const *argv[])
{
    int n;
    char s[100];
    printf("请输入一个整数:");
    scanf("%d", &n);
    for (int i = numswitch(n, s) - 1; i >= 0; i--)
    {
        printf("%c", s[i]);
    }
    return 0;
}

// #include <stdio.h>
// #include <string.h>
// #include <math.h>

// void numswitch(int n, char s[], int *index)
// {
//     int b; // 余数
//     do
//     {
//         b = n % 16; // 取余数
//         n = n / 16; // 取商
//         if (b >= 10)
//         {
//             s[(*index)++] = 'A' + (b - 10);
//         }
//         else
//         {
//             s[(*index)++] = '0' + b;
//         }
//     } while (n != 0);
// }

// void floatswitch(double f, char s[], int *index)
// {
//     while (f > 0)
//     {
//         f *= 16;
//         int part = (int)f;
//         f -= part;
//         if (part >= 10)
//         {
//             s[(*index)++] = 'A' + (part - 10);
//         }
//         else
//         {
//             s[(*index)++] = '0' + part;
//         }
//     }
// }

// int main(int argc, char const *argv[])
// {
//     double n;
//     char s[100];
//     int index = 0;

//     printf("请输入一个数:");
//     scanf("%lf", &n);

//     // 处理整数部分
//     int intPart = (int)n;
//     numswitch(intPart, s, &index);

//     // 处理小数点
//     if (n - intPart > 0)
//     {
//         s[index++] = '.';
//         // 处理小数部分
//         double decimalPart = n - intPart;
//         floatswitch(decimalPart, s, &index);
//     }

//     // 反转字符串以得到正确的顺序
//     for (int i = 0; i < index / 2; i++)
//     {
//         char temp = s[i];
//         s[i] = s[index - i - 1];
//         s[index - i - 1] = temp;
//     }

//     // 输出结果
//     printf("十六进制表示: %s\n", s);
//     return 0;
// }