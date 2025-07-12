#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void count_line(FILE *fp, const char *s)
{
    int size = 200;
    char buf[200];
    int count = 0;
    rewind(fp); // 文件指针重置到开头
    while (fgets(buf, size, fp))
    {
        count++;
    }
    printf("文件%s一共%d行\n", s, count);
}

void count_note(FILE *fp, const char *s)
{
    int size = 200;
    char buf[200];
    int count = 0;
    int block_note = 0;
    rewind(fp);
    while (fgets(buf, size, fp))
    {
        char *ch = buf;
        while (*ch == ' ' || *ch == '\t')
            ch++;
        if (*ch == '/')
        {
            ch++;
            count++;
            if (*ch == '*')
            {
                block_note = 1;
                continue;
            }
        }
        if (block_note == 1)
        {
            count++;
            if (strstr(ch, "*/"))
                block_note = 0;
        }
    }
    printf("文件%s一共%d行注释\n", s, count);
}

void count_codeline(FILE *fp, const char *s)
{
    int size = 200;
    char buf[200];
    int count = 0;
    int block_note = 0;
    rewind(fp);
    while (fgets(buf, size, fp))
    {
        char *ch = buf;
        while (*ch == ' ' || *ch == '\t')
            ch++;
        if (*ch == '\0' || *ch == '\n')
            continue;
        if (*ch == '/')
        {
            ch++;
            if (*ch == '*')
            {
                block_note = 1;
            }
            continue;
        }
        if (block_note == 1)
        {
            if (strstr(ch, "*/"))
                block_note = 0;
            continue;
        }
        count++;
    }
    printf("文件%s一共%d行代码\n", s, count);
}

void count_emptyline(FILE *fp, const char *s)
{
    int size = 200;
    char buf[200];
    int count = 0;
    rewind(fp);
    while (fgets(buf, size, fp))
    {
        char *ch = buf;
        while (*ch == ' ' || *ch == '\t')
            ch++;
        if (*ch == '\0' || *ch == '\n')
            count++;
    }
    printf("文件%s一共%d行空行\n", s, count);
}

void cat_c(FILE *fp, const char *s)
{
    char ch;
    int count = 0;
    rewind(fp);
    while ((ch = fgetc(fp)) != EOF) // EOF是文件结束符
        count++;
    printf("文件%s有%d个字符\n", s, count);
}

void cat_w(FILE *fp, const char *s)
{
    char ch;
    int count = 0;
    int in_word = 0;
    rewind(fp);
    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch != ' ' && ch != '\t' && ch != '\n' && ch != '\r')
        {
            if (!in_word)
                in_word = 1;
        }
        else
        {
            if (in_word == 1)
            {
                count++;
                in_word = 0;
            }
        }
    }
    if (in_word == 1)
        count++;
    printf("文件%s有%d个单词\n", s, count);
}

void cat_l(FILE *fp, const char *s)
{
    count_line(fp, s);
}

int main(int argc, char const *argv[])
{
    FILE *fp;
    if (argc < 2)
    {
        printf("请在文件名后指定要打开的文件名\n");
        return EXIT_FAILURE;
    }
    fp = fopen(argv[1], "r");
    if (!fp)
    {
        printf("打开文件%s失败\n", argv[1]);
        return EXIT_FAILURE;
    }
    // 调用行统计函数
    count_line(fp, argv[1]);
    // 调用注释统计函数
    count_note(fp, argv[1]);
    // 调用代码统计函数
    count_codeline(fp, argv[1]);
    // 调用代码统计函数
    count_emptyline(fp, argv[1]);
    // 调用同cat -c 函数
    cat_c(fp, argv[1]);
    // 调用同cat -w 函数
    cat_w(fp, argv[1]);
    // 调用同cat -l 函数
    cat_l(fp, argv[1]);
    // 关闭文件
    fclose(fp);
    return EXIT_SUCCESS;
}