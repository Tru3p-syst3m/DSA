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
	chain_node* next;
}chain_node;

void init_hash_tab_chain(int);