#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user
{
    /* data */
    int age;
    char name[16];
    char *tel;

    // 字符串既可以用字符数组又可以使用字符串指针
};

void newyear(struct user *p)
{
    strcpy(p->name, "chaoxi");
    p->age++;
    p->tel = "123456";
}

void print(struct user *p)
{
    printf("%s\n", p->name);
    printf("%d\n", p->age);
    printf("%s\n", p->tel);
}

int main()
{
    struct user chaoxi = {
        18,
        "chaoxi",
        "123456",
    };
    newyear(&chaoxi); // 要寻址
    print(&chaoxi);
    printf("%ld\n", sizeof(struct user)); // 有对齐
    return 0;
}