#pragma once

typedef struct node
{
	int key;
	int value;
}node;

typedef struct chain_node
{
	int key;
	int value;
	struct chain_node* next;
}chain_node;

typedef struct hash_tab_chain
{
	chain_node** hash_tab;
	int size;
}hash_tab_chain;

hash_tab_chain* init_hash_tab_chain(int);
void insert_hash_tab_chain(int, int, hash_tab_chain*);
int hash_func(int);
chain_node* hash_tab_chain_lookup(int, hash_tab_chain*);