#include "bst.h"

#include <stdlib.h>

struct bst_node *create_node(int value)
{
    struct bst_node *node = malloc(sizeof(struct bst_node));
    if (!node)
        return NULL;

    node->data = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

static struct bst_node *add_rec(struct bst_node *tree, struct bst_node *node)
{
    if (!tree)
        return node;

    if (!tree->left && !tree->right)
    {
        if (node->data <= tree->data)
            tree->left = node;
        if (node->data > tree->data)
            tree->right = node;

        return tree;
    }

    if (node->data <= tree->data)
        tree->left = add_rec(tree->left, node);
    if (node->data > tree->data)
        tree->right = add_rec(tree->right, node);

    return tree;
}

struct bst_node *add_node(struct bst_node *tree, int value)
{
    struct bst_node *node = create_node(value);

    if (!tree)
    {
        tree = node;
        return node;
    }

    add_rec(tree, node);
    return tree;
}

static struct bst_node *get_max(struct bst_node *node)
{
    if (!node->right)
        return node;
    return get_max(node->right);
}

struct bst_node *delete_node(struct bst_node *tree, int value)
{
    if (!tree)
        return NULL;

    if (tree->data > value)
    {
        tree->left = delete_node(tree->left, value);
        return tree;
    }

    if (tree->data < value)
    {
        tree->right = delete_node(tree->right, value);
        return tree;
    }

    if (!tree->left && !tree->right)
    {
        free(tree);
        return NULL;
    }

    if (!tree->left)
    {
        struct bst_node *tmp = tree->right;
        free(tree);
        return tmp;
    }

    if (!tree->right)
    {
        struct bst_node *tmp = tree->left;
        free(tree);
        return tmp;
    }

    struct bst_node *max = get_max(tree->left);
    tree->data = max->data;
    tree->left = delete_node(tree->left, max->data);
    return tree;
}

const struct bst_node *find(const struct bst_node *tree, int value)
{
    if (!tree)
        return NULL;

    if (value < tree->data)
        return find(tree->left, value);
    if (value > tree->data)
        return find(tree->right, value);
    return tree;
}

void free_bst(struct bst_node *tree)
{
    if (!tree)
        return;

    free_bst(tree->left);
    free_bst(tree->right);
    free(tree);
    return;
}
