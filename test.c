#include <stdio.h>
/**
 * 调试Makefile
*/
int main()
{
    printf("Hello World!\n");
    int a = 1, b = 2, c = 3;
    int d = (a > b) && (c++);
    printf("%d\t%d\n", c, d);
    getchar();
    return 0;
}
