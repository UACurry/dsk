#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * 快速排序O(NlogN)和插入排序O(N^2)
 * 根据《数据结构和算法》学习
 * 采用三数中值分割法
 * i为第一个元素，j为倒数第二个元素，v为中间，然后交换
 */
void swap(int *array, int pos, int pos2);
int *insert_sort(int *array, int len)
{
    for (int p = 1; p < len; p++)
    {
        int tmp = array[p], i;
        for (i = p; i > 0 && array[i - 1] > tmp; i--) //插入排序，将前一个一直往后面插入，直到遇到，比tmp小的情况
        {
            array[i] = array[i - 1];
        }
        array[i] = tmp;
    }
    return array;
}
int *quick_sort(int *array, int len)
{
    if (len <= 1) //小于等于1个长度，直接返回
    {
        return array;
    }
    // if (len <= 20) //如果长度小于20，选用更优的插入排序
    // {
    //     return insert_sort(array, len);
    // }
    int i = 0, j = len - 2, pos = len / 2 - 1, v;
    //对位置进行处理，最大的放在j位置上，最小的放在i位置上，中间的设置为v
    if (array[i] > array[pos])
        swap(array, i, pos);
    if (array[i] > array[j])
        swap(array, i, j);
    if (array[pos] > array[j])
        swap(array, pos, j);
    v = array[pos];
    print_r(array, len);
    if (len == 3)
    {
        swap(array, 1, 2);
        return array;
    }
    swap(array, len - 1, pos); //与最后一个交换
    while (1)                  //i向右移动，遇到比v大的停止，j向左移动，遇到比v小的停止
    {
        while (array[i] < v)
        {
            i++;
        }
        while (array[j] > v)
        {
            j--;
        }
        if (i > j)
        {
            break;
        }
        swap(array, j, i);
        print_r(array, len);
    }
    //将最后的与i交换
    swap(array, len - 1, i);
    quick_sort(array, i);           //递归左
    quick_sort(&array[i], len - i); //递归右
    return array;
}

void swap(int *array, int pos, int pos2)
{
    int tmp = array[pos];
    array[pos] = array[pos2];
    array[pos2] = tmp;
}

void print_r(int *a, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

#ifndef MAIN_FUNC
int main()
{
    int a[] = {8, 1, 4, 9, 6, 3, 5, 2, 7, 0};
    quick_sort(a, sizeof(a) / sizeof(int));
    print_r(a, 10);
    getchar();
    return 0;
}
#endif