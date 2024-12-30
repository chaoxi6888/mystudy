#include <stdio.h>
#include <string.h>

void reverse(char *p, size_t l)
{
    for (size_t i = 0; i <= (l - 2) / 2; i++)
    {
        char t;
        t = *(p + i);
        *(p + i) = *(p + l - 2 - i);
        *(p + l - 2 - i) = t;
    }
}

int main(int argc, char const *argv[])
{
    printf("请输入一个字符串:");
    char s[100];
    fgets(s, sizeof(s), stdin);
    reverse(s, strlen(s));
    printf("翻转后的字符串:%s", s);
}
