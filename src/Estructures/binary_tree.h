#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct tree_node
{
    int value;
    struct tree_node *left;
    struct tree_node *right;

} TREE_NODE;


typedef struct BinaryTree
{
    TREE_NODE *root;

} BINARY_TREE;


/* Crear árbol */
BINARY_TREE *create_tree(int amount);

/* Operaciones principales */
int insert_tree(BINARY_TREE *tree, int value);
int search_tree(BINARY_TREE *tree, int value);
int delete_tree(BINARY_TREE *tree, int value);

/* Recorridos */
void inorder(BINARY_TREE *tree);
void preorder(BINARY_TREE *tree);
void postorder(BINARY_TREE *tree);

/* Liberar memoria */
void free_tree(BINARY_TREE *tree);

#endif