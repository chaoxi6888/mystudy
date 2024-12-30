#include <stdio.h>
#include <string.h>

int sum(char *p, size_t l)
{
    int s = 0;
    for (int i = 0; i < l - 1; i++)
    {
        if (*(p + i) >= '0' && *(p + i) <= '9')
            s += *(p + i) - '0';
    }
    return s;
}

int main(int argc, char const *argv[])
{
    printf("请输入一个字符串:");
    char s[100];
    fgets(s, sizeof(s), stdin);
    printf("字符串中的数字和为:%d", sum(s, strlen(s)));
}
