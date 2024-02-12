#include "binary_tree.h"

#include <stdio.h>

int size(const struct binary_tree *tree)
{
    if (!tree)
        return 0;

    return 1 + size(tree->left) + size(tree->right);
}

static int max(int a, int b)
{
    return a > b ? a : b;
}

int height(const struct binary_tree *tree)
{
    if (!tree)
        return -1;

    return 1 + max(height(tree->left), height(tree->right));
}

void dfs_print_prefix(const struct binary_tree *tree)
{
    if (!tree)
        return;

    printf("%d ", tree->data);
    dfs_print_prefix(tree->left);
    dfs_print_prefix(tree->right);
}

void dfs_print_infix(const struct binary_tree *tree)
{
    if (!tree)
        return;

    dfs_print_infix(tree->left);
    printf("%d ", tree->data);
    dfs_print_infix(tree->right);
}

void dfs_print_postfix(const struct binary_tree *tree)
{
    if (!tree)
        return;

    dfs_print_postfix(tree->left);
    dfs_print_postfix(tree->right);
    printf("%d ", tree->data);
}

static int pow2(int a)
{
    int res = 1;
    for (int i = 0; i < a; i++)
    {
        res *= 2;
    }

    return res;
}

int is_perfect(const struct binary_tree *tree)
{
    return (pow2(height(tree) + 1) - 1) == size(tree);
}

static int is_complete_rec(const struct binary_tree *tree, int size, int i)
{
    if (!tree)
        return 1;

    if (i >= size)
        return 0;

    int left = is_complete_rec(tree->left, size, 2 * i + 1);
    int right = is_complete_rec(tree->right, size, 2 * i + 2);

    return left && right;
}

int is_complete(const struct binary_tree *tree)
{
    if (!tree)
        return 1;

    if (!tree->left && tree->right)
        return 0;

    return is_complete_rec(tree, size(tree), 0);
}

int is_degenerate(const struct binary_tree *tree)
{
    if (!tree)
        return 1;

    if (tree->left && tree->right)
        return 0;

    if (tree->left)
        return is_degenerate(tree->left);
    if (tree->right)
        return is_degenerate(tree->right);

    return 1;
}

int is_full(const struct binary_tree *tree)
{
    if (!tree)
        return 1;

    if (!tree->left && !tree->right)
        return 1;
    if (tree->left && tree->right)
        return is_full(tree->left) && is_full(tree->right);

    return 0;
}

static int max_left(const struct binary_tree *tree)
{
    if (!tree->right)
        return tree->data;

    return max_left(tree->right);
}

static int min_right(const struct binary_tree *tree)
{
    if (!tree->left)
        return tree->data;

    return min_right(tree->left);
}

int is_bst(const struct binary_tree *tree)
{
    if (!tree)
        return 1;

    if (tree->left && max_left(tree->left) > tree->data)
        return 0;

    if (tree->left && min_right(tree->right) <= tree->data)
        return 0;

    return is_bst(tree->left) && is_bst(tree->right);
}
