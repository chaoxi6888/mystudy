#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

void count_DIR_file(char *name, int *dc, int *rc)
{
    DIR *dir;
    struct dirent *d;
    char names[4096];
    dir = opendir(name);
    if (!dir)
    {
        printf("打开文件%s失败\n", name);
        return;
    }
    while (d = readdir(dir))
    {
        if (strcmp(d->d_name, ".") == 0 || strcmp(d->d_name, "..") == 0)
        {
            continue;
        }
        if (d->d_type == 8)
        {
            (*rc)++;
        }
        else if (d->d_type == 4)
        {
            (*dc)++;
            snprintf(names, sizeof(names), "%s/%s", name, d->d_name);
            count_DIR_file(names, dc, rc);
        }
    }
    closedir(dir);
}

int main(int argc, char const *argv[])
{
    int DIR_count = 1;
    int file_count = 0;
    count_DIR_file("/home/chaoxi/桌面/linux-6.15.6", &DIR_count, &file_count);
    printf("文件夹数: %d\n文件数: %d\n", DIR_count, file_count);
    return EXIT_SUCCESS;
}
