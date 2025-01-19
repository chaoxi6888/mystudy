#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 定义62进制字符用于编码
const char BASE62[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

struct url // 结构体
{
    char URL[100];
    char shortURL[20];
};

unsigned long long switchs() // 随机生成id
{
    // 使用当前时间初始化种子
    srand(time(NULL));
    // 生成随机数
    int n = rand();
    return n;
}

void inverse(char *result, int l) // 翻转字符串
{
    for (int i = 0; i < l / 2; i++)
    {
        char temp = result[i];
        result[i] = result[l - i - 1];
        result[l - i - 1] = temp;
    }
}

void encode_base62(unsigned long long num, char *result) // 根据id生成短码
{
    int index = 0;
    if (num == 0)
    {
        result[index++] = BASE62[0];
    }
    else
    {
        while (num > 0)
        {
            result[index++] = BASE62[num % 62];
            num /= 62;
        }
    }
    result[index] = '\0';
    // 反转字符串
    inverse(result, strlen(result));
}

void print(struct url ur) // 输出结构体的内容
{
    printf("%s\n", ur.URL);
    printf("%s\n", ur.shortURL);
}

int main()
{
    struct url url1;
    unsigned long long id;
    strncpy(url1.URL, "8d608d0b-9a33-4831-8c8a-d2efa350c4fe", 100);
    id = switchs();
    printf("%lld\n", id);
    encode_base62(id, url1.shortURL);
    print(url1);
    return 0;
}