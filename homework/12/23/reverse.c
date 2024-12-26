#include <stdio.h>

void reverse(int *p, int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        int temp = *(p + i);
        *(p + i) = *(p + size - 1 - i);
        *(p + size - 1 - i) = temp;
    }
}

int main(int argc, char const *argv[])
{
    int a[6] = {3, 1, 2, 8, 6, 4};
    reverse(a, 6);
    printf("翻转后的数组为:");
    for (int i = 0; i < 6; i++)
    {
        printf("%d", a[i]);
    }
    return 0;
}
