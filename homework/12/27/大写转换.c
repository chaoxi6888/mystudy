#include <stdio.h>

void witch(char *p)
{
    for (int i = 0; *(p + i) != '\0'; i++)
    {
        if (*(p + i) == '\n')
        {
            *(p + i) = '\0';
        }
        if (*(p + i) >= 'a' && *(p + i) <= 'z')
        {
            *(p + i) = *(p + i) - 32;
        }
    }
}

int main(int argc, char const *argv[])
{
    printf("请输入一个字符串:");
    char s[100];
    fgets(s, sizeof(s), stdin);
    witch(s);
    printf("字符转换后的字符串:%s", s);
}
