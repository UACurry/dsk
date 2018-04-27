#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define M 3

typedef struct tree *prt_tree;

struct tree
{
    int data;         //存储的数据
    prt_tree left;    //左子节点
    prt_tree right;   //右子节点
    prt_tree brother; //兄弟节点
};
prt_tree create_node(int data)
{
    prt_tree tree = malloc(sizeof(struct tree));
    memset(tree, 0, sizeof(struct tree));
    tree->data = data;
    return tree;
}

void swapNode(prt_tree a, prt_tree b)
{
    //交换数据
    int tmpData = a->data;
    a->data = b->data;
    b->data = tmpData;
    //交换节点
    prt_tree tmpPrtTree = a->brother;
    a->brother = b;
    b->brother = tmpPrtTree;
}

prt_tree insert(int data, prt_tree root)
{
    if (root == NULL)
    {
        root = create_node(data);
        return root;
    }
    //在兄弟节点进行搜索,直到data夹在两个兄弟节点之中,或者相等,或者为空
    //如果相等不进行处理,直接返回
    //如果比最小的还小,插入节点后,与第一个交换返回
    //如果是夹在兄弟中,就进入第一个的右,或者第二个左节点
    //如果等于NULL的话,证明这是叶子节点,就直接在中间插入,否则进行插入操作,回到第一行
    //如果是空就插入在最后一个兄弟节点
    //插入之后继续进行循环,得到n来判断这个节点数量有没有大于m
    prt_tree tmp = root;
    int n = 0;
    while (tmp != NULL)
    {
        n += 1;
        if (data < tmp->data)
        {
            //比最小还小的情况(也就是最小)
        }
        else if (tmp->brother == NULL)
        {
            //等于空的情况(也就是最大的情况)
        }
        else if (data > tmp->data && data < tmp->brother->data)
        {
            //夹在中间的情况
        }
        else
        {
            //相等的情况
        }
        tmp = tmp->brother;
    }

    //相等直接返回
    return root;
}

int main()
{
    prt_tree root = NULL;
    root = insert(4, root);

    root = insert(8, root);

    root = insert(5, root);

    root = insert(10, root);
    return 0;
}