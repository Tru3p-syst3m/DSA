#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <hash_tab.h>

hash_tab_chain* init_hash_tab_chain(int slots)
{
	hash_tab_chain* hash = malloc(sizeof(hash_tab_chain));
	assert(hash);
	hash->hash_tab = malloc(sizeof(chain_node*) * slots);
	assert(hash->hash_tab);
	hash->size = slots;
	for(int i = 0; i <= slots; i++)
	{
		hash->hash_tab[i] = NULL;
	}
	return hash;
}

int hash_func(int x)
{
	return x % 16;
}

void insert_hash_tab_chain(int key, int value, hash_tab_chain* hash_tab)
{
	chain_node* n = malloc(sizeof(chain_node));
	n->key = key; n->value = value;

	int hash = hash_func(key) % hash_tab->size;

	if(hash_tab->hash_tab[hash] == NULL)
	{
		hash_tab->hash_tab[hash] = n;
	}
	else
	{
		chain_node* tmp = hash_tab->hash_tab[hash];
		while(1)
		{
			if(!tmp->next)
			{
				tmp->next = n;
				break;
			}
			else
			{
				tmp = tmp->next;
			}
		}
	}
}

chain_node* hash_tab_chain_lookup(int key, hash_tab_chain* hash_tab)
{
	int hash = hash_func(key) % hash_tab->size;

	if(hash_tab->hash_tab[hash]->key == key)
	{
		return hash_tab->hash_tab[hash];
	}
	else
	{
		chain_node* tmp = hash_tab->hash_tab[hash]->next;
		while(1)
		{
			if(tmp->key == key)
			{
				return tmp;
			}
			else
			{
				tmp = tmp->next;
			}
		}
	}
}