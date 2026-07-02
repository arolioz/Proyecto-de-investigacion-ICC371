#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"


TREE_NODE *create_node(int value)
{
    TREE_NODE *newNode = malloc(sizeof(TREE_NODE));

    if(newNode == NULL)
        return NULL;

    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}


BINARY_TREE *create_tree(int amount)
{
    BINARY_TREE *tree = malloc(sizeof(BINARY_TREE));

    if (tree == NULL)
        return NULL;

    tree->root = NULL;

    create_balanced(tree, 1, amount);

    return tree;
}



TREE_NODE *insert_node(TREE_NODE *root, int value)
{
    if(root == NULL)
        return create_node(value);


    if(value < root->value)
    {
        root->left = insert_node(root->left, value);
    }
    else if(value > root->value)
    {
        root->right = insert_node(root->right, value);
    }


    return root;
}



int insert_tree(BINARY_TREE *tree, int value)
{
    if(tree == NULL)
        return 0;


    tree->root = insert_node(tree->root, value);

    return 1;
}



int search_node(TREE_NODE *root, int value)
{
    if(root == NULL)
        return 0;


    if(root->value == value)
        return 1;


    if(value < root->value)
        return search_node(root->left, value);


    return search_node(root->right, value);
}



int search_tree(BINARY_TREE *tree, int value)
{
    if(tree == NULL)
        return 0;


    return search_node(tree->root, value);
}

void inorder_node(TREE_NODE *root)
{
    if(root == NULL)
        return;


    inorder_node(root->left);

    printf("%d ", root->value);

    inorder_node(root->right);
}



void inorder(BINARY_TREE *tree)
{
    if(tree)
    {
        inorder_node(tree->root);
        printf("\n");
    }
}

TREE_NODE *min_value_node(TREE_NODE *node)
{
    TREE_NODE *current = node;

    while (current != NULL && current->left != NULL)
        current = current->left;

    return current;
}


TREE_NODE *delete_node(TREE_NODE *root, int value)
{
    if (root == NULL)
        return NULL;

    if (value < root->value)
    {
        root->left = delete_node(root->left, value);
    }
    else if (value > root->value)
    {
        root->right = delete_node(root->right, value);
    }
    else
    {
        // Caso 1: sin hijo izquierdo
        if (root->left == NULL)
        {
            TREE_NODE *temp = root->right;
            free(root);
            return temp;
        }

        // Caso 2: sin hijo derecho
        if (root->right == NULL)
        {
            TREE_NODE *temp = root->left;
            free(root);
            return temp;
        }

        // Caso 3: dos hijos
        TREE_NODE *temp = min_value_node(root->right);

        root->value = temp->value;

        root->right = delete_node(root->right, temp->value);
    }

    return root;
}

int delete_tree(BINARY_TREE *tree, int value)
{
    if (tree == NULL)
        return 0;

    if (!search_tree(tree, value))
        return 0;

    tree->root = delete_node(tree->root, value);

    return 1;
}

void create_balanced(BINARY_TREE *tree, int start, int end)
{
    if (start > end)
        return;

    int mid = (start + end) / 2;

    insert_tree(tree, mid);

    create_balanced(tree, start, mid - 1);
    create_balanced(tree, mid + 1, end);
}