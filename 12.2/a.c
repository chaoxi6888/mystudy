#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a = 10;
    int b = 1;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    printf("%d,%d", a, b);
    return 0;
}
