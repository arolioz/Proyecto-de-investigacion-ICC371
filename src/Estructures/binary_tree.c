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

    if(tree == NULL)
        return NULL;

    tree->root = NULL;


    for(int i = 1; i <= amount; i++)
    {
        insert_tree(tree, i);
    }


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