#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void print_r(int *a, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

int main()
{
    getchar();
    return 0;
}