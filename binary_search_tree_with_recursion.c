#include <stdio.h>
#include <stdlib.h>

struct bst_node
{
    int data;
    struct bst_node *left, *right;
};

struct bst_node *
insert(struct bst_node *node, int data)
{
    if (node == NULL)
    {
        struct bst_node *new_node =
                        (struct bst_node *)malloc(sizeof(struct bst_node));
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }

    if (data < node->data)
    {
        node->left = insert(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = insert(node->right, data);
    }

    return node;
}

void
display(struct bst_node *root)
{
    if (root != NULL)
    {
        display(root->left);
        printf("%d\n", root->data);
        display(root->right);
    }
}

int main()
{
    struct bst_node *root = NULL;
    root = insert(root, 10);
    insert(root, 11);
    insert(root, 12);
    insert(root, 13);
    insert(root, 14);
    display(root);
}
