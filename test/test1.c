#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int search(char *str, char *dest)
{
    int len = strlen(dest);
    for (int j = 0; str[j] != '\0'; j++)
    {
        if (str[j] == dest[0])
        {
            int i = 1;
            while (i < len)
            {
                if (str[j + i] == dest[i])
                    i++;
                else
                    break;
            }
            if (i == len)
                return j;
        }
    }
    return -1;
}

int main()
{
    char s1[] = "I like javascript.";
    char s2[] = "java";
    printf("找到的索引为%d\n", search(s1, s2));
}