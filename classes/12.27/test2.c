#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char s1[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    char s2[] = {"hello"};
    char *s3 = "hello";
    printf("%s\n", s1);
    printf("%s\n", s2);
    printf("%s\n", s3);
    printf("%ld,%lu\n", strlen(s2), sizeof(s2));
    printf("%ld,%lu\n", strlen(s3), sizeof(s3));
    s3 = "bye";
    printf("%s\n", s3);
    s3 = "hello";
    printf("%s\n", s3);
    // s2 = "bye"这是错误的; s2数组不可变(创建时指向谁就始终指向谁，内容可变)
    // s3 指针指向可以变，但指向的内容不可变(即不可修改指向的值),因为"hello"是字符串常量
    return 0;
}
