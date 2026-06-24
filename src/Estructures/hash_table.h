#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define TABLE_SIZE 26


typedef struct hash_node
{
    int value;
    struct hash_node *next;

} HASH_NODE;


typedef struct HashTable
{
    HASH_NODE *table[TABLE_SIZE];

} HASH_TABLE;



HASH_TABLE *create_hash_table(int amount);

int insert_hash(HASH_TABLE *hash, int value);

int search_hash(HASH_TABLE *hash, int value);

int delete_hash(HASH_TABLE *hash, int value);

void print_hash(HASH_TABLE *hash);

void free_hash(HASH_TABLE *hash);


#endif