#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct tree tree;

struct tree {
    tree* left;
    tree* right;
    int val;
};

tree* new_tree() {
    tree* t = malloc(sizeof(tree));
    memset(t, 0, sizeof(tree));
    return t;
}

int add_tree(tree* root) {
    int val = 0;
    printf("value:");
    scanf("%d", &val);
    root->val = val;
    int flag = 0;
    while (1) {
        printf("left(1) or right(2) or upper(3) or quit(any):");
        scanf("%d", &flag);
        if (flag == 1) {
            if (root->left == NULL) {
                root->left = new_tree();
            }
            if (!add_tree(root->left)) break;
        } else if (flag == 2) {
            if (root->right == NULL) {
                root->right = new_tree();
            }
            if (!add_tree(root->right)) break;
        } else if (flag == 3) {
            return 1;
        } else {
            break;
        }
    }
    return 0;
}

void print_tree_before(tree* root) {
    if (root == NULL) {
        return;
    }
    printf("%d\t", root->val);
    print_tree_before(root->left);
    print_tree_before(root->right);
}

void print_tree_mid(tree* root) {
    if (root == NULL) {
        return;
    }
    print_tree_mid(root->left);
    printf("%d\t", root->val);
    print_tree_mid(root->right);
}

void print_tree_after(tree* root) {
    if (root == NULL) {
        return;
    }
    print_tree_after(root->left);
    print_tree_after(root->right);
    printf("%d\t", root->val);
}

int main() {
    tree* root = new_tree();
    root->left = new_tree();
    root->right = new_tree();
    root->left->left=new_tree();
    root->left->left->val=4;
    root->val = 1;
    root->left->val = 2;
    root->right->val = 3;
    // add_tree(root);
    print_tree_before(root);
    printf("\n");
    print_tree_mid(root);
    printf("\n");
    print_tree_after(root);
    printf("\n");
    system("pause");
    return 0;
}