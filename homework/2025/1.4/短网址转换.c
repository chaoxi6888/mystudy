#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 定义62进制字符用于编码
const char BASE62[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

struct url // 结构体
{
    unsigned int id;
    char URL[100];     // 长链
    char shortURL[20]; // 短链
};

unsigned int generate_random_billion()
{
    // 组合多个 rand() 调用来生成更大的随机数
    unsigned int random_value = 0;
    random_value = (rand() << 15) | rand(); // 将两个 rand() 的结果组合
    return random_value % 1000000000;       // 限制在0到999,999,999之间
}

void create(struct url urls[], int l) // 随机生成不重复的id
{
    srand((unsigned)time(NULL)); // 设置随机数种子

    for (int i = 0; i < l;)
    {
        int flag = 1;
        unsigned int temp = generate_random_billion(); // 使用改进的随机数生成方法

        // 检验是否有重复的
        for (int j = 0; j < i; j++)
        { // 只检查已生成的ID
            if (temp == urls[j].id)
            {
                flag = 0;
                break; // 如果发现重复，立即跳出循环
            }
        }

        if (flag)
        {
            urls[i].id = temp;
            i++; // 只有在生成了不重复的ID时才移动到下一个元素
        }
    }
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

void print(struct url urls[], int l) // 输出结构体的内容
{
    printf("序号\tid\t\t长链\t\t\t\t\t短链\n");
    for (int i = 0; i < l; i++)
    {
        printf("%d\t%u\t%.99s\t%.19s\n", i + 1, urls[i].id, urls[i].URL, urls[i].shortURL);
    }
}

void encode(struct url urls[], int l) // 将每一个长链进行编码
{
    for (int i = 0; i < l; i++)
    {
        encode_base62(urls[i].id, urls[i].shortURL);
    }
}

int main()
{
    struct url urls[2];
    int len = 2;
    strncpy(urls[0].URL, "8d608d0b-9a33-4831-8c8a-d2efa350c4fe", sizeof(urls[0].URL) - 1);
    strncpy(urls[1].URL, "22cad6f4-69cb-4a32-af1e-936360d29675", sizeof(urls[1].URL) - 1);
    urls[0].URL[sizeof(urls[0].URL) - 1] = '\0'; // 确保以空字符结尾
    urls[1].URL[sizeof(urls[1].URL) - 1] = '\0'; // 确保以空字符结尾
    create(urls, len);
    encode(urls, len);
    print(urls, len);
    return 0;
}