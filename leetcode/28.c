#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
/**
 * https://leetcode-cn.com/problems/implement-strstr/description/
 * 实现strStr()
 */
//a
int strStr(char *haystack, char *needle)
{
    if (*needle == '\x0')
    {
        return 0;
    }
    int pos = 0;
    int sublen = strlen(needle);
    while (*haystack != '\x0')
    {
        if (*haystack == *needle)
        {
            char *sub = haystack;
            char *tmp = needle;
            int len = 0;
            while (*sub == *tmp && len < sublen)
            {
                len++;
                sub++;
                tmp++;
            }
            if (len == sublen)
            {
                return pos;
            }
        }
        haystack++;
        pos++;
    }
    return -1;
}

int main()
{
    printf("%d\n", strStr("hello", "lll"));
    getchar();
    return 0;
}