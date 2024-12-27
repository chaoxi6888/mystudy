#include <stdio.h>

int main(int argc, char const *argv[])
{
    char a = '9';
    char b = '2';
    char c;
    printf("%c,%d\n", a + b, a + b);
    // 所有的‘0’-‘9’的字符与字符‘0’的偏移就是本身
    printf("%d\n", '9' - '0');
    // 字母的大小写相差32, 大写在前
    printf("%c,%c\n", 'A', 'A' + 32);
    printf("请输入一个字符c:");
    scanf("%c", &c);
    if (c >= 'a' && c <= 'z')
    {
        printf("你输入的字符是小写,");
        printf("转换后%c", c - 32);
    }
    if (c >= 'A' && c <= 'Z')
    {
        printf("你输入的字符是大写,");
        printf("转换后%c", c + 32);
    }

    return 0;
}
