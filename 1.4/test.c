#include <stdio.h>
#include <stdlib.h>

struct user
{
    /* data */
    char name[16];
    int age;
    char *tel;
    // 字符串既可以用字符数组又可以使用字符串指针
};

int main()
{
    struct user chaoxi = {"chaoxi", 18, "123456"};
    struct user *p = &chaoxi;
    printf("%s\n", chaoxi.name);
    printf("%d\n", chaoxi.age);
    printf("%s\n", chaoxi.tel);
    printf("%s\n", p->name);
    printf("%d\n", p->age);
    printf("%s\n", p->tel);
    return 0;
}