#include <stdio.h>

int main(int argc, char const *argv[])
{
    for (int i = 1; i < 128; i++)
    {
        printf("(%c)%3d\t", i, i);
        if (i % 10 == 0)
        {
            printf("\n");
        }
    }
    return 0;
}
