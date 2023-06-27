#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <hash_tab.h>

void init_hash_tab_chain(int slots)
{
	chain_node* hash_tab = malloc(sizeof(chain_node*) * slots);
	assert(hash_tab);
	for(int i = 0; i <= slots; i++)
	{
		hash_tab[i] = NULL;
	}
}