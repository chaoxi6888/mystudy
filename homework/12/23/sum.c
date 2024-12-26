#include <stdio.h>

int sum(int *p, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += *(p + i);
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    int a[6] = {3, 1, 2, 8, 6, 4};
    printf("各个数的和为:%d", sum(a, 6));
    return 0;
}
