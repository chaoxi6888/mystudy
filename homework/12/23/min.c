#include <stdio.h>

int min(int *p, int size)
{
    int minvalue = *p;
    for (int i = 1; i < size; i++)
    {
        if (*(p + i) < minvalue)
            minvalue = *(p + i);
    }
    return minvalue;
}

int main(int argc, char const *argv[])
{
    int a[6] = {3, 1, 2, 8, 6, 4};
    printf("最小值为:%d", min(a, 6));
    return 0;
}
