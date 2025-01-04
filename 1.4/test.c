#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user
{
    /* data */
    char name[16];
    int age;
    char *tel;
    // 字符串既可以用字符数组又可以使用字符串指针
};

void newyear(struct user *p)
{
    strcpy(p->name, "chaoxi");
    p->age++;
    p->tel = "123456";
}

int main()
{
    struct user chaoxi = {"chaoxi", 18, "123456"};
    newyear(&chaoxi); // 要寻址
    printf("%s\n", chaoxi.name);
    printf("%d\n", chaoxi.age);
    printf("%s\n", chaoxi.tel);
    return 0;
}