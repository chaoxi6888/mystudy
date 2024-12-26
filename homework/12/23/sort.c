#include <stdio.h>

void soft(int *p, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i; j + 1 < size - i; j++)
        {
            if (*(p + j) > *(p + j + 1))
            {
                int temp = *(p + j);
                *(p + j) = *(p + j + 1);
                *(p + j + 1) = temp;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int a[6] = {3, 1, 2, 8, 6, 4};
    soft(a, 6);
    printf("排序后的数组为:");
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
