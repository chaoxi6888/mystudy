#include <stdio.h>

int max(int a[], int size)
{
    int maxvalue = a[0];
    for (int i = 1; i < size; i++)
    {
        if (a[i] > maxvalue)
            maxvalue = a[i];
    }
    return maxvalue;
}

int main(int argc, char const *argv[])
{
    int a[6] = {3, 1, 2, 8, 6, 4};
    printf("最大值为:%d", max(a, 6));
    return 0;
}
