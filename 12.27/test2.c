#include <stdio.h>

int main(int argc, char const *argv[])
{
    char s1[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    char s2[] = {"hello"};
    char *s3 = "hello";
    printf("%s\n", s1);
    printf("%s\n", s2);
    printf("%s\n", s3);
    return 0;
}
