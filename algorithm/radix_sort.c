#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../struct/u_link_list.h"
/**
 * 基数排序
 */
#define getN(number, N) (number / (int)pow(10, N - 1)) % 10
#define NODE_SIZE sizeof(struct node)
void radix_sort(int *, int);
/**
 * 初始化桶
 */
void init_buck(prt_node *buck)
{
    for (int i = 0; i < 10; i++) //初始化桶
    {
        buck[i] = malloc(NODE_SIZE);
        memset(buck[i], 0, NODE_SIZE);
    }
}
/**
 * 释放桶
 */
void free_buck(prt_node *buck)
{
    for (int i = 0; i < 10; i++)
    {
        prt_node node = buck[i];
        while (1)
        {
            prt_node tmp = node;
            if (tmp == NULL)
            {
                break;
            }
            node = node->next;
            free(tmp);
        }
    }
}

void radix_sort(int *number, int len)
{
    // int number[len] = {110, 30, 5, 46, 8, 456, 231, 5648, 99797, 156}; //随机数列表
    prt_node buck[10] = {NULL};
    init_buck(buck); //初始化桶
    prt_node tmp_buck[10] = {NULL};
    //先按照第一位入桶
    for (int i = 0; i < len; i++)
    {
        int bit = getN(number[i], 1);     //取出个位
        insert(-1, number[i], buck[bit]); //放到第bit个桶
    }
    int n = 2;
    while (1) //在桶内排序
    {
        int loop_count = 0;
        init_buck(tmp_buck);         //初始化临时桶
        for (int i = 0; i < 10; i++) //循环10个桶
        {
            prt_node tmp_node = buck[i];
            loop_count = 0;
            while ((tmp_node = tmp_node->next) != NULL) //读取这个桶的数据
            {
                int bit = getN(tmp_node->data, n);         //读取第N位
                insert(-1, tmp_node->data, tmp_buck[bit]); //放入临时桶
                loop_count += 1;                           //自增计数
                if (loop_count >= len)
                {
                    break;
                }
            }
            if (loop_count >= len)
            {
                break;
            }
        }
        if (loop_count >= len)
        {
            break;
        }
        //转移到原桶,直接交换两个变量的内存地址
        free_buck(buck);
        memcpy(buck, tmp_buck, sizeof(buck));
        n += 1; //下一位
    }
    print_list(buck[0]);
    free_buck(buck);
}

#ifndef MAIN_FUNC
int main()
{
    int number[] = {10, 56, 156, 615, 165, 1563, 15641, 5632, 1564, 165352, 165465, 1, 4894, 32, 894, 2354, 819, 15468, 1654, 89};
    radix_sort(number, 20);
    getchar();
    return 0;
}
#endif